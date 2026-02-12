#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int main() {
	int V, E, K;
	cin >> V >> E >> K;

	typedef pair<int, int> edge;
	vector<vector<edge>> mlist;
	vector<int> mdistance;
	vector<bool>visited;
	priority_queue<edge, vector<edge>, greater<edge>> q;

	mdistance.resize(V + 1);
	std::fill(mdistance.begin(), mdistance.end(), INT_MAX);
	visited.resize(V + 1);
	mlist.resize(V + 1);

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		mlist[u].push_back(edge(v, w));
	}

	q.push(make_pair(0, K));
	mdistance[K] = 0;

	while (!q.empty()) {
		int now = q.top().second;
		//int c_v = q.top().first;
		q.pop();
		if (visited[now]) {
			continue;
		}
		visited[now] = true;
		for (int i = 0; i < mlist[now].size(); i++) {
			edge tmp = mlist[now][i];
			int next = tmp.first;
			int value = tmp.second;

			if (mdistance[next] > mdistance[now] + value) {
				mdistance[next] = mdistance[now] + value;
				q.push(make_pair(mdistance[next], next));
			}
		}
	}
	for (int i = 1; i < V + 1; i++) {
		if (visited[i]) {
			cout << mdistance[i] << endl;
		}
		else {
			cout << "INF" << endl;
		}
	}

}