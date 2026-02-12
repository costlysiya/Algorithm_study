#include <iostream>
#include <vector>
using namespace std;

bool arrive = false;
bool visited[2001] = { 0 };
vector<vector<int>>A;

void DFS(int person, int cnt) {
	if (cnt == 5 || arrive) {
		arrive = true;
		return;
	}

	visited[person] = 1;

	for (int i : A[person]) {
		if (!visited[i]) {
			DFS(i, cnt+1);
		}
	}
	visited[person] = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, tmp1, tmp2;
	cin >> N >> M;

	A.resize(N);
	
	for (int i = 0; i < M; i++) {
		cin >> tmp1 >> tmp2;
		A[tmp1].push_back(tmp2);
		A[tmp2].push_back(tmp1);
	}

	for (int i = 0; i < N; i++) {
		DFS(i, 1);
		if (arrive) break;
	}

	if (arrive)
		cout << 1;
	else
		cout << 0;
}