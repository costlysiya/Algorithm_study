#include<iostream>
#include<vector>
using namespace std;

vector<int>A;

int Findmain(int n) {
	//int idx = n;
	//int value = A[idx];
	//while (value != idx) {
	//	idx = value;
	//	value = A[idx];
	//}
	//return idx;
	if (n == A[n]) return n;
	else {
		return A[n] = Findmain(A[n]);
	}
}

void Union(int a, int b) {
	int a_root = Findmain(a);
	int b_root = Findmain(b);
	a_root < b_root ? A[b_root] = a_root : A[a_root] = b_root;
	//if (a_root != b_root)A[b_root] = a_root;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	A.resize(N + 1);

	for (int i = 0; i <= N; i++) {
		A[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int cal, a, b;
		cin >> cal >> a >> b;

		switch (cal) {
		case 0:
			Union(a, b);
			break;
		case 1:
			if (Findmain(a) == Findmain(b)) cout << "YES" << '\n';
			else cout << "NO" << '\n';
			break;
		}
	}
}