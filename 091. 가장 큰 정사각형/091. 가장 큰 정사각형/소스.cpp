#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int DP[1001][1001];

int main() {
	int n, m;
	cin >> m >> n;

	int max_side = 0;


	for (int i = 1; i <= m; i++) {
		string line;
		cin >> line;
		for (int j = 1; j <= n; j++) {
			if (line[j-1] == '1') {
				//해당 칸을 오른쪽 아래 꼭짓점으로 하는 가장 큰 정사각형의 한 변의 길이 저장
				DP[i][j] = min({ DP[i - 1][j], DP[i][j - 1], DP[i - 1][j - 1] }) + 1;
				max_side = max(max_side, DP[i][j]);
			}
		}
	}

	cout << max_side * max_side;

	
	return 0;
}