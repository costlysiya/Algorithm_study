#include <bits/stdc++.h>
using namespace std;
int F, S, G, U, D;
int visited[1000001];
int UpDown[2];

int main() {
	cin >> F >> S >> G >> UpDown[0] >> UpDown[1];
	UpDown[1] = -UpDown[1];
	memset(visited, -1, sizeof(visited));

	queue<int> q;
	q.push(S);
	visited[S] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == G) {
			cout << visited[G];
			return 0;
		}

		for (int button : UpDown) {
			int floor = cur + button;
			if (floor > F || floor < 1) continue;
			if (visited[floor] == -1) {
				visited[floor] = visited[cur] + 1;
				q.push(floor);
			}
		}
	}

	cout << "use the stairs";
	return 0;
}