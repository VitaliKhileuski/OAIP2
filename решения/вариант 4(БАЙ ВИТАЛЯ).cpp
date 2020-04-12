/*
1. Описать структуру  с именем DATA,содержащую следующие поля:
-год
-месяц
-день
Описать структуру с именем Wedding:
-Дата свадьбы(DATA)
-Фамилии молодоженов
-количество гостей
-денежный эквивалент всех подарков
2.Реализовать следующие функции:
1)ввод с клавиатуры данных в массив,состоящих из n элементов типа wedding(n вводится с клавиатуры,память под массив выделять динамически)
2)функция по выявлению у кого в среднем самые щедрые гости
3)сортировка челиqов по дате свадьбы 
*/
#include <iostream>
using namespace std;
struct DATA {
	int year;
	int month;
	int day;
};
struct wedding {
	DATA date;
	char name1[20];
	char name2[20];
	int guests;
	double money;
};
void inputArrayOfWeddings(wedding* shops, short n);
void outputArrayOfWeddings(wedding* shops, short n);
void sortByDate(wedding* Wedding, short n);
void checkMoney(wedding* Wedding, int n);

int main() {
	short n;
	cout << "Input number of weddings: ";
	cin >> n;
	wedding* Wedding = new wedding[n];
	inputArrayOfWeddings(Wedding, n);
	cout << "sorted:" << endl;
	cout << endl;
	cout << endl;
	sortByDate(Wedding, n);
	outputArrayOfWeddings(Wedding, n);
	checkMoney(Wedding, n);
	system("pause");
	return 0;
}

void inputArrayOfWeddings(wedding* Wedding, short n) {
	for (int i = 0; i < n; i++) {
		cout << "year: ";
		cin >> Wedding[i].date.year;
		cout << "month: ";
		cin >> Wedding[i].date.month;
		cout << "day: ";
		cin >> Wedding[i].date.day;
		cout << "Name of the first newlywed(lol shto??): ";
		cin >> Wedding[i].name1;
		cout << "Name of the second newlywed(lol shto??): ";
		cin >> Wedding[i].name2;
		cout << "number of guests: ";
		cin >> Wedding[i].guests;
		cout << "amount of money:";
		cin >> Wedding[i].money;
	}
}

void outputArrayOfWeddings(wedding* Wedding, short n) {
	for (int i = 0; i < n; i++) {
		cout << "____________________________________" << endl;
		cout << "name of the first newlywed:" << Wedding[i].name1 << endl;
		cout << "name of the second newlywed:" << Wedding[i].name2 << endl;
		cout << "number of guests:" << Wedding[i].guests << endl;
		cout << "date:" << Wedding[i].date.year << "." << Wedding[i].date.month << "." << Wedding[i].date.day << endl;
		cout << "amount of money:" << Wedding[i].money;
		cout << endl;
	}
}

void sortByDate(wedding* Wedding, short n) {
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (Wedding[i].date.year < Wedding[i + 1].date.year) {
				swap(Wedding[i], Wedding[i + 1]);
			}
			if (Wedding[i].date.year == Wedding[i + 1].date.year) {
				if (Wedding[i].date.month < Wedding[i + 1].date.month) {
					swap(Wedding[i], Wedding[i + 1]);
				}
				if (Wedding[i].date.month == Wedding[i + 1].date.month) {
					if (Wedding[i].date.day < Wedding[i + 1].date.day) {
						swap(Wedding[i], Wedding[i + 1]);
					}
				}
			}
		}
	}
}
void checkMoney(wedding* Wedding, int n) {
	double average = 0;
	int index=0;
	for (int i = 0; i < n; i++) {
		if (Wedding[i].money / Wedding[i].guests > average) {
			average = Wedding[i].money / Wedding[i].guests;
			index = i;
		}
	}
	cout << Wedding[index].name1<<" and " << Wedding[index].name2<<" have the most generous guests"<<endl;
}