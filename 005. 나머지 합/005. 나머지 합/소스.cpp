#include <iostream>
using namespace std;

long S[1000001]; //단위 잘보기
long C[1001] = {};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int tmp;

	cin >> N >> M;
	cin >> tmp;
	S[0] = tmp % M;
	C[S[0]] += 1;

	for (int i = 1; i < N; i++) {
		cin >> tmp;
		S[i] = (S[i - 1] + tmp) % M;
		C[S[i]] += 1;
	}

	long ans = 0;
	ans += C[0];
	for (int i = 0; i < 1001; i++) {
		ans += C[i] * (C[i] - 1) / 2;
	}
	cout << ans;
}