#include <algorithm>
#include <iostream>
#include <random>
#include <string>

int main() {
    std::string word;
    std::cout << "Введите слово: ";
    std::cin >> word;

    std::string shuffled_word = word;
    int attempts = 0;
    std::random_device rd;
    std::mt19937 g(rd());

    do {
        std::shuffle(shuffled_word.begin(), shuffled_word.end(), g);
        std::cout << shuffled_word << " ";
        attempts++;
    } while (shuffled_word != word);

    std::cout << "\n" << attempts << " попыток\n";

    return 0;
}
