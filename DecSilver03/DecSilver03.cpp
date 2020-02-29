// DecSilver03.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
int d[105][10];

int f[105][10];

int proc[2000][3];
int pi, pe;

void InsertPos(int x, int y, int k) {
	if ((x == 6) && (y == 5)) {
		int test = 0;
		test++;
	}
	if ((x < 0) || (x >= 10) || (y < 0) || (y >= N)) {
		return;
	}
	
	if (f[y][x] == k) {
		proc[pe][0] = y;
		proc[pe][1] = x;
		proc[pe][2] = k;

		f[y][x] = 0;
		pe++;
	}
}

bool CleanD() {
	bool result = false;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			f[i][j] = d[i][j];
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			if (f[i][j] != 0) {
				pi = 0;
				proc[pi][0] = i;
				proc[pi][1] = j;
				proc[pi][2] = f[i][j];
				f[i][j] = 0;
				pe = 1;
				while (pi < pe) {
					InsertPos(proc[pi][1]+1, proc[pi][0], proc[pi][2]);
					InsertPos(proc[pi][1]-1, proc[pi][0], proc[pi][2]);
					InsertPos(proc[pi][1], proc[pi][0]+1, proc[pi][2]);
					InsertPos(proc[pi][1], proc[pi][0]-1, proc[pi][2]);
					pi++;
				}
				if (pe >= K) {
					for (int k = 0; k < pe; k++) {
						d[proc[k][0]][proc[k][1]] = 0;
					}

					result = true;
				}
			}
		}
	}

	if (result) {
		bool drop = false;
		do {
			drop = false;
			for (int j = 0; j < 10; j++) {
				for (int i = N - 1; i > 0; i--) {
					if (d[i][j] == 0) {
						d[i][j] = d[i - 1][j];
						d[i - 1][j] = 0;
						if (d[i][j] != 0) {
							drop = true;
						}
					}
				}
			}
			
		} while (drop);
	}

	return result;
}

int main()
{
	ifstream fin("mooyomooyo.in");
	ofstream fout("mooyomooyo.out");

	fin >> N >> K;
	char ch;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			fin >> ch;
			d[i][j] = ch-'0';
		}
	}

	while (CleanD());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			fout << d[i][j];
		}
		fout << endl;
	}

	fout.close();

	return 0;
}

