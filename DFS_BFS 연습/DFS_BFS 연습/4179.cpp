#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1e9;
int R, C;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
string maze[1001];
int depthJ[1001][1001];
int depthF[1001][1001];

//void bfs(int depth[][1001], queue<pair<int,int>> q) {
//	pair<int, int> now = q.front();
//	depth[now.first][now.second] = 0;
//
//	while (!q.empty()) {
//		//pair<int, int> now = q.front();
//		q.pop();
//
//		for (int i = 0; i < 4; i++) {
//			int nextx = now.first + dx[i];
//			int nexty = now.second + dy[i];
//
//			if (nextx<1 || nextx>R || nexty<1 || nexty>C) continue;
//			if (depth[nextx][nexty] == INT_MAX && maze[nextx][nexty] == ".") {
//				//cout << "next: " << nextx << " " << nexty << endl;
//				q.push({ nextx, nexty });
//				depth[nextx][nexty] = depth[now.first][now.second] + 1;
//				//cout << "depth: " << depth[nextx][nexty] << endl;
//			}
//		}
//	}
//
//}


int main() {
	queue<pair<int, int>> JH, Fire;
	cin >> R >> C;

	vector<pair<int, int>> Door;
	for (int i = 0; i < R; i++) {
		cin >> maze[i];
		for (int j = 0; j < C; j++) {
			depthF[i][j] = INF;
			depthJ[i][j] = -1;

			if (maze[i][j] == 'F') {
				Fire.push({ i,j });
				depthF[i][j] = 0;
			}else if (maze[i][j] == 'J') {
				JH.push({ i,j });
				depthJ[i][j] = 0;
			}
		}
	}

	while (!Fire.empty()) {
		auto now = Fire.front();
		Fire.pop();

		for (int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
			if (maze[nx][ny] == '#' || depthF[nx][ny] != INF) continue;
			depthF[nx][ny] = depthF[now.first][now.second] + 1;
			Fire.push({ nx,ny });
		}
	}

	while (!JH.empty()) {
		auto now = JH.front();
		JH.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			//출구에 도착했을 떄
			if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
				cout << depthJ[now.first][now.second] + 1;
				return 0;
			}
			//벽이거나 이미 방문했으면 통과
			if (maze[nx][ny] == '#' || depthJ[nx][ny] != -1) continue;
			//불이 더 먼저 도착한 경우 못감
			if (depthF[nx][ny] <= depthJ[now.first][now.second] + 1) continue;

			depthJ[nx][ny] = depthJ[now.first][now.second] + 1;
			JH.push({ nx,ny });
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}