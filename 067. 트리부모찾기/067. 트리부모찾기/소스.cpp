#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

static int N;
typedef tuple<int, int> Edge;
static vector<vector<int>> edges;
static vector<int> answer;
static vector<bool> visited;

void dfs(int x) {
	visited[x] = true;
	for (int i : edges[x]) {
		if (!visited[i]) {
			answer[i] = x;
			dfs(i);
		}
	}
}

int main() {
	cin >> N;
	edges.resize(N + 1);
	answer.resize(N + 1);
	visited.resize(N + 1, 0);

	visited[1] = true;

	for (int i = 0; i < N - 1; i++) {
		int s, e;
		cin >> s >> e;
		edges[s].push_back(e);
		edges[e].push_back(s);
	}

	dfs(1);

	for (int i = 2; i < N + 1; i++) {
		cout << answer[i] << '\n';
	}

	return 0;
}