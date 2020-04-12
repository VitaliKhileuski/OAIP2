#include <iostream>
using namespace std;
struct DATA {
	int day;
	int month;
	int year;
};
struct Kuznica {
public:
	Kuznica();

	DATA data;
	char F[15];
	char N;
	char O;
	long long tel;
	int zarp[3];
};
Kuznica::Kuznica() {
	cout << "Дата: ";
	cin >> data.day;
	cin >> data.month;
	cin >> data.year;
	cout << "Фамилия и инициалы начальника смены :";
	cin >> F;
	cin >> N;
	cin >> O;
	cout << "Номер телефона:";
	cin >> tel;
	cout << "Заработная плата за 1 месяц: ";
	cin >> zarp[0];
	cout << "Заработная плата за 2 месяц: ";
	cin >> zarp[1];
	cout << "Заработная плата за 3 месяц: ";
	cin >> zarp[2];
}
void sortbyData(Kuznica* kuz, int n) {
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (kuz[i].data.year < kuz[i + 1].data.year) {
				swap(kuz[i], kuz[i + 1]);
			}
			if (kuz[i].data.year == kuz[i + 1].data.year) {
				if (kuz[i].data.month < kuz[i + 1].data.month) {
					swap(kuz[i], kuz[i + 1]);
				}
				if (kuz[i].data.month == kuz[i + 1].data.month) {
					if (kuz[i].data.day < kuz[i + 1].data.day) {
						swap(kuz[i], kuz[i + 1]);
					}
				}
			}
		}
	}
}
void output(Kuznica* kuz, int n) {
	cout << "Дата смены: ";
	for (int i = 0; i < n; i++) {
		cout << kuz[i].data.day << "." << kuz[i].data.month << "." << kuz[i].data.year << "  ";
	}
	cout << endl;
	cout << "ФИО начальника смены: ";
	for (int i = 0; i < n; i++) {
		cout << kuz[i].F << " " << kuz[i].N << "." << kuz[i].O << "  ";
	}
	cout << endl;
	cout << "Номер телефона: ";
	for (int i = 0; i < n; i++) {
		cout << kuz[i].tel << "  ";
	}
	cout << endl;
	for (int j = 0; j < 3; j++) {
		cout << "Зарплата за " << j + 1 << " месяц: ";
		for (int i = 0; i < n; i++) {
			cout << kuz[i].zarp[j] << "  ";
		}
		cout << endl;
	}
}
void zarpl(Kuznica* kuz, int n, double sum) {
	cout << "Средняя зарплата меньше введенной суммы у : ";
	bool flag = true;
	for (int i = 0; i < n; i++) {
		double sred = (kuz[i].zarp[0] + kuz[i].zarp[1] + kuz[i].zarp[2]) / 3;
		if (sred < sum) {
			cout << kuz[i].F << " " << kuz[i].N << "." << kuz[i].O << ".  ";
			flag = false;
		}
	}
	if (flag)cout << "Таких работников нет!";
}
int main() {
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Введите кол-во смен: ";
	cin >> n;
	Kuznica* kuz = new Kuznica[n];
	output(kuz, n);
	sortbyData(kuz, n);
	output(kuz, n);
	double sum;
	cout << "Введите сумму: ";
	cin >> sum;
	zarpl(kuz, n, sum);
	return 0;
}