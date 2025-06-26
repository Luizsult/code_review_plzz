#include "artifacts.h"
#include <fstream>
#include <algorithm>
#include <limits>
#include <string>

namespace {

void validate_input_data(int N, int Z, const std::vector<int>& weights, 
                        const std::vector<int>& taxes) {
    if (N <= 0) {
        throw std::invalid_argument("Number of artifacts must be positive");
    }
    if (Z <= 0) {
        throw std::invalid_argument("Z must be positive");
    }
    if (weights.size() != static_cast<size_t>(N) || taxes.size() != static_cast<size_t>(N)) {
        throw std::invalid_argument("Input data size mismatch");
    }
    if (*std::min_element(weights.begin(), weights.end()) <= 0) {
        throw std::invalid_argument("All weights must be positive");
    }
    if (*std::min_element(taxes.begin(), taxes.end()) < 0) {
        throw std::invalid_argument("Taxes cannot be negative");
    }
}

}  // namespace

ArtifactSelectionResult select_artifacts(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    int N, Z;
    file >> N >> Z;

    std::vector<int> weights(N);
    std::vector<int> taxes(N);

    for (int i = 0; i < N; ++i) {
        if (!(file >> weights[i])) {
            throw std::runtime_error("Failed to read weight data");
        }
    }
    for (int i = 0; i < N; ++i) {
        if (!(file >> taxes[i])) {
            throw std::runtime_error("Failed to read tax data");
        }
    }

    validate_input_data(N, Z, weights, taxes);

    const int max_weight = std::accumulate(weights.begin(), weights.end(), 0);
    std::vector<int> min_tax(max_weight + 1, std::numeric_limits<int>::max());
    min_tax[0] = 0;

    for (int i = 0; i < N; ++i) {
        for (int w = max_weight; w >= weights[i]; --w) {
            if (min_tax[w - weights[i]] != std::numeric_limits<int>::max()) {
                min_tax[w] = std::min(min_tax[w], min_tax[w - weights[i]] + taxes[i]);
            }
        }
    }

    int min_tax_value = std::numeric_limits<int>::max();
    int total_weight = 0;
    for (int w = Z + 1; w <= max_weight; ++w) {
        if (min_tax[w] < min_tax_value) {
            min_tax_value = min_tax[w];
            total_weight = w;
        }
    }

    if (min_tax_value == std::numeric_limits<int>::max()) {
        throw std::runtime_error("No solution found");
    }

    std::vector<int> selected_indices;
    for (int i = N - 1, w = total_weight; i >= 0; --i) {
        if (w >= weights[i] && min_tax[w] == min_tax[w - weights[i]] + taxes[i]) {
            selected_indices.push_back(i + 1);
            w -= weights[i];
        }
    }

    return {selected_indices, total_weight, min_tax_value};
}
