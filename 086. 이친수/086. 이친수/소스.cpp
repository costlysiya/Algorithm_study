#include <iostream>
using namespace std;

int main() {
	int N;
	long long end_with_1[91] = { 0 };
	long long end_with_0[91] = { 0 };


	cin >> N;

	end_with_1[1] = 1;
	end_with_0[1] = 0;

	for (int i = 2; i <= N; i++) {
		end_with_0[i] = end_with_0[i - 1] + end_with_1[i - 1];
		end_with_1[i] = end_with_0[i - 1];
	}

	cout << end_with_0[N] + end_with_1[N];

	return 0;
}