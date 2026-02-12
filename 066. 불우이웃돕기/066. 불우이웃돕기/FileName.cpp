#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

static int N;
static vector<int> parent;
static int entireE = 0;
typedef struct Edge {
	int s, e, v;
	bool operator>(const Edge& temp) const {
		return v > temp.v;
	}
}Edge;

static priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

int AlphaToNum(char alpha) {
	int num;
	if (alpha >= 'A' && alpha <= 'Z') {
		num = alpha - 'A' + 27;
	}
	else if (alpha >= 'a' && alpha <= 'z') {
		num = alpha - 'a' + 1;
	}
	else {
		num = alpha - '0';
	}
	entireE += num;
	return num;
}

int find(int a) {
	if (a == parent[a]) return a;
	else
		return parent[a] = find(parent[a]);
}

void unionE(int a, int b) {
	int rootA = find(a);
	int rootB = find(b);
	if (rootA != rootB) {
		parent[rootB] = rootA;
	}
}

int main() {
	cin >> N;
	parent.resize(N);


	for (int i = 0; i < N; i++) {
		string alphas;
		cin >> alphas;
		for (int j = 0; j < N; j++) {
			int v = AlphaToNum(alphas[j]);
			if(i!=j && v!=0){
				pq.push(Edge{i, j, v});				
			}
		}
		parent[i] = i;
	}

	int useEdge = 0;
	int result = 0;
	

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (find(now.s) != find(now.e)) {
			unionE(now.s, now.e);
			result += now.v;
			useEdge++;
		}
	}

	if (useEdge == N - 1) {
		cout << entireE-result;
	}
	else {
		cout << -1;
	}


	return 0;
}