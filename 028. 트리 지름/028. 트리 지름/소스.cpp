#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> node;
vector<bool> visited;
vector<int> m_distance;
vector<vector<node>> A;

void BFS(int k) {
	queue<int> myqueue;
	myqueue.push(k);
	visited[k] = true;

	while (!myqueue.empty()) {
		int front = myqueue.front();
		myqueue.pop();
		for (node i : A[front]) {
			if (!visited[i.first]) {
				myqueue.push(i.first);
				visited[i.first] = true;
				m_distance[i.first] = m_distance[front] + i.second;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	A.resize(N+1);
	m_distance = vector<int>(N + 1, 0);
	visited = vector<bool>(N + 1, false);

	for (int i = 0; i < N; i++) {
		int num, tmp1, tmp2;
		cin >> num;
		while (1) {
			cin >> tmp1;
			if (tmp1 == -1) break;
			cin >> tmp2;
			A[num].push_back({ tmp1,tmp2 });

		}
	}


	BFS(1);
	int Max = 1;

	for (int i = 2; i < N + 1; i++) {
		if (m_distance[Max] < m_distance[i]) {
			Max = i;
		}
	}

	fill(m_distance.begin(), m_distance.end(), 0);
	fill(visited.begin(), visited.end(), false);
	BFS(Max);

	cout << *max_element(m_distance.begin(), m_distance.end());
}