#include "random_shuffle.h"
#include <iostream>
#include <string>

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
