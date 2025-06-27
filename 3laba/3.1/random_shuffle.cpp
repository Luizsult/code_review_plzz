#include "random_shuffle.h"
#include <algorithm>
#include <random>
#include <stdexcept>
#include <string>

/**
 * @brief Проверяет валидность входного слова для перемешивания.
 * 
 * Детальные критерии валидности:
 * - Строка не должна быть пустой
 * - Все символы должны быть буквами (isalpha())
 * 
 * @param word Строка для проверки
 * @return true Если слово соответствует всем критериям
 * @return false Если слово не соответствует какому-либо критерию
 */
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

/**
 * @brief Выполняет циклическое перемешивание слова до совпадения с оригиналом.
 * 
 * Алгоритм работы:
 * 1. Проверяет валидность входного слова
 * 2. Инициализирует генератор случайных чисел
 * 3. В цикле перемешивает буквы с помощью std::shuffle
 * 4. Выводит каждую перестановку
 * 5. Прекращает работу при совпадении с оригиналом
 * 
 * @param original_word Исходное слово для перемешивания
 * @return int Количество выполненных перестановок
 * @throws std::invalid_argument Если входное слово невалидно
 * 
 * @note Для вывода используется printf вместо cout для совместимости с широкими символами
 * @warning Время выполнения зависит от длины слова и случайности
 */
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
