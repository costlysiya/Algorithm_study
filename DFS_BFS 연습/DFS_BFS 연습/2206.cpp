#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
#include<tuple>

using namespace std;
string D[1001];
int visited[1001][1001][2]; //벽을 부순적 있는지도 체크. [nx][ny][broken_cnt] 
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int N, M;

int bfs() {
	queue<tuple<int, int, int>> q;
	//memset(visited, -1, sizeof(visited));
	q.push({ 0, 0, 0 });
	visited[0][0][0] = 1;

	while (!q.empty()) {
		auto cur = q.front();
		int x = get<0>(cur);
		int y = get<1>(cur);
		int broken = get<2>(cur);
		q.pop();

		if (x == N - 1 && y == M - 1) return visited[x][y][broken];

		for (int i = 0; i < 4; i++) {
			int nx =  x + dx[i];
			int ny = y + dy[i];

			if (nx<0 || ny<0 || nx >= N || ny >= M) continue;
			//다음칸이 빈칸인 경우
			//broken이 1이든 0이든 상관 없이 갈 수 있음
			if (D[nx][ny] == '0' && visited[nx][ny][broken] == 0) {
				visited[nx][ny][broken] = visited[x][y][broken] + 1;
				q.push({ nx, ny, broken });
			}
			//다음칸이 벽이고, 아직 벽을 부순적이 없고, 
			//벽을 부순 상태(1)로 nx,ny에 도착한 적이 있는지 확인.
			//visited[nx][ny][0]는 확인할 필요 없음. 원래 벽이였기 때문에 애초에 도달할 수 없기 때문
			if (D[nx][ny] == '1' && broken==0 && visited[nx][ny][1]==0) {
				visited[nx][ny][1] = visited[x][y][0] + 1;
				q.push({ nx, ny, 1 });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
			string s;
			cin >> D[i];
	}

	cout << bfs();

}