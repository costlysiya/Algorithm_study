#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<pair<int,int>>> A;
	vector<vector<pair<int, int>>> reverseA;
	vector<int> indegree;
	vector<int> result;
	vector<bool> visited;
	queue<int> Q;

	A.resize(N + 1);
	reverseA.resize(N + 1);
	indegree.resize(N + 1);
	result.resize(N + 1);
	visited.resize(N + 1);


	for (int i = 0; i < M; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		A[a].push_back(pair<int, int>(b, t));
		reverseA[b].push_back(pair<int, int>(a, t));
		indegree[b]++;
	}

	int start, end;
	cin >> start >> end;

	Q.push(start);
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (pair<int, int>next : A[now]) {
			int x, t;
			x = next.first;
			t = next.second;
			indegree[x]--;
			result[x] = max(result[x], result[now] + t);
			if (indegree[x] == 0) {
				Q.push(x);
			}
		}
	}

	//for (int i = 1; i < N + 1; i++) {
	//	cout << result[i] << endl;
	//}

	int answerT = result[end];
	int count = 0;

	Q.push(end);
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (pair<int, int> next : reverseA[now]) {
			int x, t;
			x = next.first;
			t = next.second;
			if (result[now] == result[x] + t) {
				count++;
				if (!visited[x]) {
					visited[x] = true;
					Q.push(x);
				}
			}

		}
	}

	cout << answerT << endl;
	cout << count << endl;
}