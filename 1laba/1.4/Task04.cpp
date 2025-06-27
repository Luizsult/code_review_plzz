//Во всех заданиях данной подгруппы предполагается, что исходные строки, определяющие выражения, 
//не содержат пробелов.При выполнении заданий не следует использовать оператор цикла.
//Вывести значение целочисленного выражения, заданного в виде строки S.Выражение
//определяется следующим образом :
//		<выражение> :: = <терм> | <выражение> +<терм> | <выражение> − <терм>
//		<терм> :: = <цифра> | <терм> * <цифра>

#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

int NumRead(string& s, int& symb, int currentNumber = 0) {
    if (symb >= s.length() || !isdigit(s[symb])) {
        return currentNumber;
    }
    currentNumber = currentNumber * 10 + (s[symb] - '0');
    symb++;

    return NumRead(s, symb, currentNumber);
}

int CalculateTerm(string& s, int& symb) {
    int value = NumRead(s, symb);

    while (symb < s.length() && (s[symb] == '*' || s[symb] == '/')) {
        char znak = s[symb];
        symb++;
        int number = NumRead(s, symb);

        if (znak == '*') {
            value *= number;
        }
        else {
            if (number == 0) {
                cout << "Ошибка при делении на ноль!" << endl;
                exit(1); // ну типо анлаки
            }
            value /= number;
        }
    }
    return value;
}

int CalculateS(string& s, int& symb) {
    int value = CalculateTerm(s, symb);

    while (symb < s.length() && (s[symb] == '+' || s[symb] == '-')) {
        char znak = s[symb];
        symb++;
        int term = CalculateTerm(s, symb);

        if (znak == '+') {
            value += term;
        }
        else {
            value -= term;
        }
    }
    return value;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string S; cout << "Введите выражение -> "; getline(cin, S);

    int symb = 0;
    int result = CalculateS(S, symb);

    cout << "Результат -> " << result << endl;
    return 0;
}