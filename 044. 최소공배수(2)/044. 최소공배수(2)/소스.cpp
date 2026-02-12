#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
vector<tuple<int, int, int>> A[10];
bool visited[10];
long D[10];

long gcd(long x, long y) {
	if (y == 0) return x;
	else {
		return gcd(y, x % y);
	}
}

void DFS(int idx) {
	visited[idx] = 1;
	for (tuple<int, int, int> i : A[idx]) {
		int idx2 = get<0>(i);
		if (!visited[idx2]) {
			D[idx2] = D[idx] * get<2>(i) / get<1>(i);
			DFS(idx2);
		}
	}
}

int main() {
	int N;
	long LCD = 1;
	cin >> N;

	for (int i = 0; i < N-1; i++) {
		int a, b, p, q;
		cin >> a >> b >> p >> q;
		A[a].push_back(make_tuple(b, p, q));
		A[b].push_back(make_tuple(a, q, p));
		LCD *= p*q/gcd(p, q);
	}

	D[0] = LCD;
	DFS(0);

	long GCD = D[0];

	for (int i = 1; i < N; i++) {
		GCD = gcd(GCD, D[i]);
	}
	
	for (int i = 0; i < N; i++) {
		cout << D[i]/GCD << " ";
	}
}