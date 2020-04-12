#include <iostream>
using namespace std;
struct DATA {
	int day;
	int month;
	int year;
};
struct Photo {
public:
	Photo();

	DATA data;
	int size;
	char F[15];
	char N;
	char O;
};
Photo::Photo() {
	cout << "День: ";
	cin >> data.day;
	cout << "Месяц: ";
	cin >> data.month;
	cout << "Год: ";
	cin >> data.year;
	cout << "Размере фото в МБ: ";
	cin >> size;
	cout << "Фамилия и инициалы :";
	cin >> F;
	cin >> N;
	cin >> O;
	
}
void sortbyFam(Photo* pt, int n) //(s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			for (int k = 0; k < 15; k++) {
				if (pt[j].F[k] != pt[j + 1].F[k]) {
					if (pt[j].F[k] == ' ')break;
					if (pt[j].F[k] > pt[j + 1].F[k]) {
						swap(pt[j], pt[j + 1]);
					}
					break;
				}
			}
		}
	}
}
void output(Photo* pt, int n) {
	cout << "Дата: ";
	for (int i = 0; i < n; i++) {
		cout << pt[i].data.day << "." <<pt[i].data.month << "." <<pt[i].data.year << "  ";
	}
	cout << endl;
	cout << "Размер в МБ: ";
	for (int i = 0; i < n; i++) {
		cout << pt[i].size << "  ";
	}
	cout << endl;
	cout << "ФИО : ";
	for (int i = 0; i < n; i++) {
		cout << pt[i].F << " " << pt[i].N << "." << pt[i].O << "  ";
	}
	cout << endl;
}
void maxSIZE(Photo* pt, int n) {
	int y_chek;
	cout << "Введите год для нахождения снимка - ";
	cin >> y_chek;
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (pt[i].data.year == y_chek) {
			if (pt[i].size > max) {
				max = pt[i].size;
			}
		}
	}
	cout << "Самый большой снимок в " << y_chek << " году : "<<endl;
	for (int i = 0; i < n; i++) {
		if (pt[i].data.year == y_chek && max == pt[i].size) {
			cout <<"Дата: "<< pt[i].data.day << "." << pt[i].data.month << "." << pt[i].data.year << endl;
			cout <<"Размер:"<< pt[i].size << endl;
			cout <<"ФИО :"<< pt[i].F << " " << pt[i].N << "." << pt[i].O << endl;
		}
	}
}
int main() {
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Введите кол-во фотографий: ";
	cin >> n;
	Photo* pt = new Photo[n];
	output(pt, n);
	sortbyFam(pt, n);
	output(pt, n);
	maxSIZE(pt, n);
	return 0;
}