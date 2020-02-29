/*
   ID: autinho1
   TASK: buckets
   LANG: C++
   */

   // Bronze01.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
   //

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

int bx, by, rx, ry, lx, ly;

int proc[200][2];
int pi, pe;

char m[10][10];

bool SetPos(int y, int x, int n) {
	if ((x < 0) || (x > 9) || (y < 0) || (y > 9)) {
		return false;
	}

	if (m[y][x] == 'B') {
		return true;
	}

	if (m[y][x] != '.') {
		return false;
	}

	m[y][x] = n;

	proc[pe][0] = y;
	proc[pe][1] = x;

	pe++;

	return false;
}

int main()
{
	ifstream fin("buckets.in");
	ofstream fout("buckets.out");

	string temp;
	char ch;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			fin >> ch;
			m[i][j] = ch;
			if (ch == 'B') {
				bx = j;
				by = i;
			}
			if (ch == 'R') {
				rx = j;
				ry = i;
			}
			if (ch == 'L') {
				lx = j;
				ly = i;
			}
		}
	}

	pi = 0;
	pe = 1;
	proc[0][0] = ly;
	proc[0][1] = lx;

	m[ly][lx] = 0;

	int c;

	while (pi < pe) {
		c = m[proc[pi][0]][proc[pi][1]];
		if (SetPos(proc[pi][0] + 1, proc[pi][1], c + 1)) {
			break;
		}
		if (SetPos(proc[pi][0] - 1, proc[pi][1], c + 1)) {
			break;
		}
		if (SetPos(proc[pi][0], proc[pi][1] + 1, c + 1)) {
			break;
		}
		if (SetPos(proc[pi][0], proc[pi][1] - 1, c + 1)) {
			break;
		}
		pi++;
	}

	fout << c << endl;

	fout.close();

	return 0;
}

