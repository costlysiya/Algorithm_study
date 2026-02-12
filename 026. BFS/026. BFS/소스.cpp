#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static vector<vector<int>>A;
static vector<bool> visited;
queue<int> myqueue;

void DFS(int num) {
	cout << num << " ";
	visited[num] = 1;
	for (int i : A[num]) {
		if (!visited[i])
			DFS(i);
	}
}

void BFS(int num) {
	myqueue.push(num);
	visited[num] = 1;
	while (!myqueue.empty()) {
		//cout << "myqueue size: " << myqueue.size() << endl;
		int tmp = myqueue.front();
		cout << tmp << " ";
		myqueue.pop();
		for (int i : A[tmp]) {
			if (!visited[i]) {
				myqueue.push(i);
				visited[i] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, V, tmp1, tmp2;
	cin >> N >> M >> V;

	A.resize(N+1);
	visited = vector<bool>(N + 1, false);

	for (int i = 0; i < M; i++) {
		cin >> tmp1 >> tmp2;
		A[tmp1].push_back(tmp2);
		A[tmp2].push_back(tmp1);
	}

	for (int i = 1; i < N+1; i++) {
		sort(A[i].begin(), A[i].end());
	}

	DFS(V); 
	cout << "\n";
	fill(visited.begin(),visited.end(), false);
	BFS(V);
}