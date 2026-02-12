#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>A;
int visited[20001] = { 0 };
int check[20001] = { 0 };
bool ans = true;

void DFS(int node) {
	visited[node] = 1;

	for (int i : A[node]) {
		if (!visited[i]) {
			check[i] = (check[node] + 1) % 2;
			DFS(i);
		}
		else if (check[i] == check[node]) ans = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K, V, E;
	cin >> K;

	for (int i = 0; i < K; i++) {
		cin >> V >> E;
		A.resize(V + 1);

		for (int j = 0; j < E; j++) {
			int x, y;
			cin >> x >> y;
			A[x].push_back(y);
			A[y].push_back(x);
		}

		ans = true;
		for (int k = 1; k <= V; k++) {
			if (ans) DFS(k);
			else break;
		}
		if (ans) cout << "YES" << '\n';
		else cout << "NO" << '\n';

		for (int j = 0; j <= V; j++) {
			A[j].clear();
			visited[j] = 0;
		}
	}
}