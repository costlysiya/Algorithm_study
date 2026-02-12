#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int>&a, const pair<int, int>&b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second<b.second;
}

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> A(N);

	for (int i = 0; i < N; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		A[i] = { n1,n2 };
	}

	sort(A.begin(), A.end(), cmp);

	int cnt = 0;
	int end = -1;

	for (int i = 0; i < N; i++) {
		if (A[i].first >= end) {
			cnt++;
			end = A[i].second;
		}
	}
	cout << cnt;

}