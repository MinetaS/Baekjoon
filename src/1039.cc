#include <algorithm>
#include <cstdio>
#include <deque>
#include <string>
#include <vector>

namespace {

struct State : public std::tuple<std::string, size_t, int> {
    using std::tuple<std::string, size_t, int>::tuple;

    inline constexpr std::string &state() {
        return std::get<0>(*this);
    }

    inline constexpr size_t &i() {
        return std::get<1>(*this);
    }

    inline constexpr int &ops() {
        return std::get<2>(*this);
    }
};

} // namespace

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    const std::string str = std::to_string(n);

    if (str.size() == 1 || (str.size() == 2 && str[1] == 48)) {
        printf("-1");
        return 0;
    }

    std::deque<State> pool;
    std::vector<int> candidates;
    pool.emplace_back(str, 0, 0);

    while (!pool.empty()) {
        State st(std::move(pool.front()));
        pool.pop_front();

        std::string &s = st.state();

        if (st.i() == str.size() || st.ops() == k) {
            int remaining = k - st.ops();

            if (remaining > 0) {
                bool dup = false;

                for (auto it = s.cbegin(); it != s.cend() - 1; ++it) {
                    if (*it == *(it + 1)) {
                        dup = true;
                        break;
                    }
                }

                if (!dup && (remaining % 2 == 1)) {
                    std::iter_swap(s.end() - 2, s.end() - 1);
                }
            }

            candidates.push_back(std::stoi(s));
            continue;
        }

        auto it = std::max_element(s.begin() + st.i(), s.end());
        const char max = *it;

        if (max <= s[st.i()]) {
            st.i() += 1;
            pool.emplace_back(std::move(st));
            continue;
        }

        for ( ; it != s.end(); it = std::find(it + 1, s.end(), max)) {
            std::string next(s);
            std::swap(next[st.i()], next[it - s.begin()]);
            pool.emplace_back(std::move(next), st.i() + 1, st.ops() + 1);
        }
    }

    std::sort(candidates.begin(), candidates.end(), std::greater<int>());

    printf("%d", *candidates.begin());

    return 0;
}
