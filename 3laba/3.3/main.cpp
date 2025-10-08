/**
 * @file main.cpp
 * @brief Основная программа для поиска городов с ограниченным числом пересадок.
 * 
 * Программа читает данные о авиационных соединениях из файла, затем находит и выводит
 * города, достижимые из заданного города с числом пересадок меньше указанного.
 */

#include <iostream>
#include <vector>
#include "flight_connection.h"

int main() {
    try {
        std::string fileName;
        std::cout << "Введите имя файла: ";
        std::cin >> fileName;

        std::vector<std::vector<int>> adjacencyMatrix = ReadFlightConnections(fileName);

        int startCity, maxTransfers;
        std::cout << "Введите начальный город (индекс с 1): ";
        std::cin >> startCity;
        std::cout << "Введите максимальное число пересадок: ";
        std::cin >> maxTransfers;

        std::vector<int> reachableCities = FindReachableCities(adjacencyMatrix, startCity, maxTransfers);

        std::cout << "Достижимые города: ";
        for (int city : reachableCities) {
            std::cout << city << " ";
        }
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
