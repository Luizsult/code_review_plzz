#include "deepseek_random_shuffle.h"
#include <algorithm>
#include <random>
#include <stdexcept>
#include <string>

bool IsValidWord(const std::string& word) {
    if (word.empty()) {
        return false;
    }

   for (char c : word) {
        if (!isalpha(c)) {
            return false;
        }
    }

    return true;
}

int ShuffleWordUntilMatch(const std::string& original_word) {
    if (!IsValidWord(original_word)) {
        throw std::invalid_argument("Invalid input word");
    }

    std::string shuffled_word = original_word;
    int attempts = 0;
    std::random_device rd;
    std::mt19937 g(rd());

    do {
        std::shuffle(shuffled_word.begin(), shuffled_word.end(), g);
        ++attempts;
        printf("%s\n", shuffled_word.c_str());
    } while (shuffled_word != original_word);

    return attempts;
}
