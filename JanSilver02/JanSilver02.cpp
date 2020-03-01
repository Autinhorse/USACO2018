// JanSilver02.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;
struct Pos {
    int x;
    int y;
};
int N;
char m[1000][1000];
int d[1000][1000];

vector<Pos> proc;

void CheckPos(int x, int y) {
    if ((x < 0) || (x >= N) || (y < 0) || (y >= N)) {
        return;
    }

    if (m[y][x] != '.') {
        Pos pos;
        pos.x = x;
        pos.y = y;
        proc.push_back(pos);

        m[y][x] = '.';
    }
}

int CheckSide(int x, int y) {
	if ((x < 0) || (x >= N) || (y < 0) || (y >= N)) {
		return 0;
	}
    if (d[y][x] != 0) {
        return 1;
    }
    return 0;
}



int main()
{
    ifstream fin("perimeter.in");
    ofstream fout("perimeter.out");

    fin >> N;

    for (int i = 0; i < N; i++) {
        for (int j=0;j<N;j++)
        {
            fin >> m[i][j];
        }
    }

    int maxS = 0;
    int minL = 999999999;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		{
            if (m[i][j] != '.') {
                proc.clear();
                Pos pos;
                pos.x = j;
                pos.y = i;
                int pi = 0;
                m[i][j] = '.';
                proc.push_back(pos);
                while (proc.size() > pi) {
                    pos = proc[pi];
                    pi++;
                    CheckPos(pos.x+1, pos.y);
                    CheckPos(pos.x-1, pos.y);
                    CheckPos(pos.x, pos.y+1);
                    CheckPos(pos.x, pos.y-1);
                }
                for (int i = 0; i < proc.size(); i++) {
                    d[proc[i].y][proc[i].x] = proc.size();
                }
				int l = 0;
				int lt;
				for (int i = 0; i < proc.size(); i++) {
					lt = 4;
					lt -= CheckSide(proc[i].x + 1, proc[i].y);
					lt -= CheckSide(proc[i].x - 1, proc[i].y);
					lt -= CheckSide(proc[i].x, proc[i].y + 1);
					lt -= CheckSide(proc[i].x, proc[i].y - 1);
					l += lt;
				}
				if (proc.size() > maxS) {
                    maxS = proc.size();
                    minL = l;
                }
                else if (proc.size() == maxS) {
                    minL = min(minL, l);
                }
            }
		}
	}


    fout << maxS << " " << minL << endl;

    fout.close();

    return 0;
}


