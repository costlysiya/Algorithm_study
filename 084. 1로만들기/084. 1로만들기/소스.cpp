#include <iostream>
using namespace std;
static int N;
static int D[10000001];




int main() {
	cin >> N;
	
	for (int n = 2; n <= N; n++) {
		D[n] = D[n - 1] + 1;
		if (n % 2 == 0) {
			D[n] = min(D[n], D[n / 2] + 1);
		}
		if (n % 3 == 0) {
			D[n] = min(D[n], D[n / 3] + 1);
		}
	}

	cout << D[N];

	return 0;
}