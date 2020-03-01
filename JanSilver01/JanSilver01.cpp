// JanSilver01.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int N;

vector<int> path[100010];

int c[100010];
map<int,int> f;
int fi;

int maxC;

void fill(int i, int s) {
	int index = 1;
	for (int j = 0; j < path[i].size(); j++) {
		if (path[i][j] == s) {
			continue;
		}
		while (f[index] != 0) {
			index++;
		}
		c[path[i][j]] = index;
		f[index] = 1;
	}
	maxC = max(maxC, index);
	for (int j = 0; j < path[i].size(); j++) {
		if (path[i][j] == s) {
			continue;
		}
		f.clear();
		f[c[i]] = 1;
		f[c[path[i][j]]] = 1;
		fill(path[i][j], i);
	}
}


int main()
{
	ifstream fin("planting.in");
	ofstream fout("planting.out");
	
	fin >> N;
	int a, b;
	for (int i = 0; i < N-1; i++) {
		fin >> a >> b;
		path[a].push_back(b);
		path[b].push_back(a);
	}

	c[1] = 1;
	f[1] = 1;
	fi = 1;
	maxC = 1;
	fill(1, -1);

	fout << maxC << endl;

	fout.close();

	return 0;
}

