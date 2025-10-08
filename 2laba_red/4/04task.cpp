/*
Дан циклический двусвязный линейный список и указатель первый 
элемент этого списка. Необходимо удалить в списке все элементы, у которых правый и 
левый сосед совпадают. Если таких элементов нет, то оставить список без изменений. 
Первый и последний элементы считать соседями. В результате вернуть ссылку на 
последний элемент полученного списка.

Все динамические структуры данных реализовывать через классы. Не использовать STL.  
Для каждой динамической структуры должен быть предусмотрен стандартный
набор методов - добавления/удаления/вывода элементов. Во всех задачах обязательно наличие 
дружественного интерфейса. Ввод данных с клавиатуры.
*/

#include <iostream>
using namespace std;
class Node
{
public:
    int y;
    Node* Next;
    Node* Prev;
    Node(int x) : y(x), Next(NULL), Prev(NULL) {}
};
class LinkedList
{
public:
    Node* Head;
    Node* Tail;
    LinkedList() : Head(NULL), Tail(NULL) {}
};

void AddLast(LinkedList& s, int x)
{
    Node* NewNode = new Node(x);
    NewNode->Next = NULL;
    NewNode->Prev = s.Tail;
    if (s.Tail == NULL)
        s.Head = NewNode;
    else
        s.Tail->Next = NewNode;
    s.Tail = NewNode;
    s.Tail->Next = s.Head;
    s.Head->Prev = s.Tail;
}
void F(LinkedList& s)
{
    if (s.Head == NULL)
        return;
    Node* MyNode = s.Head;
    Node* Next1 = NULL;

    do {
        Next1 = MyNode->Next;
        if ((MyNode->Prev->y == MyNode->Next->y) && (MyNode->Prev!= MyNode->Next))
        {
            if (MyNode == s.Head && MyNode == s.Tail)
            {
                delete MyNode;
                s.Head = NULL;
                s.Tail = NULL;
                break;
            }
            else if (MyNode == s.Head)
            {
                s.Head = MyNode->Next;
            }
            MyNode->Prev->Next = MyNode->Next;
            MyNode->Next->Prev = MyNode->Prev;
            delete MyNode;
            MyNode = Next1->Prev;
        }
        else {
            MyNode = Next1;
        }
    } while (MyNode != s.Head);
}
void Show(LinkedList& s)
{
    if (s.Head == NULL)
    {
        cout << "Список пуст" << endl;
        return;
    }
    Node* MyNode = s.Head;
    do
    {
        cout << MyNode->y << " ";
        MyNode = MyNode->Next;
    } while (MyNode != s.Head);
    cout << endl;
}
void Clear(LinkedList& s)
{
    if (s.Head == NULL)
        return;
    Node* MyNode = s.Head;
    do
    {
        Node* Temp = MyNode;
        MyNode = MyNode->Next;
        delete Temp;
    } while (MyNode != s.Head);
    s.Head = NULL;
    s.Tail = NULL;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    LinkedList spisok;
    int n, x;
    cout << "Введите количество чисел, которые необходимо записать в список: ";
    cin >> n;
    if (n <= 0)
    {
        cout << "Ошибка." << endl;
        return 1;
    }
    for (int i = 0; i < n;i++)
    {
        cout << "Введите " << i + 1 << " число: ";
        cin >> x;
        AddLast(spisok, x);
    }
    cout << "Исходный список: ";
    Show(spisok);
    F(spisok);
    cout << "Изменённый список: ";
    Show(spisok);
    Clear(spisok);
    return 0;
}
