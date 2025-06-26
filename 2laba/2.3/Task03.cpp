
/*Дан односвязный линейный список и указатель на голову списка P1. Необходимо
вставить значение M перед каждым вторым элементом списка, и вывести ссылку на последний
элемент полученного списка P2. При нечетном числе элементов исходного списка в конец
списка вставлять не надо.


Для каждой динамической структуры должен быть предусмотрен стандартный набор методов - 
добавления/удаления/вывода элементов. 
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.

*/




#include <iostream>
using namespace std;
class Node {
public:
    int data;       
    Node* next;     
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head; 

public:
    
    LinkedList() : head(nullptr) {}

    void add(int value) {
        Node* newNode = new Node(value); 
        if (head == nullptr) {           
            head = newNode;              
        }
        else {
            Node* current = head;        
            while (current->next != nullptr) { 
                current = current->next;
            }
            current->next = newNode;   
        }
    }

    // Метод для вставки значения M перед каждым вторым элементом
    void insertBeforeEverySecond(int M) {
        Node* current = head;          
        int count = 1;                  

        while (current != nullptr && current->next != nullptr) {
            if (count % 2 == 1) {      
                Node* newNode = new Node(M); 
                newNode->next = current->next; 
                current->next = newNode; 
                current = newNode->next; 
            }
            else {
                current = current->next; 
            }
            count++;                  
        }
    }

    
    void print() {
        Node* current = head;          
        while (current != nullptr) {    
            cout << current->data << " "; 
            current = current->next;    
        }
        cout << endl;         
    }

    // Метод для получения указателя на последний элемент списка
    Node* getLastNode() {
        Node* current = head;           // Начинаем с головы списка
        while (current != nullptr && current->next != nullptr) { // Идем до последнего узла
            current = current->next;
        }
        return current;                 // Возвращаем указатель на последний узел
    }
    void clearList() {
        while (head != nullptr) {       
            Node* temp = head;          
            head = head->next;         
            delete temp;               
        }
        cout << "Список очищен." << endl;
    }
    
    friend void insertBeforeEverySecond(LinkedList& list, int M);
};


void insertBeforeEverySecond(LinkedList& list, int M) {
    list.insertBeforeEverySecond(M);
}

int main() {
    LinkedList list;                     // Создаем список
    int n, value, M;

    
    cout << "Введите количество элементов в списке: ";
    cin >> n;
    cout << "Введите элементы списка: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;               // Вводим значение элемента
        list.add(value);                 // Добавляем элемент в список
    }

   
    cout << "Введите значение M для вставки: ";
    cin >> M;

    // Вставка значения M перед каждым вторым элементом
    insertBeforeEverySecond(list, M);

    
    cout << "Список после вставки: ";
    list.print();

    // Получение указателя на последний элемент списка
    Node* lastNode = list.getLastNode();

    // Вывод результата
    if (lastNode != nullptr) {
        cout << "Указатель на последний элемент списка: " << lastNode << endl;
        cout << "Значение последнего элемента: " << lastNode->data <<endl;
    }
    else {
        cout << "Список пуст." << endl;

    }
    list.clearList();

    // Проверка, что список пуст
    cout << "Проверка списка после очистки: ";
    list.print();


    return 0;                           
}