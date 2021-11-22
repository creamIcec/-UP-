#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <graphics.h>
#include <iomanip>
#include "drawing.h"

using namespace std;
using namespace draw;

int main() {
	int total = 0;
	int sum = 0;
	unsigned int dian = 0, trial = 0, peach = 0;
	bool baodi = 0;
	int width = 720, height = 450; //��ͼ���ڳ���
	bool output = false; //��ֵ����ʾ״̬
	double percent = 0;
	srand((unsigned)time(NULL));
	cout.setf(ios::fixed);
	initgraph(width, height, 0);
	setcaption("���и�������ͼ��");
	setbkcolor(WHITE);
	setcolor(RED);
	cout << "��������UP�Ĵ���:" << endl;
	peach = getData<int>(peach, 1);
	cin.sync();
	cout << "�Ƿ���ʾ��ֵ��?" << endl;
	output = getData<bool>(output, 0);
	cin.sync();
	for (trial = 1; trial <= 180; trial++) {
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
		//cout << total << endl;
		if (output == true) {
			cout << fixed << setprecision(5) << trial << " " << percent / 100.0 << endl;
		}
		circle(trial * width / 180, (height - (percent / 100.0 * height)), 3);
		delay_ms(0);
		sum = 0;
		total = 0;
	}
	cin.sync();
	cin.get();
	cin.get();
	return 0;
}
