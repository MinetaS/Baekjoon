#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <vector>

namespace {

struct Board {
    using Piece = std::pair<int, int>;

    Board() : positions_({}) {}

    void add(int x, int y) {
        pieces_.emplace_back(x, y);
        positions_[y][x] = true;
    }

    bool move(Piece &piece, int dx, int dy) {
        if (dx == 0 && dy == 0)
            return true;

        int x = piece.first + dx;
        int y = piece.second + dy;

        if (x < 0 || x > 4 || y < 0 || y > 4 || positions_[y][x])
            return false;

        positions_[piece.second][piece.first] = false;
        positions_[y][x] = true;
        piece.first = x;
        piece.second = y;

        return true;
    }

    bool check_adjacency() const {
        bool visited[5][5] = { false };

        static std::function<int(int, int)> search = [&](int x, int y) -> int {
            if (x < 0 || x > 4 || y < 0 || y > 4 || !positions_[y][x] || visited[y][x])
                return 0;

            visited[y][x] = true;

            return 1 + search(x - 1, y) + search(x + 1, y) +
                       search(x, y - 1) + search(x, y + 1);
        };

        const Piece &p = pieces_[0];

        return search(p.first, p.second) == int(pieces_.size());
    }

    inline constexpr std::vector<Piece> &pieces() {
        return pieces_;
    }

private:
    std::vector<Piece> pieces_;
    bool positions_[5][5];
};

} // namespace

int main() {
    Board board;

    for (int i = 0; i < 5; ++i) {
        char line[6];

        scanf("%s", line);

        for (int j = 0; j < 5; ++j) {
            if (line[j] == '*') {
                board.add(j, i);
            }
        }
    }

    static std::function<bool(int, int)> simulate = [&](int remaining, int index) {
        if (index == int(board.pieces().size()))
            return remaining == 0 && board.check_adjacency();

        if (remaining > 3 + 3 * (int(board.pieces().size()) - index))
            return false;

        Board::Piece &p = board.pieces()[index];
        int x_lb = std::max(-p.first, -remaining);
        int x_ub = std::min(4 - p.first, remaining);

        for (int dx = x_lb; dx <= x_ub; ++dx) {
            int t = remaining - std::abs(dx);
            int y_lb = std::max(-p.second, -t);
            int y_ub = std::min(4 - p.second, t);

            for (int dy = y_lb; dy <= y_ub; ++dy) {
                Board::Piece &p = board.pieces()[index];

                if (!board.move(p, dx, dy))
                    continue;

                if (simulate(remaining - std::abs(dx) - std::abs(dy), index + 1))
                    return true;

                board.move(p, -dx, -dy);
            }
        }

        return false;
    };

    for (int i = 0; i <= 12; ++i) {
        if (simulate(i, 0)) {
            printf("%d", i);
            break;
        }
    }

    return 0;
}
