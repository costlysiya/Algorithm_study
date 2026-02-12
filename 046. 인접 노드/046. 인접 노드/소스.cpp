#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

long visited[300001];
vector<long>answer;
vector<vector<long>> A;
long K;

void BFS(long node) {
	queue<long> myqueue;
	myqueue.push(node);
	visited[node]++;

	while (!myqueue.empty()) {
		long top = myqueue.front();
		myqueue.pop();
		for (long i : A[top]) {
			if (visited[i] == -1) {
				myqueue.push(i);
				visited[i] = visited[top] + 1;
			}
		}
	}
}

int main() {
	long N, M, X;
	cin >> N >> M >> K >> X;

	A.resize(N + 1);

	for (long i = 0; i < M; i++) {
		long x, y;
		cin >> x >> y;
		A[x].push_back(y);
	}

	for (long i = 0; i < N + 1; i++) {
		visited[i] = -1;
	}
	BFS(X);

	for (long i = 0; i <= N; i++) {
		if (visited[i] == K) answer.push_back(i);
	}

	if (answer.size() == 0) {
		cout << -1;
	}
	else {
		for (long i : answer) {
			cout << i << '\n';
		}
	}
}