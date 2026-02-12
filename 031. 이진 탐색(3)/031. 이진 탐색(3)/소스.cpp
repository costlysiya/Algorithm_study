#include<iostream>
using namespace std;

int main() {
	long N, k;
	cin >> N;
	cin >> k;

	long start = 1;
	long end = k;
	long ans = 0;

	while (start <= end) {
		long mid = (start + end) / 2;
		long sum = 0;
		for (int i = 1; i <= N; i++) {
			sum += min(mid / i, N);
		}

		if (sum < k) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
			ans = mid;
		}
	}

	cout << ans;
}