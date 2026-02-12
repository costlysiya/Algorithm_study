#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>>A;
int cnt[10001] = { 0 };
bool visited[10001];
int N, M;

void BFS(int node) {
	queue<int>myqueue;
	myqueue.push(node);
	visited[node] = true;

	while (!myqueue.empty()) {
		int top_node = myqueue.front();
		myqueue.pop();
		for (int i : A[top_node]) {
			if (!visited[i]) {
				myqueue.push(i);
				visited[i] = true;
				cnt[i]++;
			}	
		}
	}

	//for (int i = 1; i <= N; i++) {
	//	if (visited[i] == true) {
	//		cnt[i] += 1;
	//	}
	//}

}

int main() {

	cin >> N >> M;

	A.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		A[x].push_back(y);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visited[j] = false;
		}
		BFS(i);
	}



	vector<int>ans;
	int max = 0;
	for (int i = 1; i <= N; i++) {
		if (cnt[i] > max) {
			max = cnt[i];
			ans.clear();
			ans.push_back(i);
		}
		else if (cnt[i] == max) {
			ans.push_back(i);
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}