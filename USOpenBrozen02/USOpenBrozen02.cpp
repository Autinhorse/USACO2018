/*
   ID: autinho1
   TASK: milkorder
   LANG: C++
   */

   // Bronze01.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
   //

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

vector<int> nodes[105];
int c[105];

int proc[105];
int order[105];


bool RemovePath(int x) {
	if (c[x] != 0) {
		return false;
	}

	if (nodes[x].size() == 0) {
		return false;
	}

	for (int i = 0; i < nodes[x].size(); i++) {
		c[nodes[x][i]]--;
		RemovePath(nodes[x][i]);
		c[x] = -1;
	}
	
	return true;
}

int main()
{
	ifstream fin("factory.in");
	ofstream fout("factory.out");

	fin >> N;
	int a, b;
	for (int i = 0; i < N-1; i++) {
		fin >> a >> b;
		nodes[a].push_back( b );
		c[b]++;
	}


	int countV = 0;
	int index = -1;
	bool deleted = false;
	do {
		for (int i = 1; i <= N; i++) {
			if (c[i] == -1) {
				continue;
			}
			deleted != RemovePath(i);
		}

		deleted = false;
	} while (deleted);

	for (int i = 1; i <= N; i++) {
		if (c[i] == 0) {
			countV++;
			index = i;
		}
	}
	
	
	if (countV == 1) {
		fout << index << endl;
	}
	else {
		fout << -1 << endl;
	}

	fout.close();

	return 0;
}


/*

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

int N, M, K;

int proc[105];
int order[105];

int main()
{
	ifstream fin("milkorder.in");
	ofstream fout("milkorder.out");

	fin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		fin >> order[i];
	}

	int a, b;
	for (int i = 0; i < K; i++) {
		fin >> a >> b;
		proc[b] = a;
	}

	int pi=0;
	int pc = 1;
	bool found;
	for (int i = 0; i < M; i++) {
		found = false;
		for (int j = pc; j <= N; j++) {
			if (order[i] == proc[j]) {
				found = true;
				pc = j;
				break;
			}
		}
		if (found) {
			if (pi == i) {
				pi++;
			}
			else {
				for (int j = i - 1; j >= pi; j--) {
					for (int k = pc - 1; k > 0; k--) {
						if (proc[k] == 0) {
							proc[k] = order[j];
							pc = k;
							break;
						}
					}
				}
				pi = i + 1;
			}
		}
	}

	int c=-1;
	for (int i = 1; i <= N; i++) {
		if (proc[i] == 0) {
			c = i;
			break;
		}
	}

	fout << c << endl;

	fout.close();

	return 0;
}

*/