#include <bits/stdc++.h>
using namespace std;
int N;
int chess[301][301];
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };
int dist[301][301];

void bfs(int x, int y, int destX, int destY) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	dist[x][y] = 0;

	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

			if (dist[nx][ny] == -1) {
				//cout << "nx: " << nx << " ny:" << ny << endl;
				dist[nx][ny] = dist[now.first][now.second] + 1;
				q.push({ nx, ny });
				if (nx == destX && ny == destY) {
					cout << dist[nx][ny] <<'\n';
					return;
				}
			}
		}
	}
}

int main() {
	int T;
	cin >> T;


	for (int t=0; t < T; t++) {
		cin >> N;
		int x, y, destX, destY;
		memset(dist, -1, sizeof(dist));
		cin >> x >> y;
		cin >> destX >> destY;

		if (x == destX && y == destY) cout << 0 << '\n';
		else {
			bfs(x, y, destX, destY);
		}
	}


	return 0;
}