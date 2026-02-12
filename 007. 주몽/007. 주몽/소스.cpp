#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;
	cin >> M;

	vector<int> S(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	sort(S.begin(), S.end());

	int start = 0;
	int end = N - 1;
	int sum;
	int count = 0;

	while (start < end) {
		sum = S[start] + S[end];
		if (sum == M) {
			count++;
			end--;
			start++;
		}
		else if (sum < M) {
			start++;
		}
		else if (sum > M) {
			end--;
		}
	}
	cout << count;
}