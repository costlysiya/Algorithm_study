#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static int N, M;
vector<int> depth;
vector<int> parent;
vector<bool>visited;
vector<vector<int>> tree;

void BFS(int node) {
	queue<int> myqueue;
	myqueue.push(node);
	visited[node] = true;
	int level = 1; //트리의 깊이
	int now_size = 1; //현재 층에 있는 노드의 개수
	int count = 0; //현재 층에서 이미 처리한 노드의 개수

	while (!myqueue.empty()) {
		int now_node = myqueue.front();
		myqueue.pop();
		for (int next : tree[now_node]) {
			if (!visited[next]) {
				visited[next] = true;
				myqueue.push(next);
				parent[next] = now_node;
				depth[next] = level;
			}
		}
		count++;
		if (count == now_size) { //현재 층의 노드를 다 살펴봤을때
			count = 0;
			now_size = myqueue.size(); //다음 층 노드 개수
			level++;
		}
	}
}

int findLCA(int a, int b) {
	if (depth[a] < depth[b]) {
		int temp = a;
		a = b;
		b = temp;
	}
	while (depth[a] != depth[b]) { //두 노드의 깊이 맞추기
		a = parent[a];
	}
	while (a != b) { //같은 조상이 나올 떄 까지 한칸씩 올림
		a = parent[a];
		b = parent[b];
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	
	tree.resize(N + 1);
	depth.resize(N + 1);
	parent.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	BFS(1);
	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		int LCA = findLCA(a, b);
		cout << LCA << '\n';

	}

}