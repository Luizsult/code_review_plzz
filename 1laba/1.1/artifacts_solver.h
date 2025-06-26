#ifndef ARTIFACTS_SOLVER_H
#define ARTIFACTS_SOLVER_H

#include <vector>
#include <string>
#include <stdexcept>

class ArtifactsSolver {
public:
    struct Solution {
        std::vector<int> selected_artifacts;
        int total_weight;
        int total_tax;
    };

    // FIX ME: было nalogi(Z)
    ArtifactsSolver(const std::vector<int>& weights, const std::vector<int>& taxes);

    Solution solve(int min_weight) const;

private:
    std::vector<int> weights_;
    std::vector<int> taxes_;

    void validate_input() const;
    int calculate_max_weight() const;
    std::vector<int> find_min_taxes(int max_weight) const;
    Solution reconstruct_solution(const std::vector<int>& min_taxes, int min_weight) const;
};

#endif 
