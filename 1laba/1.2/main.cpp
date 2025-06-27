#include "turtle_path.h"
#include <iostream>

int main() {
    try {
        int n = 0;
        //FIXME: Убрали прямой доступ к файлам из main
        const auto board = ReadBoardFromFile("input.txt", n);
        const int result = CalculateMinPath(board);
        WriteResultToFile("output.txt", result);
        
        cout << "Минимальная сумма пути: " << result << endl;
        return 0;
    } 
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }
}
