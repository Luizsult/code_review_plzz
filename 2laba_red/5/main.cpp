/* Продолжение задания №5: Перемещение среднего элемента из списка L1 с нечётным количеством элементов 
в конец списка L2 с помощью одного вызова функции splice */

#include "list_processor.h"
#include <iostream>
#include <exception>

int main() {
    setlocale(LC_ALL, "Russian");
    
    try {
        ListProcessor processor;
        processor.Run();
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Неизвестная ошибка" << std::endl;
        return 1;
    }
    
    return 0;
}
