#include <bits/stdc++.h>
using namespace std;
int N, M, H;
int tomato[101][101][101];
int visited[101][101][101] = { 0, };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int dx[6] = { 0, 0, 1, -1, 0, 0 };
int dy[6] = { 1, -1, 0, 0, 0, 0 };

struct xyz {
	int z; int x; int y;
};


int main() {
	cin >> M >> N >> H;
	queue<xyz> q;

	for (int h = 0; h < H; h++) {
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				cin >> tomato[h][n][m];
				if (tomato[h][n][m] == 1) {
					q.push({ h,n,m });
					visited[h][n][m] = 0;
				}else {
					visited[h][n][m] = -1;
				}
			}
		}
	}

	while (!q.empty()) {
		xyz now = q.front(); q.pop();

		for (int i = 0; i < 6; i++) {
			int nz = now.z + dz[i];
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nz < 0 || nx < 0 || ny < 0 || nz >= H || nx >= N || ny >= M) continue;
			// 안 익은 토마토(0)이고 아직 방문 안 한(-1) 경우만
			if (tomato[nz][nx][ny] == 0 && visited[nz][nx][ny] == -1) {
				visited[nz][nx][ny] = visited[now.z][now.x][now.y] + 1;
				q.push({ nz, nx, ny });
			}
		}
	}
	
	int day = 0;
	for (int h = 0; h < H; h++) {
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				if (tomato[h][n][m] == 0 && visited[h][n][m] == -1) {
					cout << -1;
					return 0;
				}
				day = max(day, visited[h][n][m]);
			}
		}
	}
	cout << day;
	return 0;
}