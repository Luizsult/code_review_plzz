/**
 * @file flight_connection.h
 * @brief Заголовочный файл для работы с авиационными соединениями.
 * 
 * Содержит объявления функций для обработки авиационных маршрутов между городами,
 * представленных в виде матрицы смежности.
 */

#ifndef FLIGHT_CONNECTION_H
#define FLIGHT_CONNECTION_H

#include <vector>
#include <string>

/**
 * @brief Находит города, достижимые с ограниченным числом пересадок.
 * 
 * По заданной матрице смежности авиационных соединений находит все города,
 * достижимые из начального города с числом пересадок меньше указанного.
 * 
 * @param adjacencyMatrix Матрица смежности, представляющая авиационные соединения.
 * @param startCity Начальный город (индекс начинается с 1).
 * @param maxTransfers Максимально допустимое число пересадок.
 * @return std::vector<int> Отсортированный список достижимых городов (индексы с 1), или {-1} если таких нет.
 * @throws std::invalid_argument Если входные параметры некорректны.
 */
std::vector<int> FindReachableCities(const std::vector<std::vector<int>>& adjacencyMatrix,
                                    int startCity,
                                    int maxTransfers);

/**
 * @brief Читает данные о авиационных соединениях из файла.
 * 
 * @param fileName Имя файла с данными о авиационных соединениях.
 * @return std::vector<std::vector<int>> Матрица смежности.
 * @throws std::runtime_error Если файл не может быть открыт или данные некорректны.
 */
std::vector<std::vector<int>> ReadFlightConnections(const std::string& fileName);

#endif  // FLIGHT_CONNECTION_H
