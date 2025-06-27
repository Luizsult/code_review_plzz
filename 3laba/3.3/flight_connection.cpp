/**
 * @file flight_connection.cpp
 * @brief Реализация операций с авиационными соединениями.
 * 
 * Содержит реализацию функций, объявленных в flight_connection.h.
 */

#include "flight_connection.h"
#include <fstream>
#include <stdexcept>
#include <queue>
#include <algorithm>
#include <unordered_set>

std::vector<int> FindReachableCities(const std::vector<std::vector<int>>& adjacencyMatrix,
                                    int startCity,
                                    int maxTransfers) {
    // Проверка входных параметров
    if (adjacencyMatrix.empty() || adjacencyMatrix.size() != adjacencyMatrix[0].size()) {
        throw std::invalid_argument("Некорректная матрица смежности");
    }
    const int numCities = adjacencyMatrix.size();
    if (startCity < 1 || startCity > numCities) {
        throw std::invalid_argument("Начальный город вне диапазона");
    }
    if (maxTransfers < 0) {
        throw std::invalid_argument("Число пересадок не может быть отрицательным");
    }

    std::vector<int> reachableCities;
    std::queue<std::pair<int, int>> q;  // {город, текущее число пересадок}
    std::vector<bool> visited(numCities, false);

    // Конвертируем в 0-базированный индекс
    const int startIndex = startCity - 1;
    q.push({startIndex, -1});  // Начальный город требует 0 пересадок, но мы считаем рёбра
    visited[startIndex] = true;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int currentCity = current.first;
        int currentTransfers = current.second;

        if (currentTransfers < maxTransfers) {
            reachableCities.push_back(currentCity + 1);  // Конвертируем обратно в 1-базированный
        } else {
            continue;
        }

        for (int neighbor = 0; neighbor < numCities; ++neighbor) {
            if (adjacencyMatrix[currentCity][neighbor] == 1 && !visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, currentTransfers + 1});
            }
        }
    }

    // Удаляем дубликаты и сортируем
    std::sort(reachableCities.begin(), reachableCities.end());
    reachableCities.erase(
        std::unique(reachableCities.begin(), reachableCities.end()),
        reachableCities.end());

    // Удаляем начальный город, если он был включён
    reachableCities.erase(
        std::remove(reachableCities.begin(), reachableCities.end(), startCity),
        reachableCities.end());

    if (reachableCities.empty()) {
        return {-1};
    }
    return reachableCities;
}

std::vector<std::vector<int>> ReadFlightConnections(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Не удалось открыть файл: " + fileName);
    }

    int numCities;
    inputFile >> numCities;

    // Проверка числа городов
    if (numCities <= 0 || numCities > 25) {
        throw std::runtime_error("Некорректное число городов: должно быть от 1 до 25");
    }

    std::vector<std::vector<int>> adjacencyMatrix(numCities, std::vector<int>(numCities));

    for (int i = 0; i < numCities; ++i) {
        for (int j = 0; j < numCities; ++j) {
            if (!(inputFile >> adjacencyMatrix[i][j])) {
                throw std::runtime_error("Некорректные данные матрицы в файле");
            }
            // Проверка значений матрицы
            if (adjacencyMatrix[i][j] != 0 && adjacencyMatrix[i][j] != 1) {
                throw std::runtime_error("Значения матрицы должны быть 0 или 1");
            }
        }
    }

    return adjacencyMatrix;
}
