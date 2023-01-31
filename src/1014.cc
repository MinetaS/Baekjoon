#include <cstdio>
#include <deque>
#include <limits>
#include <vector>

class Graph {
public:
    using NodeID = int;
};

class BipartiteGraph : public Graph {
public:
    BipartiteGraph() = delete;
    BipartiteGraph(size_t size_left, size_t size_right)
            : size_left_(size_left), size_right_(size_right), adjacent_nodes_(size_left) {}

    inline void add_edge(NodeID left, NodeID right) {
        adjacent_nodes_[left].push_back(right);
    }

private:
    friend class HopcroftKarpMatching;

    size_t size_left_;
    size_t size_right_;
    std::vector<std::vector<NodeID>> adjacent_nodes_;
};

class Matching {
public:
    using NodeID = Graph::NodeID;
};

// John E. Hopcroft and Richard M. Karp.
// An n^5/2 algorithm for maximum matchings in bipartite graphs.
// SIAM Journal on Computing, 2(4):225-231, 1973.
class HopcroftKarpMatching : public Matching {
public:
    HopcroftKarpMatching() = delete;
    HopcroftKarpMatching(BipartiteGraph &graph)
            : graph_(graph),
              level_(graph.size_left_, -1),
              match_left_(graph.size_left_, -1), match_right_(graph.size_right_, -1) {}

    int match();

private:
    void update_level();
    bool add_augment_path(NodeID node);

    BipartiteGraph &graph_;

    std::vector<int> level_;
    std::vector<NodeID> match_left_;
    std::vector<NodeID> match_right_;
};

int HopcroftKarpMatching::match() {
    int match = 0;

    while (true) {
        int augment = 0;

        update_level();

        for (size_t i = 0; i < graph_.size_left_; ++i) {
            if (match_left_[i] == -1 && add_augment_path(i)) {
                ++augment;
            }
        }

        if (augment == 0)
            break;

        match += augment;
    }

    return match;
}

void HopcroftKarpMatching::update_level() {
    std::deque<NodeID> q;

    for (size_t i = 0; i < graph_.size_left_; ++i) {
        if (match_left_[i] == -1) {
            level_[i] = 0;
            q.push_back(i);
        }
        else {
            level_[i] = std::numeric_limits<int>::max();
        }
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop_front();

        for (int next : graph_.adjacent_nodes_[now]) {
            int update = match_right_[next];

            if (update != -1 && level_[update] == std::numeric_limits<int>::max()) {
                level_[update] = level_[now] + 1;
                q.push_back(update);
            }
        }
    }
}

bool HopcroftKarpMatching::add_augment_path(NodeID node) {
    for (int next : graph_.adjacent_nodes_[node]) {
        int update = match_right_[next];

        if (update == -1 || (level_[update] == level_[node] + 1 && add_augment_path(update))) {
            match_left_[node] = next;
            match_right_[next] = node;
            return true;
        }
    }

    return false;
}

int main() {
    int N;

    scanf("%d", &N);

    while (N-- > 0) {
        constexpr int dx[6] = {-1, -1, -1, 1, 1, 1};
        constexpr int dy[6] = {1, 0, -1, 1, 0, -1};

        char map[10][11];
        int height, width;
        int seat = 0;

        scanf("%d %d", &height, &width);

        BipartiteGraph graph(height * width, height * width);

        for (int i = 0; i < height; ++i) {
            scanf("%s", map[i]);

            for (int j = 0; j < width; ++j) {
                if (map[i][j] == '.') {
                    ++seat;
                }
            }
        }

        for (int x = 0; x < width; x += 2) {
            for (int y = 0; y < height; ++y) {
                if (map[y][x] == 'x')
                    continue;

                for (int k = 0; k < 6; ++k) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || nx > width - 1 || ny < 0 || ny > height - 1 || map[ny][nx] == 'x')
                        continue;

                    graph.add_edge(width * y + x, width * ny + nx);
                }
            }
        }

        HopcroftKarpMatching matching(graph);

        printf("%d\n", seat - matching.match());
    }

    return 0;
}
