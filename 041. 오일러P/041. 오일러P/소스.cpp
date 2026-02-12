#include <iostream>
#include <cmath>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long N;
	cin >> N;
	long result = N;

	for (int i = 2; i <= sqrt(N); i++) {
		if (N % i == 0) {
			result = result - result / i;
			while (N % i == 0) {
				N /= i;
			}
		}
	}

	if (N > 1) {
		result = result - result / N;
	}
	cout << result;

}