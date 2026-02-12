#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> target;

void binary_search(int k) {
	int start_idx = 0; int end_idx = target.size();
	int mid_idx = target.size() / 2;
	while (target[mid_idx] != k) {
		if (start_idx == mid_idx || end_idx == mid_idx) {
			cout << 0 << '\n';
			return;
		}
		if (target[mid_idx] < k) {
			start_idx = mid_idx;
			mid_idx = (mid_idx + end_idx) / 2;
		}
		else if (target[mid_idx] > k) {
			end_idx = mid_idx;
			mid_idx = (mid_idx + start_idx) / 2;
		}
	}
	cout << 1 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N;
	target = vector<int> (N, 0);

	for (int i = 0; i < N; i++) {
		cin >> target[i];
	}

	sort(target.begin(), target.end());

	cin >> M;
	int num;

	for (int i = 0; i < M; i++) {
		cin >> num;
		binary_search(num);
	}


}