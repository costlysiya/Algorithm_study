#include <iostream>
#include <algorithm>
using namespace std;

int GCD(int x, int y) {
	while (1) {
		if (x > y) {
			x = x % y;
		}
		else {
			y = y % x;
		}
		if (x == 0) return y;
		if (y == 0) return x;
	}

}

int main() {
	int N, x, y;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		cout << x * y / GCD(x, y) << "\n";
	}
}