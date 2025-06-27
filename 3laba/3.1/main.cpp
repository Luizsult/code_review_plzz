#include "random_shuffle.h"
#include <iostream>
#include <string>

/**
 * @brief Главная функция программы.
 * 
 * Запрашивает у пользователя слово, запускает процесс перемешивания
 * и выводит количество попыток до получения исходного слова.
 * 
 * @return int Код возврата программы (0 - успех, 1 - ошибка)
 */
int main() {
    try {
        std::string word;
        printf("Введите слово: ");
        std::cin >> word;

        int attempts = ShuffleWordUntilMatch(word);
        printf("%d попыток\n", attempts);
    } catch (const std::exception& e) {
        fprintf(stderr, "Ошибка: %s\n", e.what());
        return 1;
    }

    return 0;
}
