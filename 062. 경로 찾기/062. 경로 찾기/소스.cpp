#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

static int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	vector<vector<int>> D(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			if (tmp == 0) continue;
			else D[i][j] = tmp;
		}
	}

	for (int k = 0; k < N; k++) {
		for (int s = 0; s < N; s++) {
			for (int e = 0; e < N; e++) {
				if (D[s][e] != 0) continue;
				else if (D[s][k] != 0 && D[k][e] != 0) {
					D[s][e] = 1;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int ans = D[i][j];
			cout << ans;
			cout << " ";
		}
		cout << '\n';
	}

	return 0;
}