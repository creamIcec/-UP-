#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <ctime>
#include "drawing.h"

//#define Randmod(x) rand()%x

using namespace std;
using namespace draw;
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
