// DecBronze02.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int N;
int t[1005];

int main()
{
	ifstream fin("blist.in");
	ofstream fout("blist.out");

	fin >> N;
	int maxV = 0;
	int a, b, c;
	for (int i = 0; i < N; i++) {
		fin >> a >> b >> c;
		for (int j = a; j <= b; j++) {
			t[j]+=c;
			maxV = max(maxV, t[j]);
		}
	}

	fout << maxV << endl;

	fout.close();
	return 0;
}

