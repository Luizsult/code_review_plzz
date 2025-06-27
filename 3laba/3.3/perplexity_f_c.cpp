#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

int main() {
  std::string file_name;
  int start_city, max_transfers;
  std::cin >> file_name >> start_city >> max_transfers;

  std::ifstream input_file(file_name);
  if (!input_file.is_open()) {
    std::cerr << "Cannot open file: " << file_name << "\n";
    return 1;
  }

  int num_cities;
  input_file >> num_cities;

  std::vector<std::vector<int>> adjacency_matrix(
      num_cities, std::vector<int>(num_cities));
  
  for (int i = 0; i < num_cities; ++i) {
    for (int j = 0; j < num_cities; ++j) {
      input_file >> adjacency_matrix[i][j];
    }
  }

  const int start_index = start_city - 1;
  std::vector<int> distance(num_cities, -1);
  std::queue<int> bfs_queue;

  for (int neighbor = 0; neighbor < num_cities; ++neighbor) {
    if (adjacency_matrix[start_index][neighbor] == 1) {
      distance[neighbor] = 1;
      bfs_queue.push(neighbor);
    }
  }

  while (!bfs_queue.empty()) {
    int current = bfs_queue.front();
    bfs_queue.pop();

    for (int next = 0; next < num_cities; ++next) {
      if (adjacency_matrix[current][next] == 1 && distance[next] == -1) {
        distance[next] = distance[current] + 1;
        bfs_queue.push(next);
      }
    }
  }

  std::vector<int> result_cities;
  for (int city = 0; city < num_cities; ++city) {
    if (distance[city] != -1 && distance[city] < max_transfers + 1) {
      result_cities.push_back(city + 1);
    }
  }

  std::sort(result_cities.begin(), result_cities.end());

  if (result_cities.empty()) {
    std::cout << -1 << "\n";
  } else {
    for (size_t i = 0; i < result_cities.size(); ++i) {
      if (i > 0) std::cout << " ";
      std::cout << result_cities[i];
    }
    std::cout << "\n";
  }

  return 0;
}
