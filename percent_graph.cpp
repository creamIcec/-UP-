#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <graphics.h>
#include <iomanip>
#include "drawing.h"

using namespace std;

int main() {
	int total = 0;
	int sum = 0;
	unsigned int dian = 0, trial = 0, peach = 0;
	bool baodi_c = 0;
	int baodi_w = 0;
	bool chou = 0;
	int width = 720, height = 450; //绘图窗口长宽
	bool output = false; //数值对显示状态
	double percent = 0;
	srand((unsigned)time(NULL));
	cout.setf(ios::fixed);
	initgraph(width, height, 0);
	setcaption("抽中概率曲线图像");
	setbkcolor(WHITE);
	setcolor(RED);
	cout << "你要抽什么? 0=角色池,1=武器池" << endl;
	chou = getData<bool>(chou, 0);
	cin.sync();
	cout << "输入想中UP的次数:" << endl;
	peach = getData<int>(peach, 1);
	cin.sync();
	cout << "是否显示数值对?" << endl;
	output = getData<bool>(output, 0);
	cin.sync();
	if (chou == 0) {
		for (trial = 1; trial <= 180; trial++) {
			for (long times = 0; times < 100000; times++) {
				int favor = 0;
				unsigned int big = dian;
				unsigned int smal = dian;
				bool state = baodi_c;
				while (big <= dian + trial) {
					smal++;
					big++;
					//cout<<smal<<" "<<big<<endl;
					int res = character::guess(smal, state);
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
				//cout << "抽中次数：" << favor << endl;
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
	} else {
		for (trial = 1; trial <= 240; trial++) {
			for (long times = 0; times < 100000; times++) {
				int favor = 0;
				unsigned int big = dian;
				unsigned int smal = dian;
				int state = baodi_w;
				while (big <= dian + trial) {
					smal++;
					big++;
					//cout<<smal<<" "<<big<<endl;
					int res = weapon::guess(smal, state);
					//cout<<res<<endl;
					if (res == 2) {
						state = 0;
						favor++;
						smal = 0;
					} else if (res == 1) {
						state++;
						smal = 0;
					} //else continue;
				}
				if (favor >= peach) {
					sum++;
				}
				//cout << "抽中次数：" << favor << endl;
				total = total + favor;
			}
			percent = sum / 1000.0;
			//cout << total << endl;
			if (output == true) {
				cout << fixed << setprecision(5) << trial << " " << percent / 100.0 << endl;
			}
			circle(trial * width / 240, (height - (percent / 100.0 * height)), 3);
			delay_ms(0);
			sum = 0;
			total = 0;
		}
	}
	cin.sync();
	cin.get();
	cin.get();
	return 0;
}
