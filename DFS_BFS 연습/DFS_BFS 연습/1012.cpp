#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
 
int main() {
	int T;
	cin >> T;


	for (int t = 0; t < T; t++) {
		int M, N, K;
		cin >> M >> N >> K;
		int place[51][51] = { 0, };
		bool visited[51][51] = { 0, };
		int count = 0;
		queue<pair<int, int>> q;

		for (int k = 0; k < K; k++) {
			int x, y;
			cin >> x >> y;
			q.push({ y,x });
			place[y][x] = 1;
		}

		while (!q.empty()) {
			auto nnow = q.front();
			q.pop();

			queue<pair<int, int>> qq;

			if (!visited[nnow.first][nnow.second]) {
				visited[nnow.first][nnow.second] = true;
				//cout << "new start: " << nnow.first << " " << nnow.second << endl;
				count++;
				//cout << "count: " << count << endl;
				qq.push(nnow);
			} 

			
			while (!qq.empty()) {
				auto now = qq.front();
				qq.pop();

				for (int i = 0; i < 4; i++) {
					int nexti = now.first + dx[i];
					int nextj = now.second + dy[i];

					if (nexti < 0 || nextj < 0 || nexti > N || nextj > M) continue;
					if (!visited[nexti][nextj] && place[nexti][nextj] == 1) {
						visited[nexti][nextj] = true;
						qq.push({ nexti, nextj });
					}
				}
			}
		}
		cout << count << '\n';
	}

	return 0;
}