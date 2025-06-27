//Археолог нашел N артефактов.Известны веса(сi) и налоговое бремя(di) находок.
//Нужно выбрать такое подмножество находок, чтобы их суммарный вес превысил Z кг, а их об
//щее налоговое бремя оказалось минимальным.Известно, что решение единственно.Укажите
//порядковые номера вещей, которые нужно взять.Исходный данные находятся в текстовом фай
//ле, в первой строке указаны N и Z, а во второй строке значения весов(в кг), в третьей - величина
//налога по каждой находке.Вывести так же суммарный вес и общую ценность результата.

#include <iostream> 
#include <vector> 
#include <fstream> 
#include <algorithm> 
#include <limits> 

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    ifstream file("file.txt");
    if (!file.is_open()) {
        cout << "Файл не открылся!!";
        return 1;
    }
    int N, Z; //Вводим кол-во артефактов и налогов 
    file >> N >> Z; // Вносим в файл 

    vector <int> wes(N); //Хранит веса артефактов. 
    vector <int> nalogi(Z); //Хранит налоговое бремя артефактов. 

    for (int i = 0; i < N; i++) { // заполняем вектора данными  
        file >> wes[i];
    }
    for (int i = 0; i < N; i++) {
        file >> nalogi[i];
    }

    //Максимальный возможный вес подмножества  
    int maxWes = 0;
    for (int wes1 : wes) {
        maxWes += wes1; //Сумма всех артифактов 
    }

    //вектор для хранение  минимального налога  
    vector <int> minNalog(maxWes + 1, numeric_limits<int>::max());
    minNalog[0] = 0;

    //Дигнамическоен прог 

    for (int i = 0; i < N; i++) {
        for (int w = maxWes; w >= wes[i]; w--) {
            if (minNalog[w - wes[i]] != numeric_limits<int>::max()) {
                minNalog[w] = min(minNalog[w], minNalog[w - wes[i]] + nalogi[i]);
            }
        }
    }

    //поиск минимальнорго налога при весе больше Z 
    int minNalogivalue = numeric_limits<int>::max();
    int totalwes = 0;
    for (int w = Z + 1; w <= maxWes; w++) {
        if (minNalog[w] < minNalogivalue) {
            minNalogivalue = minNalog[w];
            totalwes = w;
        }
    }

    //Востаовление выбранных артефактов  
    vector <int> selectart;
    for (int i = N - 1, w = totalwes; i >= 0; --i) {
        if (w >= wes[i] && minNalog[w] == minNalog[w - wes[i]] + nalogi[i]) {
            selectart.push_back(i + 1); // Используем 1-based индекс 
            w -= wes[i];
        }
    }
    // Вывод результата 
    cout << "Индексы артефактов: ";
    for (int index : selectart) {
        cout << index << " ";
    }
    cout << "\nСуммарный вес: " << totalwes << " кг";
    cout << "\nОбщая ценность: " << minNalogivalue << endl;


}