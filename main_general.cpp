#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <ctime>
#include "drawing.h"

//#define Randmod(x) rand()%x

using namespace std;

int main() {
	int total = 0;
	int sum = 0;
	unsigned int dian = 0, trial = 0, peach = 0;
	bool chou = 0;
	bool baodi_c = 0;
	int baodi_w = 0;
	srand((unsigned)time(NULL));
	cout << "��Ҫ��ʲô? 0=��ɫ��,1=������" << endl;
	chou = getData<bool>(chou, 0);
	cin.sync();
	if (chou == 1) {
		cout << "��֮ǰ�Ἰ��?" << endl;
		baodi_w = getData<int>(baodi_w, 1);
		cin.sync();
		cout << "�����ѵ����:" << endl;
		dian = getData<unsigned int>(dian, 1);
		while (1) {
			cin.sync();
			if (baodi_w == 1 && dian >= 80) {
				cout << "���Ѿ���С�����ˣ�Ϊɶ������80����?(�s�F����)�s��ߩ���,����������~" << endl;
				dian = getData<unsigned int>(dian, 1);
			} else break;
		}
	} else {
		cout << "��֮ǰ��С���׻��Ǵ󱣵�? 1=С,0=��" << endl;
		baodi_c = getData<bool>(baodi_c, 0);
		cin.sync();
		cout << "�����ѵ����:" << endl;
		dian = getData<unsigned int>(dian, 1);
		while (1) {
			cin.sync();
			if (baodi_c == 1 && dian >= 90) {
				cout << "���Ѿ���С�����ˣ�Ϊɶ������90����?(�s�F����)�s��ߩ���,����������~" << endl;
				dian = getData<unsigned int>(dian, 1);
			} else break;
		}
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
	if (chou == 0) {
		for (long times = 0; times < 100000; times++) {
			unsigned int favor = 0;
			unsigned int big = dian;
			unsigned int small = dian;
			bool state = baodi_c;
			while (big <= dian + trial) {
				small++;
				big++;
				//cout<<small<<" "<<big<<endl;
				int res = character::guess(small, state);
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
	} else {
		for (long times = 0; times < 100000; times++) {
			unsigned int favor = 0;
			unsigned int big = dian;
			unsigned int small = dian;
			int state = baodi_w;
			while (big <= dian + trial) {
				small++;
				big++;
				//cout<<small<<" "<<big<<endl;
				int res = weapon::guess(small, state);
				//cout<<res<<endl;
				if (res == 2) {
					state = 0;
					favor++;
					small = 0;
				} else if (res == 1) {
					state++;
					small = 0;
				} //else continue;
			}
			if (favor >= peach) {
				sum++;
			}
			//cout << "���д�����" << favor << endl;
			total = total + favor;
			//cout << state << endl;
		}
	}
	double percent = sum / 1000.0;
	cout.setf(ios::fixed);
	cout << "����" << peach << "�����ϴ���:" << sum << ",����:" << fixed << setprecision(3) << percent << "%" << endl;
	cout << "�ܴ���:" << total << endl;
	cin.sync();
	cin.get();
	return 0;
}
