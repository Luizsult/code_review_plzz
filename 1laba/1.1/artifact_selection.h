#ifndef ARTIFACT_SELECTION_H
#define ARTIFACT_SELECTION_H

#include <vector>
#include <string>
#include <stdexcept>

struct ArtifactData {
    int N;
    int Z;
    std::vector<int> weights;
    std::vector<int> taxes;
};

ArtifactData readInputData(const std::string& filename);
std::vector<int> selectArtifacts(const ArtifactData& data);
void printResults(const std::vector<int>& selected, int total_weight, int total_tax);

#endif  
