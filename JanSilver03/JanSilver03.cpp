// JanSilver03.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Peak {
    int x;
    int y;

    bool operator < (const Peak& p) const {
        return x < p.x;
    }
} peaks[100010];

int N;

vector<Peak> results;

int main()
{
    ifstream fin("mountains.in");
    ofstream fout("mountains.out");

    fin >> N;
    for (int i = 0; i < N; i++) {
        fin >> peaks[i].x >> peaks[i].y;
    }

    sort(peaks, peaks + N);

    int lastH = 0;
    int countV = 0;
    for (int i = 0; i < N; i++) {
        if (peaks[i].y == 0) {
            continue;
        }
        for (int j = results.size()-1; j >= 0; j--) {
			if (results[j].y >= peaks[i].y) {
				break;
			}
			if (peaks[i].y <= peaks[i].x - results[j].x) {
				break;
			}
			if (peaks[i].y - results[j].y >= peaks[i].x - results[j].x) {
                results.erase(results.begin() + j);
            }
        }
        results.push_back(peaks[i]);

        for (int j = i + 1; j < N; j++) {
            if (peaks[j].y >= peaks[i].y) {
                break;
            }
            if (peaks[j].x - peaks[i].x >= peaks[i].y) {
                break;
            }
            if (peaks[j].x - peaks[i].x <= peaks[i].y - peaks[j].y) {
                peaks[j].y = 0;
            }
        }
    }

    fout << results.size() << endl;

    fout.close();

    return 0;
}

