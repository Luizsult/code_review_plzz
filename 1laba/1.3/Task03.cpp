// К-ичные числа. Среди чисел в системе счисления с основанием K (2≤K≤10) определить сколько имеется 
// чисел из N (1<N<20, N+K<26) разрядов таких,что в их записи не содержится более двух подряд идущих нулей.
// Для того, чтобы избежать переполнения, ответ представьте в виде вещественного числа.

#include <iostream>
using namespace std;

double kichnye(int N, int K) {
    long long nz = K - 1;
    long long oz = 1;
    long long tz = 0;
    for (int i = 2; i <= N; i++) {
        long long nz_ = (K - 1) * (nz + oz);
        long long oz_ = nz;
        long long tz_ = tz + oz*K;
        nz = nz_;
        oz = oz_;
        tz = tz_;
    }
    return nz + oz;
}

int main() {
    setlocale(LC_ALL, "ru");
    int N, K;
    cout << "Введите количество разрядов N (1 < N < 20): ";
    cin >> N;
    if (N <= 1 || N >= 20) {
        cout << "Некорректные входные данные" << endl;
        return 1;
    }
    cout << "Введите систему счисления К (2 <= K <= 10, N + K < 26): ";
    cin >> K;
    if (K < 2 || K > 10 || N + K >= 26) {
        cout << "Некорректные значения" << endl;
        return 1;
    }

    double bebe = kichnye(N, K);
    cout << "Количество чисел, в которых не содержится более двух подряд идущих нулей: " << bebe << endl;

    return 0;
}