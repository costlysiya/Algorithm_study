#include <iostream>
#include <queue>
using namespace std;

static int A[101][101];
bool visited[101][101];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int N, M;

void BFS(int i, int j) {
	queue<pair<int, int>> myqueue;
	myqueue.push({i, j});
	visited[i][j] = 1;
	while (!myqueue.empty()) {
		pair<int, int> tmp = myqueue.front();
		myqueue.pop();
		for (int k = 0; k < 4; k++) {
			int x = tmp.first + dy[k];
			int y = tmp.second + dx[k];
			if (x < N && y < M && x >= 0 && y >= 0) {
				if (A[x][y] != 0 && !visited[x][y]) {
					visited[x][y] = 1;
					A[x][y] = A[tmp.first][tmp.second] + 1;
					myqueue.push({ x,y });
				}
			}

		}
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			A[i][j] = s[j] - '0';
		}
	}

	BFS(0, 0);
	cout << A[N - 1][M - 1];

}