#include <bits/stdc++.h>
using namespace std;
int N;
int D[101][101];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
bool visited[101][101];

void bfs(int amount, int x, int y) {
	queue<pair<int, int>> q;
	q.push({x, y});
	visited[x][y] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (!visited[nx][ny] && D[nx][ny] > amount) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}



int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> D[i][j];
		}
	}

	int maxArea = 0;
	for (int rain = 0; rain <= 100; rain++) {
		memset(visited, false, sizeof(visited));
		int nowMax = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && D[i][j] > rain) {
					nowMax++;
					bfs(rain, i, j);
				}
			}
		}
		if (nowMax == 0) break;
		maxArea = max(maxArea, nowMax);
	}

	cout << maxArea;
	return 0;
}