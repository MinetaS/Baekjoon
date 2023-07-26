#include <cstdint>
#include <cstdio>
#include <functional>
#include <limits>

int main() {
    constexpr int Jimin = 0, Hansu = 1;
    constexpr int8_t INF = std::numeric_limits<int8_t>::max();

    int n, m;
    int rounds[2] = { 0 };
    int8_t capacity[2][50] = { 0 };
    int8_t flow[50][50] = { 0 };
    int8_t level[2][50], level_sink;

    scanf("%d %d", &n, &m);

    // Jimin's team, flow from Source.
    for (int i = 0, t; i < n; ++i) {
        scanf("%d", &t);
        capacity[Jimin][i] = t;
        rounds[Jimin] += t;
    }

    // Hansu's team, flow to Sink.
    for (int i = 0, t; i < m; ++i) {
        scanf("%d", &t);
        capacity[Hansu][i] = t;
        rounds[Hansu] += t;
    }

    if (rounds[Jimin] != rounds[Hansu]) {
        puts("-1");
        return 0;
    }

    static auto construct_level_graph = [&]() -> int8_t {
        int connected = 0;

        std::fill_n(reinterpret_cast<int8_t *>(level), sizeof(level), INF);

        // Initialize level = 1.
        for (int i = 0; i < n; ++i) {
            if (capacity[Jimin][i] > 0) {
                level[Jimin][i] = connected = 1;
            }
        }

        if (connected != 1)
            return INF;

        for (int l = 2; l < INF; ++l) {
            if (l % 2 == 0) {
                for (int i = 0; i < m; ++i) {
                    if (level[Hansu][i] != INF)
                        continue;

                    for (int j = 0; j < n; ++j) {
                        if (level[Jimin][j] != l - 1)
                            continue;

                        if (flow[j][i] == 0) {
                            level[Hansu][i] = connected = l;
                            break;
                        }
                    }
                }
            }
            else {
                for (int i = 0; i < m; ++i) {
                    if (level[Hansu][i] != l - 1)
                        continue;

                    if (capacity[Hansu][i] > 0) {
                        connected = l;
                        break;
                    }
                }

                if (connected == l)
                    return l;

                for (int i = 0; i < n; ++i) {
                    if (level[Jimin][i] != INF)
                        continue;

                    for (int j = 0; j < m; ++j) {
                        if (level[Hansu][j] != l - 1)
                            continue;

                        // Reverse flow
                        if (flow[i][j] == 1) {
                            level[Jimin][i] = connected = l;
                            break;
                        }
                    }
                }
            }

            if (connected != l)
                return INF;
        }

        return INF;
    };

    static auto send_flow = [&](const std::pair<int, int> edge = std::make_pair(-1, -1)) {
        static std::function<int(int, int)> traverse = [&](int type, int node) {
            int current_level = level[type][node];

            if (type == Jimin) {
                for (int i = 0; i < m; ++i) {
                    if (level[Hansu][i] != current_level + 1)
                        continue;
                    if (flow[node][i] != 0)
                        continue;
                    if (std::make_pair(node, i) <= edge) {
                        continue;}

                    if (traverse(Hansu, i) > 0) {
                        flow[node][i] = 1;
                        return true;
                    }
                }
            }
            else {
                // Prioritize flow to sink.
                if (level_sink == current_level + 1 && capacity[Hansu][node] > 0) {
                    capacity[Hansu][node] -= 1;
                    return true;
                }

                for (int i = 0; i < n; ++i) {
                    if (level[Jimin][i] != current_level + 1)
                        continue;
                    if (flow[i][node] != 1)
                        continue;

                    if (traverse(Jimin, i) > 0) {
                        flow[i][node] = 0;
                        return true;
                    }
                }
            }

            return false;
        };

        int total_flow = 0;

        for (int i = 0; i < n; ++i) {
            if (level[Jimin][i] != 1)
                continue;

            while (capacity[Jimin][i] > 0 && traverse(Jimin, i)) {
                capacity[Jimin][i] -= 1;
                total_flow += 1;
            }
        }

        return total_flow;
    };

    int max_flow = 0;

    // Find maximum flow using Dinic's algorithm.
    while ((level_sink = construct_level_graph()) != INF) {
        int t = send_flow();

        if (t == 0)
            break;

        max_flow += t;
    }

    if (max_flow != rounds[Jimin]) {
        puts("-1");
        return 0;
    }

    static auto try_swap_flow = [&](int from, int to) {
        const std::pair<int, int> c = std::make_pair(from, to);

        // It is necessary to store the path to swap flow paths easily.
        int previous[2][50];
        bool updated;

        std::fill_n(reinterpret_cast<int *>(previous), sizeof(previous) / sizeof(int), -1);

        previous[Jimin][from] = INF;  // source

        do {
            updated = false;

            for (int i = 0; i < m; ++i) {
                if (previous[Hansu][i] != -1)
                    continue;

                for (int j = 0; j < n; ++j) {
                    if (previous[Jimin][j] != -1 && flow[j][i] == 0 && std::make_pair(j, i) > c) {
                        previous[Hansu][i] = j;
                        updated = true;
                    }
                }
            }

            for (int i = 0; i < n; ++i) {
                if (previous[Jimin][i] != -1)
                    continue;

                for (int j = 0; j < m; ++j) {
                    if (previous[Hansu][j] != -1 && flow[i][j] == 1) {
                        previous[Jimin][i] = j;
                        updated = true;
                    }
                }
            }
        } while (updated);

        if (previous[Hansu][to] == -1)
            return;

        flow[from][to] = 0;

        int type = Hansu;
        int node = to;
        int prev;

        do {
            if (type == Jimin) {
                flow[node][(prev = previous[Jimin][node])] = 0;
            }
            else {
                flow[(prev = previous[Hansu][node])][node] = 1;
            }

            type = !type;
            node = prev;
        } while (!(type == Jimin && node == from));
    };

    // Find a match table that comes first in lexicographical order.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (flow[i][j] == 1) {
                try_swap_flow(i, j);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d", flow[i][j]);
        }

        printf("\n");
    }

    return 0;
}
