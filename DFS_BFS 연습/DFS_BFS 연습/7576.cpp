#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

static int N, M;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int tomato[1001][1001];
int depth[1001][1001];
bool visited[1001][1001] = {};

void bfs(queue<pair<int, int>> q) {
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nextx = now.first + dx[i];
			int nexty = now.second + dy[i];

			if (nextx <= 0 || nexty <= 0 || nextx>N || nexty >M) continue;
			if (!visited[nextx][nexty] && tomato[nextx][nexty]==0) {
				q.push({ nextx, nexty });
				visited[nextx][nexty] = true;
				depth[nextx][nexty] = depth[now.first][now.second] + 1;
			}
		}
	}
}


int main() {
	cin >> M >> N;
	queue<pair<int, int>> q;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				q.push({ i,j });
				visited[i][j] = true;
			}
			if (tomato[i][j] == -1) visited[i][j] = true;
		}
	}

	bfs(q);

	int answer = -1;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!visited[i][j]) {
				cout << -1;
				exit(0);
			}
			else {
				answer = max(answer, depth[i][j]);
			}
		}
	}

	cout << answer;
	return 0;
}