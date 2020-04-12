#include <iostream>
using namespace std;

/*1. Описать структуру  с именем DATA,содержащую следующие поля:
-год
-месяц
-день
Описать структуру с именем zoo:
-порода
-кличка
-возраст
-масса
-дата зачисления через структуру DATA
2.Реализовать следующие функции:
1)ввод с клавиатуры данных в массив,состоящих из n элементов типа zoo(n вводится с клавиатуры,память под массив выделять динамически)
2)упорядочить данные по дате и вывести полученный результат на экран
3)определить самого легкого из самых взрослых животных зоопарка.*/

struct zoo
{
    char poroda[50];
    char klichka[50];
    int age;
    int weight;
    struct DATA
    {
        int year;
        int month;
        int day;
    }date;

};

zoo Input();
void InputAll(zoo* A, int n);
void Output(zoo a);
void OutputAll(zoo* A, int n);
void SortDate(zoo* A, int n);
void LightWeight(zoo* A, int n);

int main()
{
    int n;
    cout << "Vitalya sosi." << endl;
    cout << "Input number of animal:" << endl;
    cin >> n;
    zoo* A = new zoo[n]; // Выделение памяти для массива
    InputAll(A, n);
    OutputAll(A, n);
    SortDate(A, n);
    LightWeight(A, n);
    return 0;
}

zoo Input()
{
    zoo a;
    cout << "poroda: ";
    cin >> a.poroda;
    cout << "klichka: ";
    cin >> a.klichka;
    cout << "age: ";
    cin >> a.age;
    cout << "weight: ";
    cin >> a.weight;
    cout << "year: ";
    cin >> a.date.year;
    cout << "month: ";
    cin >> a.date.month;
    cout << "day: ";
    cin >> a.date.day;
    return a;
}

void InputAll(zoo* A, int n)
{
    for (int i = 0; i < n; i++)
    {
        A[i] = Input();
    }

}

void Output(zoo a)
{
    cout << "________________________ " << endl;
    cout << "poroda: " << a.poroda << endl;
    cout << "klichka: " << a.klichka << endl;
    cout << "age: " << a.age << endl;
    cout << "weight: " << a.weight << endl;
    cout << "year: " << a.date.year << endl;
    cout << "month: " << a.date.month << endl;
    cout << "day: " << a.date.day << endl;
    cout << "________________________ " << endl;

}

void OutputAll(zoo* A, int n)
{
    for (int i = 0; i < n; i++)
    {
        Output(A[i]);
    }
}

void SortDate(zoo* A, int n)
{
    for (int i = 0; i < n; ++i)
    {
        int small = i;

        for (int j = i + 1; j < n; ++j)
        {
            if (A[j].date.year < A[small].date.year|| A[j].date.year < A[small].date.year&& A[j].date.month < A[small].date.month|| A[j].date.year < A[small].date.year && A[j].date.month < A[small].date.month &&A[j].date.day < A[small].date.day)
                small = j;
        }
        swap(A[i], A[small]);
    }
    for (int i = 0; i < n; ++i)
        Output(A[i]);
}

void LightWeight(zoo* A, int n)
{

    int old = 0;
    for (int i = 0; i < n; ++i)
    {
        if (A[i].age>=A[old].age) 
                old = i;     
    }
    int lightweight=0;
    for (int j = 0; j < n; ++j)
    {
        if(A[j].age == A[old].age&&A[j].weight<=A[lightweight].weight)
            Output(A[j]);
    }
}