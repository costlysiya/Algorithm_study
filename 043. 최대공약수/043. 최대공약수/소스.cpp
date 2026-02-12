#include <iostream>
using namespace std;

long GCD(long x, long y) {
	if (y == 0) return x;
	else {
		return GCD(y, x % y);
	}
}

int main() {
	long a, b;
	cin >> a >> b;

	//cout << GCD(a, b);

	for (int i = 0; i < GCD(a, b); i++) {
		cout << 1;
	}
}