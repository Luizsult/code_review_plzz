#include <algorithm>
#include <iostream>
#include <random>
#include <string>

int main() {
  std::cout << "Введите слово: ";
  std::string original_word;
  std::cin >> original_word;

  std::string shuffled_word = original_word;

  std::random_device rd;
  std::mt19937 gen(rd());

  int attempts = 0;

  do {
    std::shuffle(shuffled_word.begin(), shuffled_word.end(), gen);
    std::cout << shuffled_word << std::endl;
    ++attempts;
  } while (shuffled_word != original_word);

  std::cout << attempts << " попыток" << std::endl;

  return 0;
}
