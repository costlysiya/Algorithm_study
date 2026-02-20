#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int D[11][11];
	
	for (int i = 0; i <= n; i++) {
		D[i][0] = 1;
		D[i][1] = i;
		D[i][i] = 1;
	}

	for (int i = 2; i <= n; i++) { //전체 개수가 2이상, n이하
		for (int j = 1; j < i; j++) { //고르는 수의 개수가 전체 개수를 넘을 수 없음
			D[i][j] = D[i - 1][j] + D[i - 1][j - 1];
		}
	}

	cout << D[n][k];


	return 0;
}