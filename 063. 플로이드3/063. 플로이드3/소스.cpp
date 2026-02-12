#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

static int N, M;

int main() {
	cin >> N >> M;
	vector<vector<long>> D(N + 1, vector<long>(N+1, LONG_MAX));

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		D[s][e] = 1;
		D[e][s] = 1;
	}
	
	for (int k = 1; k < N + 1; k++) {
		for (int s = 1; s < N + 1; s++) {
			for (int e = 1; e < N + 1; e++) {
				if (D[s][k] != LONG_MAX && D[k][e] != LONG_MAX) {
					D[s][e] = min(D[s][e], D[s][k] + D[k][e]);
					D[e][s] = D[s][e];
				}	
			}
		}
	}

	int kavinMin = INT_MAX;
	int answer = 0;

	for (int i = 1; i < N + 1; i++) {
		int kavinNum = 0;
		for (int j = 1; j < N + 1; j++) {
			if (D[i][j] == LONG_MAX) continue;
			else kavinNum += D[i][j];
		}
		if (kavinNum < kavinMin) {
			answer = i;
			kavinMin = kavinNum;
		}
	}

	cout << answer;

}