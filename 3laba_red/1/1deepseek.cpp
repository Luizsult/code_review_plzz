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
#include <chrono>

using namespace std;

int main() {
    string word;
    cout << "Введите слово: ";
    cin >> word;
    
    string original = word;
    string shuffled = word;
    int attempts = 0;
    
    // Инициализация генератора случайных чисел
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 generator(seed);
    
    cout << endl;
    
    do {
        // Перемешиваем слово
        shuffle(shuffled.begin(), shuffled.end(), generator);
        
        // Выводим перемешанное слово
        cout << shuffled << endl;
        
        attempts++;
        
    } while (shuffled != original);
    
    cout << attempts << " попыток" << endl;
    
    return 0;
}
