#include "queue.h"
#include <iostream>

int main() {
    try {
        PQueue queue;
        
        for (int i = 1; i <= 10; ++i) {
            queue.Enqueue(i);
        }

        std::cout << "Извлеченные элементы: ";
        for (int i = 0; i < 5; ++i) {
            int value = queue.Dequeue();
            std::cout << value << " ";
        }
        std::cout << "\n";

        if (!queue.IsEmpty()) {
            std::cout << "Адрес начала очереди: " << queue.front()
                      << ", Значение: " << queue.front()->data << "\n";
            std::cout << "Адрес конца очереди: " << queue.last()
                      << ", Значение: " << queue.last()->data << "\n";
        } else {
            std::cout << "Очередь пуста, адреса начала и конца: nullptr\n";
        }

    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }

    return 0;
}
