#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>

void FindReachableCities(const std::string& file_name, int k, int l) {
    std::ifstream input_file(file_name);
    if (!input_file.is_open()) {
        std::cerr << "Error: Could not open file " << file_name << std::endl;
        std::cout << -1 << std::endl;
        return;
    }

    int num_cities;
    input_file >> num_cities;
    if (num_cities <= 0 || num_cities > 25) {
        std::cerr << "Error: Invalid number of cities" << std::endl;
        std::cout << -1 << std::endl;
        return;
    }

    std::vector<std::vector<int>> adjacency_matrix(num_cities, std::vector<int>(num_cities));
    for (int i = 0; i < num_cities; ++i) {
        for (int j = 0; j < num_cities; ++j) {
            input_file >> adjacency_matrix[i][j];
        }
    }

    if (k < 1 || k > num_cities) {
        std::cerr << "Error: Invalid starting city K" << std::endl;
        std::cout << -1 << std::endl;
        return;
    }

    std::set<int> reachable_cities;
    std::queue<std::pair<int, int>> queue;  // {city, transfers}
    queue.push({k - 1, 0});
    reachable_cities.insert(k - 1);

    while (!queue.empty()) {
        auto current = queue.front();
        queue.pop();
        int current_city = current.first;
        int current_transfers = current.second;

        if (current_transfers >= l) {
            continue;
        }

        for (int neighbor = 0; neighbor < num_cities; ++neighbor) {
            if (adjacency_matrix[current_city][neighbor] == 1 &&
                reachable_cities.find(neighbor) == reachable_cities.end()) {
                reachable_cities.insert(neighbor);
                queue.push({neighbor, current_transfers + 1});
            }
        }
    }

    // Remove the starting city if it was added (since we need cities reachable WITH transfers)
    reachable_cities.erase(k - 1);

    if (reachable_cities.empty()) {
        std::cout << -1 << std::endl;
    } else {
        std::vector<int> sorted_cities(reachable_cities.begin(), reachable_cities.end());
        std::sort(sorted_cities.begin(), sorted_cities.end());
        for (size_t i = 0; i < sorted_cities.size(); ++i) {
            if (i != 0) {
                std::cout << " ";
            }
            std::cout << sorted_cities[i] + 1;  // Convert back to 1-based indexing
        }
        std::cout << std::endl;
    }
}

int main() {
    std::string file_name;
    int k, l;
    std::cin >> file_name >> k >> l;

    FindReachableCities(file_name, k, l);

    return 0;
}
