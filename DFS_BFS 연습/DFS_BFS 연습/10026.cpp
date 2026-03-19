#include <bits/stdc++.h>
using namespace std;
//string metrix[101];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int N;
bool visited[101][101] = { 0, };
string metrix[101];

void bfs(int nx, int ny, char color) {
	queue<pair<int, int>> q;
	
	q.push({ nx, ny });
	visited[nx][ny] = true;

	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x = now.first + dx[i];
			int y = now.second + dy[i];
			if (x < 0 || y < 0 || x >= N || y >= N) continue;

			if (!visited[x][y] && metrix[x][y] == color) {
				visited[x][y] = true;
				q.push({ x,y });
			}
		}
	}
}

int section() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				cnt++;
				bfs(i, j, metrix[i][j]);
			}
		}
	}
	return cnt;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> metrix[i];
	}
	
	cout << section() << " ";

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (metrix[i][j] == 'G') {
				metrix[i][j] = 'R';
			}
			visited[i][j] = false;
		}
	}

	cout << section();

	return 0;
}