#include <iostream>
using namespace std;

static int N;
static long D[1000001];


int main() {
	cin >> N;

	D[1] = 0;
	D[2] = 1;

	for (int i = 3; i <= N; i++) {
		D[i] = (i - 1)*(D[i - 2] + D[i - 1])%1000000000;
	}
	cout << D[N];

	return 0;
}