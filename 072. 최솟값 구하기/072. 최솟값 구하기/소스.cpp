#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int N, M;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;

	int k = 0;
	while ((1 << k) < N) {
		k++;
	}

	int tree_start_index = 1 << k;

	vector<long long> tree(tree_start_index * 2, 2000000000);

	for (int i = tree_start_index; i < tree_start_index + N; i++) {
		cin >> tree[i];
	}

	for (int i = tree_start_index - 1; i > 0; i--) {
		tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		long long answer = 2000000000;
		cin >> a >> b;

		int start_idx = a + tree_start_index - 1;
		int end_idx = b + tree_start_index - 1;

		while (start_idx <= end_idx) {
			if (start_idx % 2 == 1) {
				answer = min(answer, tree[start_idx]);
				start_idx++;
			}
			if (end_idx % 2 == 0) {
				answer = min(answer, tree[end_idx]);
				end_idx--;
			}
			start_idx /= 2;
			end_idx /= 2;
		}
		cout << answer << '\n';
		
	}
	return 0;
}