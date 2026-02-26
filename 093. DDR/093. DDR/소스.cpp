#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long D[100001][5][5];
int mp[5][5] = { {0, 2, 2, 2, 2},
				{2, 1, 3, 4, 3},
				{2, 3, 1, 3, 4},
				{2, 4, 3, 1, 3},
				{2, 3, 4, 3, 1} };


int main() {
	int n = 0; int s = 1;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 100001; k++) {
				D[k][i][j] = 400000;
			}
		}
	}
	
	D[0][0][0] = 0;
	

	while (true) {
		cin >> n;
		if (n == 0) break;

		//오른발이 n인 자리에 위치하게되는 경우
		for (int i = 0; i <= 4; i++) { //왼발의 위치(어디든 상관 없음)
			if (n == i) continue;
			for (int j = 0; j <= 4; j++) { //오른발의 위치
				D[s][i][n] = min(D[s][i][n], D[s - 1][i][j] + mp[j][n]);
			}
		}

		//왼발이 n인 자리에 위치하게되는 경우
		for (int i = 0; i <= 4; i++) { //오른발의 위치(어디든 상관 없음)
			if (n == i) continue;
			for (int j = 0; j <= 4; j++) { //왼발의 위치
				D[s][n][i] = min(D[s][n][i], D[s - 1][j][i] + mp[j][n]);
			}
		}

		s++;
	}

	long min_answer = INT_MAX;
	for (int i = 0; i <= 4; i++) {
		for (int j = 0; j <= 4; j++) {
			min_answer = min(min_answer, D[s-1][i][j]);
		}
	}

	cout << min_answer;

	return 0;
}