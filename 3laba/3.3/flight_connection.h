/**
 * @file flight_connection.h
 * @brief Header file for flight connection operations.
 * 
 * This file contains declarations for functions that process flight connections
 * between cities represented as an adjacency matrix.
 */

#ifndef FLIGHT_CONNECTION_H
#define FLIGHT_CONNECTION_H

#include <vector>
#include <string>

/**
 * @brief Finds cities reachable within a limited number of transfers.
 * 
 * Given an adjacency matrix of flight connections, this function finds all cities
 * reachable from a starting city with less than a specified number of transfers.
 * 
 * @param adjacencyMatrix The adjacency matrix representing flight connections.
 * @param startCity The starting city (1-based index).
 * @param maxTransfers The maximum number of allowed transfers.
 * @return std::vector<int> Sorted list of reachable cities (1-based indices), or {-1} if none.
 * @throws std::invalid_argument If input parameters are invalid.
 */
std::vector<int> FindReachableCities(const std::vector<std::vector<int>>& adjacencyMatrix,
                                    int startCity,
                                    int maxTransfers);

/**
 * @brief Reads flight connections from a file and builds an adjacency matrix.
 * 
 * @param fileName The name of the file containing the flight connections data.
 * @return std::vector<std::vector<int>> The adjacency matrix.
 * @throws std::runtime_error If the file cannot be opened or data is invalid.
 */
std::vector<std::vector<int>> ReadFlightConnections(const std::string& fileName);

#endif  // FLIGHT_CONNECTION_H
