#include <iostream>
#include <vector>
using namespace std;

int visited[1001] = { 0 };
static vector<vector<int>> A;

void DFS(int start) {
	if (visited[start]) return;
	visited[start] = 1;
	for (int i = 0; i < A[start].size(); i++) {
		if (!visited[A[start][i]])
			DFS(A[start][i]);
	}
}

int main() {
	int N, E, tmp, tmp2, cnt=0;
	cin >> N >> E;

	A.resize(N + 1);


	for (int i = 0; i < E; i++) {
		cin >> tmp >> tmp2;
		A[tmp].push_back(tmp2);
		A[tmp2].push_back(tmp);
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			cnt++;
			DFS(i);
		}
	}

	cout << cnt;
}