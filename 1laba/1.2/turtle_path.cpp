#include "turtle_path.h"
#include <fstream>
#include <algorithm>
#include <stdexcept>

using namespace std;

vector<vector<int>> ReadBoardFromFile(const string& filename, int& n) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        //FIXME: Заменили простой cerr на выбрасывание исключения
        throw runtime_error("Ошибка! Не удалось открыть input.txt");
    }

    fin >> n;
    //FIXME: Добавили явную проверку размера доски
    if (n <= 1 || n >= 80) {
        throw out_of_range("Некорректный размер доски! Допустимый диапазон: 1 < N < 80");
    }

    vector<vector<int>> board(n, vector<int>(n));
    for (auto& row : board) {
        for (auto& cell : row) {
            fin >> cell;
            //FIXME: Добавили проверку значений клеток
            if (cell < 0 || cell > 100) {
                throw out_of_range("Значение клетки должно быть от 0 до 100");
            }
        }
    }

    return board;
}

int CalculateMinPath(const vector<vector<int>>& board) {
    //FIXME: Добавили проверку на пустую доску
    if (board.empty() || board[0].empty()) {
        throw logic_error("Доска не может быть пустой");
    }

    const int n = board.size();
    vector<vector<int>> dp(n, vector<int>(n));

    //FIXME: Оптимизировали инициализацию DP таблицы
    dp[n-1][0] = board[n-1][0];

    for (int j = 1; j < n; ++j) {
        dp[n-1][j] = dp[n-1][j-1] + board[n-1][j];
    }

    for (int i = n-2; i >= 0; --i) {
        dp[i][0] = dp[i+1][0] + board[i][0];
    }

    for (int i = n-2; i >= 0; --i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + board[i][j];
        }
    }

    return dp[0][n-1];
}

void WriteResultToFile(const string& filename, int result) {
    ofstream fout(filename);
    if (!fout.is_open()) {
        //FIXME: Добавили обработку ошибок записи
        throw runtime_error("Ошибка! Не удалось создать output.txt");
    }
    fout << result;
}
