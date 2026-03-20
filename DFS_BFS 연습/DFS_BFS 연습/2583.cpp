#include<bits/stdc++.h>
using namespace std;
int N, M, K;
int dist[101][101];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

struct pt {
	int x; int y;
};

int bfs(int x, int y) {
	queue<pt> q;
	q.push({ x,y });
	int cnt = 0;
	while (!q.empty()) {
		pt cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (dist[nx][ny] == -1) continue;
			if (dist[nx][ny] == 0) {
				cnt++;
				dist[nx][ny] = dist[cur.x][cur.y] + 1;
				q.push({ nx, ny });
			}
		}
	}
	if (cnt == 0) cnt++;
	return cnt;
}

int main() {
	cin >> N >> M >> K;
	while (K--) {
		pt left, right;
		cin >> left.y >> left.x >> right.y >> right.x;
		for (int i = right.x - 1; i >= left.x; i--) {
			for (int j = right.y - 1; j >= left.y; j--) {
				dist[i][j] = -1;
				//cout << "black: " << i << " " << j << endl;
			}
		}
	}

	int cnt = 0; vector<int>Area;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dist[i][j] == 0) {
				cnt++;
				Area.push_back(bfs(i, j));
			}
		}
	}
	sort(Area.begin(), Area.end());
	cout << cnt << '\n';
	for (auto a : Area) cout << a << " ";

}