#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int N, M;
	vector<vector<int>> A;
	vector<int> indegree;
	queue<int> Q;

	cin >> N >> M;
	A.resize(N + 1);
	indegree.resize(N + 1, 0);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		A[a].push_back(b);
		indegree[b]++;
	}


	for (int i = 1; i < N + 1; i++) {
		if (indegree[i] == 0) {
			Q.push(i);
		}
	}

	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		cout << now << " ";
		for (int next:A[now]) {
			indegree[next]--;
			if (indegree[next] == 0) {
				Q.push(next);
			}
		}
	}
}