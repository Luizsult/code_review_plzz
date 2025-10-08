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
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>

int main() {
    std::string word;
    std::cout << "Введите слово: ";
    std::cin >> word;

    if (word.empty()) {
        std::cout << "Слово пустое!" << std::endl;
        return 0;
    }

    std::string current = word;
    int attempts = 0;

    // Инициализация генератора случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());

    do {
        // Перемешиваем буквы текущего слова
        std::shuffle(current.begin(), current.end(), gen);
        std::cout << current << std::endl;
        attempts++;
    } while (current != word);

    std::cout << attempts << " попыток" << std::endl;

    return 0;
}
