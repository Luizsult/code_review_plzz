#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

namespace string_shuffle {
    // Функция для перемешивания строки
    void shuffleString(std::string& str) {
        int length = str.length();
        for (int i = length - 1; i > 0; --i) {
            int j = rand() % (i + 1);
            std::swap(str[i], str[j]);
        }
    }

    // Функция для проверки совпадения строк
    bool stringsMatch(const std::string& str1, const std::string& str2) {
        return str1 == str2;
    }

    int main() {
        std::string originalWord;
        std::cout << "Введите слово: ";
        std::getline(std::cin, originalWord);

        std::string currentWord = originalWord;
        srand(static_cast<unsigned>(std::time(nullptr)));
        
        int attemptCount = 0;
        currentWord = originalWord;

        while (!stringsMatch(currentWord, originalWord)) {
            shuffleString(currentWord);
            std::cout << currentWord << " ";
            attemptCount++;
        }

        std::cout << "\nКоличество попыток: " << attemptCount << std::endl;
        return 0;
    }
}  // namespace string_shuffle
