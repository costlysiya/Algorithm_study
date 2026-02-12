#include<iostream>
#include<vector>
using namespace std;
static int N, delete_node, answer = 0;
static vector<vector<int>> Tree;
static vector<bool> visited;

void DFS(int n) {
	visited[n] = true;
	int child_node = 0;

	for (int m : Tree[n]) {
		if (!visited[m] && m!=delete_node) {
			child_node++;
			visited[m] = true;
			DFS(m);
		}
	}
	if (child_node == 0) {
		answer++;
	}
}

int main() {
	cin >> N;
	Tree.resize(N);
	visited.resize(N);

	int root;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		if (t == -1) root = i;
		else {
			Tree[i].push_back(t);
			Tree[t].push_back(i);
		}

	}

	cin >> delete_node;
	
	if (delete_node == root) {
		cout << 0 << '\n';
	}
	else {
		DFS(root);
		cout << answer << '\n';
	}



	return 0;
}