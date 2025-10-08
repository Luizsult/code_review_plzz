/* Ввести с клавиатуры любое слово. Используя генерацию случайных чисел, переставить буквы этого слова в случайном порядке. Делать это до тех пор, пока полученное слово не совпадёт с начальным словом. Выводить слово после каждой перестановки и посчитать общее количество выведенных слов (не считая исходного). Пример выполнения программы: 
Введите слово: корова 
воакро 
вокроа 
ароовк 
краоов 
крваоо 
оокавр 
ооквра 
вкраоо 
корова 
9 попыток */

#include <iostream>
#include <string>
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
        attempts++;
    } while (word != original_word);

    std::cout << attempts << " попыток" << std::endl;

    return 0;
}
