/*
   ID: autinho1
   TASK: evolution
   LANG: C++
   */

   // Bronze03.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
   //

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <map>

using namespace std;

map<string, int> dict;
int p[300];

string cows[26][26];
int ca[26];

int N;

int Find(string str) {
	int i = -1;
	
	for (map<string, int>::iterator it = dict.begin(); it != dict.end(); it++) {
		i++;
		if ((*it).first == str) {
			return i;
		}
	}
	return -1;
}

int GetP(string str) {
	int i = Find(str);
	if (i == -1) {
		return -1;
	}
	while ((p[i] != 0)&&(p[i]!=-1)) {
		i = p[i];
	}
	return i;
}

bool IsParent(int j, int k) {
	if (p[k] == j) {
		return true;
	}

	//while(p[k])
	return false;
}

int main()
{
	ifstream fin("7.in");
	ofstream fout("evolution.out");

	fin >> N;
	int a;
	string str;
	int maxA = 0;

	for (int i = 0; i < N; i++) {
		fin >> ca[i];
		maxA = max(maxA, ca[i]);
		for (int j = 0; j < ca[i]; j++) {
			fin >> str;
			dict[str]++;

			cows[i][j]=str;
		}
	}

	int maxV, maxI;
	string temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < ca[i]-1; j++) {
			maxV = -1;
			for (int k = j; k < ca[i]; k++) {
				if (dict[cows[i][k]] > maxV) {
					maxV = dict[cows[i][k]];
					maxI = k;
				}
			}
			if (maxI != j) {
				temp = cows[i][j];
				cows[i][j] = cows[i][maxI];
				cows[i][maxI] = temp;
			}
		}
	}
	
	int index, ji, ki, jc, kc;
	for (int i = 0; i < N; i++) {
		if (ca[i] == 0) {
			continue;
		}
		else if (ca[i] == 1) {
			index = Find(cows[i][0]);
			p[index] = 0;
		}
		else {
			for (int j = 0; j < ca[i]-1; j++) {
				ji = Find(cows[i][j]);
				jc = dict[cows[i][j]];
				for (int k = j + 1; k < ca[i]; k++) {
					ki = Find(cows[i][k]);
					kc = dict[cows[i][j]];
					if (jc == kc) {
						continue;
					}
					else if (jc > kc) {
						if (p[ki] == -1) {
							p[ki] = ji;
						}
						else {

						}
					}
				}
			}
		}
	}

	for (int i = 0; i < dict.size(); i++) {
		p[i] = -1;
	}


	fout << "yes\n";

	fout.close();

	return 0;
}

