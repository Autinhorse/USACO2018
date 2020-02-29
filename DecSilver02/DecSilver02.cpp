// DecSilver02.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;

struct Cow {
	int s;
	int t;
	int a;

	bool operator < (const Cow&  c)const {
		return s < c.s;
	}
}cows[100010];

int N;

bool Comp(Cow c1, Cow c2) {
	if (c1.a == c2.a) {
		return c1.s < c2.s;
	}
	return c1.a < c2.a;
}

set<Cow> waiting;

int main()
{
	ifstream fin("convention2.in");
	ofstream fout("convention2.out");

	fin >> N;
	int maxT = 0;
	int minT = 999999;
	for (int i = 0; i < N; i++) {
		cows[i].s= i;
		fin >> cows[i].a >> cows[i].t;
		maxT = max(maxT, cows[i].t);
		minT = min(minT, cows[i].t);
	}
	sort(cows, cows + N, Comp);

	int index = 0;
	int maxW = 0;
	int ts, te;
	int curT;
	set<Cow>::iterator it;
	while ((waiting.size() > 0) || (index < N)) {
		waiting.insert(cows[index]);
		curT = cows[index].a;
		index++;
		
		while (waiting.size() > 0) {
			it = waiting.begin();
			ts = (*it).a;
			if (ts < curT) {
				maxW = max(maxW, curT - ts);
				curT += (*it).t;
			}
			else {
				curT = ts + (*it).t;
			}
			while (index < N) {
				if (cows[index].a <= curT) {
					waiting.insert(cows[index]);
					index++;
				}
				else {
					break;
				}
			}
			waiting.erase(it);
		}
	}
	
	fout << maxW << endl;

	fout.close();
	return 0;
}

