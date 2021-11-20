#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <graphics.h>
#include <iomanip>

using namespace std;

int guess(unsigned int s, bool st);
int main() {
	int total = 0;
	int sum = 0;
	unsigned int dian = 0, trial = 0, peach = 0;
	bool baodi = 0;
	int width = 1440, height = 900; //��ͼ���ڳ���
	double percent = 0;
	srand((unsigned)time(NULL));
	cout.setf(ios::fixed);
	initgraph(width, height, 0);
	setcaption("���и�������ͼ��");
	setbkcolor(WHITE);
	setcolor(RED); //Ĭ��Ϊ��ɫ
	/*cout << "��������UP�Ĵ���:" << endl;
	while (1) {
		cin >> peach;
		if (!cin) {
			cout << "������������" << endl;
			cin.clear();
			cin.sync();
		} else {
			break;
		}
	}*/
	for (peach = 1; peach <= 3; peach++) {
		switch(peach){
			case 1: setcolor(RED); cout<<"��ǰ���:����1�μ����ϸ���ͼ����ɫ:��"; break;
			case 2: setcolor(GREEN); cout<<"��ǰ���:����1�μ����ϸ���ͼ����ɫ:��"; break;
			case 3: setcolor(BLUE); cout<<"��ǰ���:����1�μ����ϸ���ͼ����ɫ:��"; break;
		}
		for (trial = 0; trial <= 180; trial++) {
			for (long times = 0; times < 100000; times++) {
				int favor = 0;
				unsigned int big = dian;
				unsigned int smal = dian;
				bool state = baodi;
				while (big <= dian + trial) {
					smal++;
					big++;
					//cout<<smal<<" "<<big<<endl;
					int res = guess(smal, state);
					//cout<<res<<endl;
					if (res == 2) {
						state = false;
						favor++;
						smal = 0;
					} else if (res == 1) {
						state = true;
						smal = 0;
					} //else continue;
				}
				if (favor >= peach) {
					sum++;
				}
				//cout << "���д�����" << favor << endl;
				total = total + favor;
			}
			percent = sum / 1000.0;
			cout << total << endl;
			cout << fixed << setprecision(3) << trial << " " << percent / 100.0 << endl;
			circle(trial * width / 180, (height - (percent / 100.0 * height)), 3);
			delay_ms(0); //�������»�ͼ����
			sum = 0;
			total = 0;
		}
	}
	cin.sync();
	cin.get();
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
