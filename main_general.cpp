#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <ctime>

//#define Randmod(x) rand()%x

using namespace std;

int guess(unsigned int s, bool st);
template <typename T> getData(T target, bool type) {   //type: target�����͡�0 = ����ֵ(bool), 1 = unsigned int�Ǹ�����
	while (1) {
		cin >> target;
		if (!cin) {
			if (type == 0) {
				cout << "������0��1" << endl;
			} else {
				cout << "������Ǹ�����" << endl;
			}
			cin.clear();
			cin.sync();
		} else {
			return target;
		}
	}
	return 0;
}
int main() {
	int total = 0;
	int sum = 0;
	unsigned int dian = 0, trial = 0, peach = 0;
	bool baodi = 0;
	srand((unsigned)time(NULL));
	cout << "��֮ǰ��С���׻��Ǵ󱣵�? 1=С,0=��" << endl;
	baodi = getData<bool>(baodi, 0);
	cin.sync();
	cout << "�����ѵ����:" << endl;
	dian = getData<unsigned int>(dian, 1);
	while (1) {
		cin.sync();
		if (baodi == 1 && dian >= 90) {
			cout << "���Ѿ���С�����ˣ�Ϊɶ������90����?(�s�F����)�s��ߩ���,����������~" <<endl;
			dian = getData<unsigned int>(dian, 1);
		} else break;
	}
	cin.sync();
	cout << "���뻹Ҫ��ȡ�Ĵ���:" << endl;
	trial = getData<unsigned int>(trial, 1);
	cin.sync();
	cout << "��������UP�Ĵ���:" << endl;
	peach = getData<unsigned int>(peach, 1);
	cin.sync();
	/*cout << trial << endl;
	cout << dian << endl;
	system("pause");*/
	for (long times = 0; times < 100000; times++) {
		unsigned int favor = 0;
		unsigned int big = dian;
		unsigned int small = dian;
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
	double percent = sum / 1000.0;
	cout.setf(ios::fixed);
	cout << "����" << peach << "�����ϴ���:" << sum << ",����:" << fixed << setprecision(3) << percent << "%" << endl;
	cout << "�ܴ���:" << total << endl;
	cin.sync();
	cin.get();
	return 0;
}
int guess(unsigned int s, bool st) {
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
