#ifndef RANDOM_SHUFFLE_H
#define RANDOM_SHUFFLE_H

#include <string>

/**
 * @brief Проверяет, является ли слово валидным для перемешивания.
 * 
 * Валидное слово должно:
 * - Быть непустым
 * - Содержать только буквенные символы
 * 
 * @param word Слово для проверки
 * @return true Если слово валидно
 * @return false Если слово невалидно
 */
bool IsValidWord(const std::string& word);

/**
 * @brief Перемешивает буквы в слове до получения исходного слова.
 * 
 * На каждой итерации выводит текущую перестановку. Подсчитывает количество попыток.
 * 
 * @param original_word Исходное слово для перемешивания
 * @return int Количество попыток до получения исходного слова
 * @throws std::invalid_argument Если исходное слово невалидно
 */
int ShuffleWordUntilMatch(const std::string& original_word);

#endif  // RANDOM_SHUFFLE_H
