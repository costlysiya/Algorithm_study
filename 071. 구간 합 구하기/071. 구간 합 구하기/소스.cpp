#include <iostream>
#include <vector>

using namespace std;

static int N, M, S;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M >> S;

	int k = 0;
	while ((1 << k) < N) {
		k++;
	}

	int tree_start_index = 1 << k;

	vector<long long> tree(tree_start_index * 2, 0);

	for (int i = tree_start_index; i < tree_start_index + N; i++) {
		cin >> tree[i];
	}

	//구간 합 구하기
	for (int i = tree_start_index + N; i > 0; i--) {
		int parent_index = i / 2;
		tree[parent_index] += tree[i];
	}


	for (int i = 0; i < M + S; i++) {
		long long a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {
			long long seg_index = b + tree_start_index - 1;
			long long diff = c - tree[seg_index];
			tree[seg_index] = c;

			long long parent_index = seg_index / 2;

			while (parent_index > 0) {
				tree[parent_index] += diff;
				parent_index /= 2;
			}
		}
		else if (a == 2) {
			long long start_index = b + tree_start_index - 1;
			long long end_index = c + tree_start_index - 1;
			long long sum = 0;

			while (start_index <= end_index) {
				if (start_index % 2 == 1) {
					sum += tree[start_index];
				}
				if (end_index % 2 == 0) {
					sum += tree[end_index];
				}
				start_index = (start_index + 1) / 2;
				end_index = (end_index - 1) / 2;
			}
			cout << sum << '\n';
		}
	}

	return 0;
}