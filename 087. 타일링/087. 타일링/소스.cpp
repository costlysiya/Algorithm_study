#include <iostream>
using namespace std;

int main() {
	int N;
	int D[1001] = { 0 };
	cin >> N;

	D[1] = 1;
	D[2] = 2;

	for (int i = 3; i <= N; i++) {
		D[i] = (D[i - 1] + D[i - 2])%10007;
	}

	cout << D[N];


	return 0;
}