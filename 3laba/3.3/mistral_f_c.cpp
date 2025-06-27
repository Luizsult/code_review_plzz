#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> FindAccessibleCities(const string& filename, int K, int L) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file";
        return {-1};
    }

    int n;
    file >> n;
    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            file >> matrix[i][j];
        }
    }

    vector<bool> visited(n, false);
    vector<int> distance(n, 0);
    queue<int> q;
    vector<int> result;

    q.push(K - 1);
    visited[K - 1] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 0; i < n; ++i) {
            if (matrix[current][i] && !visited[i]) {
                visited[i] = true;
                distance[i] = distance[current] + 1;
                if (distance[i] < L) {
                    result.push_back(i + 1);
                    q.push(i);
                }
            }
        }
    }

    if (result.empty()) {
        return {-1};
    }

    sort(result.begin(), result.end());
    return result;
}

int main() {
    string filename = "FileName";
    int K = 1; // Пример значения
    int L = 2; // Пример значения

    vector<int> result = FindAccessibleCities(filename, K, L);

    for (int city : result) {
        cout << city << " ";
    }
    cout << endl;

    return 0;
}
