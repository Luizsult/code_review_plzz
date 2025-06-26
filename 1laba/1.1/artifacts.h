/* 
Задание: Выбор артефактов с минимальным налоговым бременем при суммарном весе > Z
Дано: N артефактов с весами (ci) и налоговым бременем (di)
Требуется: найти подмножество с минимальным налогом и весом > Z
*/

#ifndef ARTIFACTS_H
#define ARTIFACTS_H

#include <vector>
#include <string>
#include <stdexcept>

struct ArtifactSelectionResult {
    std::vector<int> selected_indices;
    int total_weight;
    int total_tax;
};

ArtifactSelectionResult select_artifacts(const std::string& filename);

#endif  // ARTIFACTS_H
