#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> edge;
static int N, M;
static vector<vector<edge>> mlist;
static vector<int> dist;
static vector<bool>visited;

int dijkstra(int start, int end) {
	priority_queue<edge, vector<edge>, greater<edge>> q;
	q.push(make_pair(0, start));
	dist[start] = 0;
	while (!q.empty()) {
		edge nowNode = q.top();
		int now = nowNode.second;
		q.pop();
		if (visited[now]) {
			continue;
		}
		else {
			visited[now] = true;
			for (int i = 0; i < mlist[now].size(); i++) {
				edge tmp = mlist[now][i];
				int next = tmp.first;
				int value = tmp.second;
				if (dist[next] > dist[now] + value) {
					dist[next] = dist[now] + value;
					q.push(make_pair(dist[next], next));
				}
			}
		}
	}
	return dist[end];
}


int main() {
	cin >> N >> M;
	mlist.resize(N + 1);
	visited.resize(N + 1);
	dist.resize(N + 1);

	std::fill(dist.begin(), dist.end(), INT_MAX);

	for (int i = 0; i < M; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		mlist[a].push_back(make_pair(b, cost));
	}

	int startidx, endidx;
	cin >> startidx>> endidx;

	cout << dijkstra(startidx, endidx);

}