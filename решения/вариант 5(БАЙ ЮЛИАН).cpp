#include <iostream>
using namespace std;
struct DATA {
	int day;
	int month;
	int year;
};
struct Bicycle {
public:
	Bicycle();
	char marka[10];
	int cost;
	DATA data;
	char F[15];
	char N;
	char O;
};
Bicycle::Bicycle(){
	cout << "Марка велосипеда: ";
	cin >> marka;
	cout << "Цена: ";
	cin >> cost;
	cout << "Дата изготовления: ";
	cin >> data.day;
	cin >> data.month;
	cin >> data.year;
	cout << "Фамилия и инициалы :";
	cin >> F;
	cin >> N;
	cin >> O;
}
void sortbyData(Bicycle* vel, int n) {
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (vel[i].data.year < vel[i + 1].data.year) {
				swap(vel[i], vel[i + 1]);
			}
			if (vel[i].data.year == vel[i + 1].data.year) {
				if (vel[i].data.month < vel[i + 1].data.month) {
					swap(vel[i], vel[i + 1]);
				}
				if (vel[i].data.month == vel[i + 1].data.month) {
					if (vel[i].data.day < vel[i + 1].data.day) {
						swap(vel[i], vel[i + 1]);
					}
				}
			}
		}
	}
}
void output(Bicycle* vel, int n) {
	cout << "Марка: ";
	for (int i = 0; i < n; i++) {
		cout << vel[i].marka << "  ";
	}
	cout << endl;
	cout << "Цена: ";
	for (int i = 0; i < n; i++) {
		cout << vel[i].cost << "  ";
	}
	cout << endl;
	cout << "Дата изготовления: ";
	for (int i = 0; i < n; i++) {
		cout << vel[i].data.day << "."<< vel[i].data.month<<"."<< vel[i].data.year<<"  ";
	}
	cout << endl;
	cout << "ФИО: ";
	for (int i = 0; i < n; i++) {
		cout << vel[i].F << " " << vel[i].N<< "." << vel[i].O << "  ";
	}
	cout << endl;
}
void popular(Bicycle* vel, int n) {
	int max = 0;
	int s = 0;
	int ch;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			bool flag = true;
			for (int j = 0; j < 10; j++) {
				if (vel[k].marka[j] != vel[i].marka[j] ) {
					flag = false;
					break;
				}
			}
			if (flag)s++;
		}
		if (s > max) {
			max = s;
			ch = k;
		}
	}
	cout << "Самая популярная модель велосипеда - ";
	cout << vel[ch].marka<<endl;
	cout << "Её владельцы: ";
	for (int i = 0; i < n; i++) {
		bool flag = true;
		for (int j = 0; j < 10; j++) {
			if (vel[i].marka[j] != vel[ch].marka[j]) {
				flag = false;
				break;
			}
		}
		if (flag)cout << vel[i].F << " " << vel[i].N << "." << vel[i].O << "." << "  ";
	}
}
int main() {
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Введите кол-во велосипедов: ";
	cin >> n;
	Bicycle* vel = new Bicycle[n];
	output(vel, n);
	sortbyData(vel, n);
	output(vel, n);
	popular(vel, n);
	return 0;
}