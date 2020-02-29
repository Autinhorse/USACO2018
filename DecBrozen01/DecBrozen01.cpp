// DecBrozen01.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int buckets[3];
int milk[3];


int main()
{
	ifstream fin("mixmilk.in");
	ofstream fout("mixmilk.out");

	for (int i = 0; i < 3; i++) {
		fin >> buckets[i] >> milk[i];
	}

	for (int i = 0; i < 100; i++) {
		if (i % 3 == 0) {
			milk[1] = milk[0] + milk[1];
			if (milk[1] > buckets[1]) {
				milk[0] = milk[1] - buckets[1];
				milk[1] = buckets[1];
			}
			else {
				milk[0] = 0;
			}
		}
		else if (i % 3 == 1) {
			milk[2] = milk[2] + milk[1];
			if (milk[2] > buckets[2]) {
				milk[1] = milk[2] - buckets[2];
				milk[2] = buckets[2];
			}
			else {
				milk[1] = 0;
			}
		}
		else {
			milk[0] = milk[0] + milk[2];
			if (milk[0] > buckets[0]) {
				milk[2] = milk[0] - buckets[0];
				milk[0] = buckets[0];
			}
			else {
				milk[2] = 0;
			}
		}
	}

	fout << milk[0] << endl;
	fout << milk[1] << endl;
	fout << milk[2] << endl;

	fout.close();
	return 0;
}


