#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<pair<int, int>> RC;
int DP[501][501];

int execute(int r, int c) {
	//이미 값이 구해진 적 있을 때
	if (DP[r][c]!= -1) return DP[r][c];

	//행렬 하나 곱
	if (r == c) return 0;

	//행렬 두개 곱
	if (r+1 == c) {
		return DP[r][c] = RC[r].first * RC[c].first * RC[c].second;
	}

	//행렬 3개 이상 곱
	int minval = INT_MAX;

	//두 덩이로 나눠서 곱한것 중 최솟값 저장
	for (int i = r; i < c; i++) {
		int a = RC[r].first * RC[i].second * RC[c].second;
		minval = min(minval, execute(r, i) + execute(i + 1, c) + a);
	}

	return DP[r][c] = minval;
	
}

int main() {
	int N;
	cin >> N;
	RC.resize(N + 1);

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			DP[i][j] = -1;
		}
	}

	for (int i = 1; i <= N; i++) {
		int r, c;
		cin >> r >> c;
		RC[i] = { r,c };
	}

	cout << execute(1, N);

	return 0;
}