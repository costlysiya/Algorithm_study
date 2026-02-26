#include <iostream>
using namespace std;

long D[101][101][101];

int main() {
	int N, L, R;
	cin >> N >> L >> R;

	//D[N][L][R] = N개의 빌딩이 있고 왼쪽에서 L개, 오른쪽에서 R개 보일때 가능한 경우의 수
	D[1][1][1] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= L; j++) {
			for (int k = 1; k <= R; k++) {
				//현재 = (왼-1)인 앞단계 + (오-1)인 앞단계 + 앞단계*(i-2)
				//*(i-2)하는 이유는 가장 짧은게 중간에 위치되는 경우의 수가 i-2이기 때문
				D[i][j][k] = (D[i - 1][j - 1][k] + D[i - 1][j][k - 1] + D[i - 1][j][k] * (i - 2)) % 1000000007;
			}
		}
	}

	cout << D[N][L][R];


	return 0;
}