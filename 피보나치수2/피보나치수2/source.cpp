#include <iostream>
using namespace std;

long long answer[91] = { 0 };

long long fibo(int k) {
	if (k == 0) {
		return 0;
	}
	if (answer[k] != 0) {
		return answer[k];
	}
	else {
		return answer[k]=fibo(k - 2) + fibo(k - 1);
	}
}


int main() {
	answer[1] = 1;
	answer[2] = 1;
	int n;
	cin >> n;
	cout<<fibo(n);
	return 0;
}