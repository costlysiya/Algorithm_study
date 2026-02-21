#include <iostream>
#include <vector>
using namespace std;

static int M, K;
static int N = 0;
static int D[51];
static double probability[51];
static double ans = 0.0;

int main() {
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> D[i];
		N += D[i];
	}
	cin >> K;

	double answer = 0;

	//각 색상에서 K개 뽑을 수 있는 확률을 더해줌
	for (int i = 0; i < M; i++) {
		if (D[i] >= K){ //뽑으려는 개수 보다 그 색상인 것의 개수가 많을경우만 체크
			probability[i] = 1.0;

			for (int k = 0; k < K; k++) {
				probability[i] *= (double)(D[i] - k) / (N - k);
			}
		}
		ans += probability[i];

	}

	cout << fixed;
	cout.precision(9);
	cout << ans;

	return 0;
}