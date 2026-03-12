#include <iostream>
#include <queue>
using namespace std;
int x[] = { 0, 1, 0, -1 };
int y[] = { 1,0,-1,0 };
int paint[502][502];
bool visited[502][502];
int maxsize = 0;
int count_paint = 0;
int n, m;


int bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = true;

	int paint_size = 0;

	while (!q.empty()) {
		int nowi = q.front().first;
		int nowj = q.front().second;
		q.pop();
		//cout << "현재좌표: " << nowi << " " << nowj << endl;

		paint_size++;

		for (int i = 0; i < 4; i++) {
			int nx = nowi + x[i];
			int ny = nowj + y[i];

			if (nx<1 || nx>n || ny<1 || ny>m) continue; //범위 넘는 것
			if (visited[nx][ny] || paint[nx][ny] == 0) continue; //방문했거나 0인것

			visited[nx][ny] = true;
			q.push({nx, ny});
		}

	}
	return paint_size;
}


int main() {
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> paint[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (paint[i][j] == 1 && !visited[i][j]) {
				count_paint++;
				maxsize = max(maxsize, bfs(i, j));
			}
		}
	}


	cout << count_paint << '\n';
	cout << maxsize << '\n';

	return 0;
}