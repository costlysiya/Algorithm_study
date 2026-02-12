#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, tmp;
	cin >> N;

	int B[10001] = { 0 };

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		B[tmp]++;
	}

	int index = 0;

	for (int i = 1; i < 10001; i++) {
		while (B[i] > 0) {
			cout << i << '\n';
			B[i]--;
		}
	}

}