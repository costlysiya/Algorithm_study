#include <iostream>
#include <vector>
#include<tuple>
#include <limits.h>
using namespace std;

typedef tuple<int, int, int> edge;
static int N, M, startEdge, endEdge;
static vector<edge> edges;
static vector<long> dist;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> startEdge >> endEdge >> M;
	edges.resize(M);
	dist.resize(N);
	std::fill(dist.begin(), dist.end(), LONG_MAX);
	
	//엣지리스트
	for (int i = 0; i < M; i++) {
		int s, e, cost;
		cin >> s >> e >> cost;
		edges[i] = make_tuple(s, e, cost);
	}

	//버는 돈 빼기 (엣지리스트 업데이트)
	for (int i = 0; i < N; i++) {
		int cost;
		cin >> cost;
		if (i == startEdge) dist[startEdge] = -cost;

		for (int j = 0; j < M; j++) {
			if (get<1>(edges[j]) == i) {
				get<2>(edges[j]) -= cost;
			}
		}
		
	}

	//벨만-포드 알고리즘
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			long start = get<0>(edges[j]);
			long end = get<1>(edges[j]);
			long cost = get<2>(edges[j]);
			if (dist[start] != LONG_MAX && dist[end] > dist[start] + cost) {
				dist[end] = dist[start] + cost;
			}
		}
	}

	//N번 만큼 추가로 돌리면서 사이클로 도달할 수 있는 노드들 충분히 확인
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			edge mEdge = edges[j];
			long start = get<0>(mEdge);
			long end = get<1>(mEdge);
			long cost = get<2>(mEdge);

			if (dist[start] == LONG_MAX) continue;

			if (dist[start] == LONG_MIN || dist[end] > dist[start] + cost) {
				dist[end] = LONG_MIN;
			}
		}
	}


	if (dist[endEdge] == LONG_MAX) {
		cout << "gg";
	}
	else if (dist[endEdge] == LONG_MIN) {
		cout << "Gee";
	}
	else
		cout << -dist[endEdge];

	return 0;

}