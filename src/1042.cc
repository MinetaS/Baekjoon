#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <limits>
#include <ranges>
#include <string>
#include <unordered_map>
#include <vector>

constexpr std::size_t kInfinity = std::numeric_limits<std::size_t>::max();
constexpr std::uint64_t kMod = 1000000007;

using Nucleotide = std::int8_t;
using Codon = std::array<Nucleotide, 3>;
using AminoAcid = std::uint32_t;

constexpr Nucleotide resolve_nucleotide_char(const char c) {
    switch (c) {
    case 'A':
        return 0;
    case 'C':
        return 1;
    case 'G':
        return 2;
    case 'T':
        return 3;
    }
    __builtin_unreachable();
}

template<>
struct std::hash<Codon> {
    std::size_t operator()(const Codon& codon) const {
        return (static_cast<std::uint32_t>(codon[0]) << 16) |
               (static_cast<std::uint32_t>(codon[1]) << 8) |
               static_cast<std::uint32_t>(codon[2]);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);

    std::string dna_string;
    std::size_t table_size;
    std::unordered_map<std::string, AminoAcid> amino_acid_map;
    std::unordered_map<Codon, AminoAcid> codon_to_amino_acid;

    std::cin >> dna_string;
    std::cin >> table_size;

    const std::size_t N = dna_string.size();

    auto view = dna_string | std::views::transform(resolve_nucleotide_char);
    std::vector<Nucleotide> dna(view.begin(), view.end());

    // Assign an ID to each unique amino acid.
    for (std::size_t _ : std::views::iota(0u, table_size)) {
        std::string codon_string, amino_acid;
        std::uint32_t amino_acid_id;

        std::cin >> codon_string >> amino_acid;

        if (amino_acid_map.find(amino_acid) == amino_acid_map.end()) {
            amino_acid_map[amino_acid] = amino_acid_id = amino_acid_map.size();
        }
        else {
            amino_acid_id = amino_acid_map[amino_acid];
        }

        codon_to_amino_acid.emplace(
            Codon{resolve_nucleotide_char(codon_string[0]),
                  resolve_nucleotide_char(codon_string[1]),
                  resolve_nucleotide_char(codon_string[2])},
            amino_acid_id);
    }

    const std::size_t L = amino_acid_map.size();

    // Construct an array of codon groups, where each group contains codons
    // that map to the same amino acid.
    std::vector<std::vector<Codon>> codon_groups(L);

    for (const auto& [codon, amino_acid_id] : codon_to_amino_acid) {
        codon_groups[amino_acid_id].push_back(codon);
    }

    // Build an array which stores the index of the next nucleotide.
    std::vector<std::array<std::size_t, 4>> next_nucleotide_index(N);
    std::array<std::size_t, 4> last_nucleotide_index;

    std::ranges::fill(next_nucleotide_index | std::views::join, kInfinity);
    std::ranges::fill(last_nucleotide_index, kInfinity);

    for (std::size_t i : std::views::iota(0u, N) | std::views::reverse) {
        last_nucleotide_index[dna[i]] = i;
        next_nucleotide_index[i] = last_nucleotide_index;
    }

    // Build a 2D array which stores the ending index of the shortest sequence
    // of a codon that can be formed starting from each nucleotide.
    std::vector<std::vector<std::size_t>> amino_acid_matched(
        N, std::vector<std::size_t>(L, kInfinity));

    for (std::size_t amino_acid_id : std::views::iota(0u, L)) {
        for (const Codon& codon : codon_groups[amino_acid_id]) {
            for (std::size_t i : std::views::iota(0u, N)) {
                std::size_t j = i;
                bool ok = true;

                for (Nucleotide nucleotide : codon) {
                    if (j == N) {
                        ok = false;
                        break;
                    }

                    std::size_t j_next = next_nucleotide_index[j][nucleotide];

                    if (j_next == kInfinity) {
                        ok = false;
                        break;
                    }

                    j = j_next + 1;
                }

                if (ok && j < amino_acid_matched[i][amino_acid_id]) {
                    amino_acid_matched[i][amino_acid_id] = j;
                }
            }
        }
    }

    // Calculate all possible sequences.
    std::vector<std::uint64_t> sum(N + 1, 0);

    for (std::size_t i : std::views::iota(0u, N) | std::views::reverse) {
        std::uint64_t count = 0;

        for (std::size_t amino_acid_id : std::views::iota(0u, L)) {
            std::size_t j = amino_acid_matched[i][amino_acid_id];

            if (j != kInfinity) {
                count = (count + sum[j] + 1) % kMod;
            }
        }

        sum[i] = count;
    }

    std::cout << sum[0];

    return 0;
}
