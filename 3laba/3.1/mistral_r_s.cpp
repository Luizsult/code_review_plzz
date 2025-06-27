#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

int main() {
    std::string word;
    std::cout << "Введите слово: ";
    std::cin >> word;

    std::string original_word = word;
    int attempts = 0;

    std::mt19937 generator(static_cast<unsigned int>(std::time(nullptr)));

    do {
        std::shuffle(word.begin(), word.end(), generator);
        std::cout << word << std::endl;
        ++attempts;
    } while (word != original_word);

    std::cout << attempts << " попыток" << std::endl;

    return 0;
}
