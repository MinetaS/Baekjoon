#include <algorithm>
#include <cstdio>
#include <vector>

namespace {

class Graph {
public:
    using NodeID = int;
};

using NodeID = Graph::NodeID;

class BipartiteGraph : public Graph {
public:
    BipartiteGraph() = delete;
    BipartiteGraph(size_t size_left, size_t size_right)
            : size_left_(size_left), size_right_(size_right), adjacent_nodes_(size_left) {}

    inline void add_edge(NodeID left, NodeID right) {
        adjacent_nodes_[left].push_back(right);
    }

private:
    friend class Matching$1017;

    size_t size_left_;
    size_t size_right_;
    std::vector<std::vector<NodeID>> adjacent_nodes_;
};

class Matching {};

class Matching$1017 : public Matching {
public:
    Matching$1017(BipartiteGraph &graph)
            : graph_(graph), match_(graph.size_left_) {}

    std::vector<NodeID> find_match();

private:
    bool search(NodeID node);

    BipartiteGraph &graph_;

    std::vector<NodeID> match_;
    unsigned int visited_;
};

std::vector<NodeID> Matching$1017::find_match() {
    std::vector<NodeID> result;

    for (NodeID first : graph_.adjacent_nodes_[0]) {
        size_t matches = 1;

        std::fill(match_.begin(), match_.end(), -1);
        match_[first] = 0;

        for (size_t j = 1; j < graph_.size_left_; ++j) {
            visited_ = 1;

            if (search(j)) {
                ++matches;
            }
        }

        if (matches == graph_.size_left_) {
            result.push_back(first);
        }
    }

    return result;
}

bool Matching$1017::search(NodeID node) {
    if ((visited_ & 1u << node) != 0)
        return false;

    visited_ |= 1u << node;

    for (NodeID v : graph_.adjacent_nodes_[node]) {
        if (match_[v] == -1 || search(match_[v])) {
            match_[v] = node;
            return true;
        }
    }

    return false;
}

bool is_prime(unsigned int n) {
    if (n <= 3)
        return n >= 2;

    if (!(n & 1))
        return false;

    for (unsigned int t = 3; t * t <= n; t += 2) {
        if (n % t == 0)
            return false;
    }

    return true;
}

} // namespace

int main() {
    int n, first, t;

    // set[0]: even, set[1]: odd
    std::vector<int> set[2];

    scanf("%d", &n);
    scanf("%d", &first);

    set[first & 1].push_back(first);

    for (int i = 1; i < n; ++i) {
        scanf("%d", &t);
        set[t & 1].push_back(t);
    }

    if (set[0].size() != set[1].size()) {
        puts("-1");
        return 0;
    }

    // set[0]: w/ first, set[1]: w/o first
    if (first & 1) {
        std::swap(set[0], set[1]);
    }

    const size_t size = n / 2;
    BipartiteGraph graph(size, size);

    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            if (is_prime(set[0][i] + set[1][j])) {
                graph.add_edge(Graph::NodeID(i), Graph::NodeID(j));
            }
        }
    }

    Matching$1017 match(graph);
    std::vector<NodeID> result = match.find_match();

    if (result.size() == 0) {
        puts("-1");
        return 0;
    }

    for (size_t i = 0; i < result.size(); ++i) {
        // NodeID = int, so this is a trivial conversion.
        result[i] = set[1][result[i]];
    }

    std::sort(result.begin(), result.end());

    for (size_t i = 0; i < result.size() - 1; ++i) {
        printf("%d ", result[i]);
    }

    printf("%d\n", *(result.end() - 1));

    return 0;
}
