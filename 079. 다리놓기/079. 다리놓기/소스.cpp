#include <iostream>
using namespace std;

static int T, N, M;
static int D[31][31];

int main() {
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n, m; 
		cin >> n >> m;

		for (int i = 1; i <= m; i++) {
			D[i][i] = 1;
			D[i][1] = i;
			D[i][0] = 1;
		}

		for (int i = 2; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				D[i][j] = D[i - 1][j] + D[i - 1][j - 1];
			}
		}

		
		cout << D[m][n] << '\n';

	}


	return 0;
}