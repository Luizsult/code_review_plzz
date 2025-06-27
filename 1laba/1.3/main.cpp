#include <iostream>
#include "k_ary_numbers.h"

int main() {
    try {
        int N, K;
        std::cout << "Enter number of digits N (1 < N < 20): ";
        std::cin >> N;
        
        std::cout << "Enter base K (2 <= K <= 10, N + K < 26): ";
        std::cin >> K;

        double count = Count(N, K);
        std::cout << "Number count without more than two consecutive zeros: " << count << std::endl;
        
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
