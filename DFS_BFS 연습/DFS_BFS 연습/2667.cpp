#include <bits/stdc++.h>
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
bool visited[26][26];
int N;

int bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	int cnt = 1;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (!visited[nx][ny]) {
				cnt++;
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
	return cnt;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string p;
		cin >> p;
		for (int j = 0; j < N; j++) {
			if (p[j] == '0') {
				visited[i][j] = true;
				//cout << "0ÀÎ °÷: " << i << " " << j << endl;
			} 
		}
	}

	int cnt = 0; vector<int>Area;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				cnt++;
				Area.push_back(bfs(i, j));
			}
		}
	}
	sort(Area.begin(), Area.end());
	cout << cnt << '\n';
	for (auto x : Area) cout << x << '\n';
}