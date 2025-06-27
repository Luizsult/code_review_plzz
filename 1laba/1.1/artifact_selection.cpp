#include "artifact_selection.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <stdexcept>

ArtifactData readInputData(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл: " + filename);
    }

    ArtifactData data;
    file >> data.N >> data.Z;

    //FIXME: Добавлена проверка на положительное количество артефактов
    if (data.N <= 0) {
        throw std::runtime_error("Количество артефактов должно быть положительным");
    }

    data.weights.resize(data.N);
    data.taxes.resize(data.N);

    //FIXME: Добавлена проверка корректности данных весов
    for (int i = 0; i < data.N; ++i) {
        if (!(file >> data.weights[i])) {
            throw std::runtime_error("Некорректные данные веса");
        }
    }

    //FIXME: Добавлена проверка корректности данных налогов
    for (int i = 0; i < data.N; ++i) {
        if (!(file >> data.taxes[i])) {
            throw std::runtime_error("Некорректные данные налогов");
        }
    }

    return data;
}

std::vector<int> selectArtifacts(const ArtifactData& data) {
    //FIXME: Исправлено именование переменных для лучшей читаемости
    // int maxWes, vector<int> minNalog
    int max_weight = 0;
    for (int weight : data.weights) {
        max_weight += weight;
    }

    std::vector<int> min_tax(max_weight + 1, std::numeric_limits<int>::max());
    min_tax[0] = 0;

    //FIXME: Улучшена читаемость циклов
    // for (int i = 0; i < N; i++)
    for (int i = 0; i < data.N; ++i) {
        for (int w = max_weight; w >= data.weights[i]; --w) {
            if (min_tax[w - data.weights[i]] != std::numeric_limits<int>::max()) {
                min_tax[w] = std::min(min_tax[w], min_tax[w - data.weights[i]] + data.taxes[i]);
            }
        }
    }

    int min_tax_value = std::numeric_limits<int>::max();
    int total_weight = 0;
    for (int w = data.Z + 1; w <= max_weight; ++w) {
        if (min_tax[w] < min_tax_value) {
            min_tax_value = min_tax[w];
            total_weight = w;
        }
    }

    std::vector<int> selected_artifacts;
    for (int i = data.N - 1, w = total_weight; i >= 0; --i) {
        if (w >= data.weights[i] && min_tax[w] == min_tax[w - data.weights[i]] + data.taxes[i]) {
            selected_artifacts.push_back(i + 1);
            w -= data.weights[i];
        }
    }

    //FIXME: Вывод результатов вынесен в отдельную функцию
    printResults(selected_artifacts, total_weight, min_tax_value);

    return selected_artifacts;
}

void printResults(const std::vector<int>& selected, int total_weight, int total_tax) {
    std::cout << "Индексы артефактов: ";
    for (int index : selected) {
        std::cout << index << " ";
    }
    std::cout << "\nСуммарный вес: " << total_weight << " кг";
    std::cout << "\nОбщая ценность: " << total_tax << std::endl;
}
