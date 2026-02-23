#include <iostream>
using namespace std;

static int N, M, K;
long long D[202][202];

int main() {
	cin >> N >> M >> K;

	for (int i = 0; i <= N + M; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				D[i][j] = 1;
			}
			else {
				D[i][j] = D[i - 1][j] + D[i - 1][j - 1];
				if (D[i][j] > 1000000000) {
					D[i][j] = 1000000001;
				}
			}
		}
	}

	//for (int i = 0; i <= N + M; i++) {
	//	for (int j = 0; j <= N + M; j++) {
	//		cout << D[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	if (D[N + M][M] < K) {
		cout << -1;
	}
	else {
		while (!(N==0 && M==0)) {
			if (D[N + M - 1][M] >= K) {
				cout << "a";
				N--; //a의 개수를 하나 줄임
			}
			else {
				cout << "z";
				K = K - D[N + M - 1][M]; //z로 시작함으로 a로 시작하는 경우의 수 만큼 빼줌
				M--; //z의 개수를 하나 줄임
			}
			
		}

	}
	return 0;
}