#include <iostream>
#include <stdlib.h>
#include <ctime>

//#define Randmod(x) rand()%x

using namespace std;

int guess(int s, bool st);
int main() {
	int total = 0;
	int sum = 0;
	int dian = 0, trial = 0, peach = 0;
	bool baodi = 0;
	srand((unsigned)time(NULL));
	cout<<"��֮ǰ��С���׻��Ǵ󱣵�? 1/true =С,0/false =��"<<endl;
		while (1) {
			cin >> baodi;
			if (!cin >> baodi && baodi == 0) {
				cout << "������1/true��0/false" << endl;
				dian = 0;
				cin.sync();
			} else {
				break;
			}
		}
	cout << "�����ѵ����:" << endl;
	while (1) {
		cin >> dian;
		if (!cin >> dian && dian == 0) {
			cout << "������������" << endl;
			dian = 0;
			cin.sync();
		} else {
			break;
		}
	}
	cout << "���뻹Ҫ��ȡ�Ĵ���:" << endl;
	while (1) {
		cin >> trial;
		if (!cin >> trial && trial == 0) {
			cout << "������������" << endl;
			trial = 0;
			cin.sync();
		} else {
			break;
		}
	}
	cout << "��������UP�Ĵ���:" << endl;
	while (1) {
		cin >> peach;
		if (!cin >> peach && peach == 0) {
			cout << "������������" << endl;
			peach = 0;
			cin.sync();
		} else {
			break;
		}
	}
	/*cout << trial << endl;
	cout << dian << endl;
	system("pause");*/
	for (long int times = 0; times < 100000; times++) {
		int favor = 0;
		int big = dian;
		int small = dian;
		bool state = baodi;
		while (big <= dian + trial) {
			small++;
			big++;
			//cout<<small<<" "<<big<<endl;
			int res = guess(small, state);
			//cout<<res<<endl;
			if (res == 2) {
				state = false;
				favor++;
				small = 0;
			} else if (res == 1) {
				state = true;
				small = 0;
			} //else continue;
		}
		if (favor >= peach) {
			sum++;
		}
		//cout << "���д�����" << favor << endl;
		total = total + favor;
	}
	long double percent = 1.0 * (sum / 1000);
	cout << "����" << peach << "�����ϴ���:" << sum << ",����:" << percent << "%" << endl;
	cout << "�ܴ���:" << total << endl;
	system("pause");
	return 0;
}
int guess(int s, bool st) {
	long long ra = (double)rand() / RAND_MAX * 1000;
	//cout<<ra<<endl;
	//cout<<s<<" "<<st<<endl;
	if (s > 73) {
		if (s == 90) {
			if (st == true) {
				return 2;
			} else if (ra >= 1 && ra <= (500)) {
				return 2;
			} else {
				return 1;
			}
		} else if (ra >= 1 && (ra <= (6 + (s - 73) * 60))) {
			if (st == true) {
				return 2;
			} else if (ra >= 1 && ra <= ((6 + (s - 73) * 60) / 2)) {
				return 2;
			} else {
				return 1;
			}
		} else {
			return 3;
		}
	} else {
		if (ra >= 1 && ra <= 6) {
			if (st == true) {
				return 2;
			} else if (ra >= 1 && ra <= 3) {
				return 2;
			} else {
				return 1;
			}
		} else {
			return 3;
		}
	}
}
