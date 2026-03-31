#include<bits/stdc++.h>
using namespace std;
int L, N, M;
vector<vector<string>> D;
int visited[31][31][31];
int dx[6] = { 0, 1, 0, -1, 0, 0 };
int dy[6] = { 1, 0, -1, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

struct xyz {
	int z; int x; int y;
};

void solve() {
	D.clear();
	D.resize(L, vector<string>(N, ""));
	memset(visited, -1, sizeof(visited));

	queue<xyz> q;
	for (int l = 0; l < L; l++) {
		for (int n = 0; n < N; n++) {
			cin >> D[l][n];
			for (int m = 0; m < M; m++) {
				if (D[l][n][m] == 'S') {
					q.push({ l, n, m });
					visited[l][n][m] = 0;
				}
			}
		}
	}

	while (!q.empty()) {
		xyz cur = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			int nz = cur.z + dz[i];

			if (nx < 0 || ny < 0 || nz < 0 || nz >= L || nx >= N || ny >= M) continue;

			if (visited[nz][nx][ny] == -1 && D[nz][nx][ny] != '#') {
				visited[nz][nx][ny] = visited[cur.z][cur.x][cur.y] + 1;
				
				q.push({ nz, nx, ny });
			}
			if (D[nz][nx][ny] == 'E') {
				cout <<"Escaped in " << visited[nz][nx][ny] << " minute(s)." << '\n';
				return;
			}
		}
	}
	cout << "Trapped!" << '\n';
}


int main() {
	cin >> L >> N >> M;
	while (L != 0 && N != 0 && M != 0) {
		solve();
		cin >> L >> N >> M;
	}

	return 0;
}