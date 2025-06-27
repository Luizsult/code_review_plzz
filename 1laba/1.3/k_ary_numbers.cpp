#include "k_ary_numbers.h"
#include <stdexcept>

double Count(int N, int K) {
    if (N <= 1 || N >= 20) {
        throw std::invalid_argument("N must satisfy: 1 < N < 20");
    }
    if (K < 2 || K > 10) {
        throw std::invalid_argument("K must satisfy: 2 <= K <= 10");
    }
    if (N + K >= 26) {
        throw std::invalid_argument("N + K must be < 26");
    }

    // FIXME: Изменили типы с long long на double для предотвращения переполнения
    // и добавили более понятные имена переменных
    // long long nz = K - 1;
    // long long oz = 1;
    // long long tz = 0;
    double numbers_without_zero = K - 1;
    double numbers_with_one_zero = 1;
    double numbers_with_two_zeros = 0;

    for (int i = 2; i <= N; i++) {
        // FIXME: Упростили вычисления
        // long long nz_ = (K - 1) * (nz + oz);
        // long long oz_ = nz;
        // long long tz_ = tz + oz*K;
        double new_without_zero = (K - 1) * (numbers_without_zero + numbers_with_one_zero);
        double new_with_one_zero = numbers_without_zero;
        double new_with_two_zeros = numbers_with_one_zero;

        numbers_without_zero = new_without_zero;
        numbers_with_one_zero = new_with_one_zero;
        numbers_with_two_zeros = new_with_two_zeros;
    }

    return numbers_without_zero + numbers_with_one_zero;
}
