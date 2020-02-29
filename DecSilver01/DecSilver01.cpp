// DecSilver01.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int N, M, C;
int cows[100010];

int s;
int lastV = 1000000000;

void Check(int l, int r) {
	if (l > r) {
		return;
	}
	int t = cows[0];
	int c = 1;
	int g = 1;
	int m = (l + r) / 2;
	for (int i = 1; i < N; i++) {
		if ((cows[i] - t > m)||(c==C)) {
			c = 0;
			t = cows[i];
			g++;
		}
		c++;
	}
	if (g > M) {
		Check(m + 1, r);
	}
	else {
		lastV = min(lastV, m);
		Check(l, m - 1);
	}
}

int main()
{
	ifstream fin("convention.in");
	ofstream fout("convention.out");

	fin >> N >> M >> C;

	for (int i = 0; i < N; i++) {
		fin >> cows[i];
	}
	sort(cows, cows + N);

	Check(1, 1000000000);

	fout << lastV << endl;

	fout.close();
	return 0;
}

