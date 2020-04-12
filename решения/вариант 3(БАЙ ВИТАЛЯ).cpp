#include <iostream>
using namespace std;
struct DATA {
	int year;
	int month;
	int day;
};
struct shop {
	DATA date;
	char shopName[15];
	int stuff;
	double income[3];
};
void inputArrayOfShops(shop* shops, short n);
void outputArrayOfShops(shop* shops, short n);
void sortByStuff(shop* shops, short n);
void checkIncome(shop* shops, int n);

int main() {
	short n;
	cout << "Input number of shops: ";
	cin >> n;
	shop* shops = new shop[n];
	inputArrayOfShops(shops, n);
	cout << "sorted:" << endl;
	cout << endl;
	cout << endl;
	sortByStuff(shops, n);
	outputArrayOfShops(shops, n);
	checkIncome(shops, n);
	system("pause");
	return 0;
}

void inputArrayOfShops(shop* shops, short n) {
	for (int i = 0; i < n; i++) {
		cout << "year: ";
		cin >> shops[i].date.year;
		cout << "month: ";
		cin >> shops[i].date.month;
		cout << "day: ";
		cin >> shops[i].date.day;
		cout << "Name of the shop: ";
		cin >> shops[i].shopName;
		for (int k = 0; k < 3; k++) {
			cout << k + 1 << " month income:";
			cin >> shops[i].income[k];
		}
		cout << "number of staff: ";
		cin >> shops[i].stuff;
	}
}

void outputArrayOfShops(shop* shops, short n) {
	for (int i = 0; i < n; i++) {
		cout << "____________________________________"<<endl;
		cout << "name of the shop:" << shops[i].shopName << endl;
		cout << "number of stuff:" << shops[i].stuff<< endl;
		cout << "date:" << shops[i].date.year<<"."<<shops[i].date.month<<"."<<shops[i].date.day<<endl;
		for (int k = 0; k < 3; k++) {
			cout << i + 1 << " month income:" << shops[i].income[k]<<endl;
		}
		cout << endl;
	}
}

void sortByStuff(shop* shops, short n) {
	bool swapped = false;
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			if (shops[j].stuff < shops[j - 1].stuff) {
				swap(shops[j], shops[j - 1]);
				swapped = true;
			}
		}
		if (!swapped) {
			break;
		}
	}
}
void checkIncome(shop* shops,int n) {
	double k;
	bool flag = false;
	cout << "enter k:";
	cin >> k;
	for (int i = 0; i < n; i++) {
		double sum = 0;
		for (int k = 0; k < 3; k++) {
			sum += shops[i].income[k];
		}
		if (sum > k) {
			flag = true;
			cout << shops[i].shopName << " has an income greater than " << k<<endl;
		}
	}
	if (flag == false) {
		cout << "we don't have any store with the income greater than " << k<<endl;
	}
	
}