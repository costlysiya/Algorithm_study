#include<iostream>
#include<vector>
using namespace std;

int main() {
	int T, k, n;
	
	cin >> T;
	for (int t = 0; t < T; t++) {

		cin >> k;
		cin >> n;

		vector<vector<int>>D(k + 1, vector<int>(n + 1, 0));

		for (int j = 1; j < n + 1; j++) {
			D[0][j] = j;
		}

		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= n; j++) {
				D[i][j] = D[i][j - 1] + D[i - 1][j];
			}
		}
		cout << D[k][n] << '\n';
	}

	

	return 0;
}