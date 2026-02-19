#include <iostream>
#include <vector>
using namespace std;

static int N, M, K;
static long long MOD = 1000000007;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M >> K;

	int x = 0;

	while ((1 << x) < N) {
		x++;
	}

	int start_idx = 1 << x;

	vector<long long>tree(start_idx*2, 1);

	for (int i = 0; i < N; i++) {
		cin >> tree[start_idx + i];
	}

	for (int i = start_idx - 1; i > 0; i--) {
		tree[i] = (tree[i * 2] * tree[i * 2 + 1]) % MOD;
	}

	for (int i = 0; i < M + K; i++) {
		long long a, b, c;
		cin >> a >> b >> c;

		b = b + start_idx - 1;
		

		if (a == 1) {
			tree[b] = c;
			while (b > 1) {
				b /= 2;
				tree[b] = (tree[b * 2] * tree[b * 2 + 1]) % MOD;
			}
		}

		else if (a == 2) {
			c = c + start_idx - 1;
			long long answer = 1;
			while (b <= c) {
				if (b % 2 == 1) {
					answer *= tree[b++];
					answer %= MOD;
				}
				if (c % 2 == 0) {
					answer *= tree[c--];
					answer %= MOD;
				}
				b = b / 2;
				c = c / 2;
			}
			cout << answer << '\n';
		}
	}

	return 0;
}