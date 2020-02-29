// DecBronze03.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int tanks[2];

int buckets[2][11];

set<int> res;

void move(int n) {
	if (n == 4) {
		res.insert(tanks[0]);
		return;
	}

	if (n % 2 == 0) {
		for (int i = 0; i < 10; i++) {
			int v = buckets[0][i];
			tanks[0] -= v;
			tanks[1] += v;
			buckets[0][i] = -1;
			int j;
			for ( j = 0; j < 11; j++) {
				if (buckets[1][j] == -1) {
					break;
				}
			}
			buckets[1][j] = v;
			move(n+1);
			buckets[1][j] = -1;
			tanks[0] += v;
			tanks[1] -= v;
			buckets[0][i] = v;
		}
	}
	else {
		for (int i = 0; i < 11; i++) {
			int v = buckets[1][i];
			tanks[1] -= v;
			tanks[0] += v;
			buckets[1][i] = -1;
			int j;
			for (j = 0; j < 10; j++) {
				if (buckets[0][j] == -1) {
					break;
				}
			}
			buckets[0][j] = v;
			move(n+1);
			buckets[0][j] = -1;
			tanks[1] += v;
			tanks[0] -= v;
			buckets[1][i] = v;
		}
	}
}

int main()
{
	ifstream fin("backforth.in");
	ofstream fout("backforth.out");

	for (int i = 0; i < 10; i++) {
		fin >> buckets[0][i];
	}
	for (int i = 0; i < 10; i++) {
		fin >> buckets[1][i];
	}
	buckets[1][10] = -1;

	move(0);

	fout << res.size() << endl;

	fout.close();
	return 0;
}


