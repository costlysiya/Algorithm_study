#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

struct UnionFind {
	vector<int>parent;

	UnionFind(int n) {
		parent.resize(n + 1);
		for (int i = 0; i <= n; i++) {
			parent[i] = i;
		}
	}

	int find(int x) {
		if (parent[x] == x) return x;
		return parent[x] = find(parent[x]);
	}

	void unite(int x, int y) {
		int rootX = find(x);
		int rootY = find(y);
		parent[rootY] = rootX;
	}

	bool isSame(int x, int y) {
		return find(x) == find(y);
	}
};


static int V, E;
typedef tuple<int, int, int> edge;
static vector<edge> edges;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;
	edges.resize(E);

	for (int i = 0; i < E; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		edges[i] = make_tuple(s, e, c);
	}

	sort(edges.begin(), edges.end(), [](const auto& a, const auto& b) {
		return get<2>(a) < get<2>(b);
		});

	UnionFind uf(V);
	int EdgeNum = 0;
	int weight = 0;

	while (EdgeNum < V - 1) {
		for (int i = 0; i < E; i++) {
			int s, e, c;
			s = get<0>(edges[i]);
			e = get<1>(edges[i]);
			c = get<2>(edges[i]);

			if (uf.find(s) != uf.find(e)) {
				uf.unite(s, e);
				weight += c;
				EdgeNum++;
			}
		}
	}

	cout << weight;

	return 0;
}