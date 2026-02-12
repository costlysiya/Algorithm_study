#include <iostream>
#include <vector>
using namespace std;

int A[201] = { 0 };

int Find(int n) {
	if (n == A[n]) return n;
	else {
		return A[n] = Find(A[n]);
	}
}

void Union(int a, int b) {
	int a_root = Find(a);
	int b_root = Find(b);

	a_root < b_root ? A[b_root] = a_root : A[a_root] = b_root;
	//cout << "a_root: " << A[a_root] << "  b_root: " << A[b_root] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i <= N; i++) {
		A[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		//cout << "i: " << i << endl;
		for (int j = 1; j <= N; j++) {
			//cout << "j: " << j << endl;
			int k; cin >> k;
			if (k == 1 && Find(i)!=Find(j)) {
				Union(i, j);
			}
		}
	}

	int k = 0, root = A[k];
	cin >> k;

	for (int i = 1; i < M; i++) {
		int z;
		cin >> z;
		if (Find(k) != Find(z)) {
			cout << "NO" << '\n';
			return 0;
		}
		k = z;
	}
	cout << "YES" << '\n';
}