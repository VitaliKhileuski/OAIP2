#include <iostream>
using namespace std;
struct DATA {
	int day;
	int month;
	int year;
};
struct Birthday {
public:
	Birthday();

	DATA data;
	char F[15];
	char N;
	char O;
	char podarok[10];
	int money;
};
Birthday::Birthday() {
	cout << "День: ";
	cin >> data.day;
	cout << "Месяц: ";
	cin >> data.month;
	cout << "Год: ";
	cin >> data.year;
	cout << "Фамилия и инициалы :";
	cin >> F;
	cin >> N;
	cin >> O;
	cout << "Подарок:";
	cin >> podarok;
	cout << "В денежном эквиваленте: ";
	cin >> money;
}
void sortbyData(Birthday* birth, int n)

{
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (birth[i].data.year < birth[i + 1].data.year) {
				swap(birth[i], birth[i + 1]);
			}
			if (birth[i].data.year == birth[i + 1].data.year) {
				if (birth[i].data.month < birth[i + 1].data.month) {
					swap(birth[i], birth[i + 1]);
				}
				if (birth[i].data.month == birth[i + 1].data.month) {
					if (birth[i].data.day < birth[i + 1].data.day) {
						swap(birth[i], birth[i + 1]);
					}
				}
			}
		}
	}
}
void output(Birthday* birth, int n) {
	cout << "Дата дня рождения: ";
	for (int i = 0; i < n; i++) {
		cout << birth[i].data.day << "." << birth[i].data.month << "." << birth[i].data.year << "  ";
	}
	cout << endl;
	cout << "ФИО : ";
	for (int i = 0; i < n; i++) {
		cout << birth[i].F << " " << birth[i].N << "." << birth[i].O << "  ";
	}
	cout << endl;
	cout << "Подарок: ";
	for (int i = 0; i < n; i++) {
		cout << birth[i].podarok << "  ";
	}
	cout << endl;
	cout << "В денежном эквиваленте: ";
	for (int i = 0; i < n; i++) {
		cout << birth[i].money << "  ";
	}
	cout << endl;
}
void skup(Birthday* birth, int n) {
	int ch=n-1;
	int min = birth[n - 1].money;
	for (int i = 0; i < n; i++) {
		if (birth[n - 1].data.year == birth[i].data.year && birth[n - 1].data.month == birth[n - 1].data.month && birth[n - 1].data.day == birth[n - 1].data.day) {
			if (min > birth[i].money) {
				min = birth[i].money;
				ch = i;
			}
		}
	}
	cout << "Самый скупой из самых взрослых: ";
	for (int i = 0; i < n; i++) {
		if (birth[n - 1].data.year == birth[i].data.year && birth[n - 1].data.month == birth[n - 1].data.month && birth[n - 1].data.day == birth[n - 1].data.day) {
			if (min == birth[i].money) {
				cout << birth[i].F << " " << birth[i].N << "." << birth[i].O << "  ";
			}
		}
	}
	
}
int main() {
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Введите кол-во друзей: ";
	cin >> n;
	Birthday* birth = new Birthday[n];
	output(birth, n);
	sortbyData(birth, n);
	output(birth, n);
	skup(birth, n);
	return 0;
}