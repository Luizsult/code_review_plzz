#include "artifact_selection.h"
#include <iostream>

int main() {
    try {
        //FIXME: Обработка ошибок вынесена в блок try-catch
        ArtifactData data = readInputData("file.txt");
        selectArtifacts(data);
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
