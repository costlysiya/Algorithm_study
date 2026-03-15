#include <bits/stdc++.h>
using namespace std;



int main() {
	int N, K;
	
	cin >> N >> K;

	queue<int> q;
	int visited[100001] = {0};
	
	q.push(N);
	visited[N] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		int n[3];
		n[0] = now - 1;
		n[1] = now + 1;
		n[2] = now * 2;

		for (auto next : n) {
			if (next < 0 || next>100000) continue;

			if (visited[next] == 0) {
				visited[next] = visited[now] + 1;
				//cout << "next: " << next << endl;
				//cout << "ÇöÀç visited: "<< visited[next]-1 << endl;
				q.push(next);
			}

			if (next == K) {
				cout << visited[K] - 1;
				return 0;
			}
		}
		
	}

	return 0;
}