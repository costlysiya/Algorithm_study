#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int DP[1001][1001];
vector<char>Path;
string A, B;

void get_text(int r, int c) {
	if (r == 0 || c == 0) return;

	if (A[r - 1] == B[c - 1]) {
		Path.push_back(A[r - 1]);
		get_text(r - 1, c - 1);
	}
	else {
		//왼쪽 또는 윗쪽 중에 DP값이 더 큰쪽(공통 부분이 더 긴 쪽)으로 이동
		if (DP[r - 1][c] > DP[r][c - 1]) {
			get_text(r - 1, c);
		}
		else {
			get_text(r, c - 1);
		}
	}
}

int main() {

	cin >> A >> B;

	for (int i = 1; i <= A.size(); i++) {
		for (int j = 1; j <= B.size(); j++) {
			if (A[i-1] == B[j-1]) {
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else {
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}
		}
	}

	cout << DP[A.size()][B.size()] << '\n';

	get_text(A.size(), B.size());
	
	for (int i = Path.size() - 1; i >= 0; i--) {
		cout << Path[i];
	}

	return 0;
}