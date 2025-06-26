#include "artifacts.h"
#include <iostream>

int main() {
    try {
        auto result = select_artifacts("file.txt");
        
        std::cout << "Индексы артефактов: ";
        for (int index : result.selected_indices) {
            std::cout << index << " ";
        }
        std::cout << "\nСуммарный вес: " << result.total_weight << " кг";
        std::cout << "\nОбщая ценность: " << result.total_tax << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
