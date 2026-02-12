#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>
using namespace std;

typedef tuple<int, int, int> edge;
static int N, M;
static vector<edge> edges;
static vector<long> dist;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    edges.resize(M + 1);
    dist.resize(N + 1);
    

    //최단 거리 리스트 생성
    std::fill(dist.begin(), dist.end(), LONG_MAX);
    dist[1] = 0;

    //엣지 리스트 생성
    for (int i = 0; i < M; i++) {
        int s, e, cost;
        cin >> s >> e >> cost;
        edges[i] = make_tuple(s, e, cost);
    }

    //최단 거리 리스트 갱신
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M; j++) { //엣지 개수 만큼
            long start = get<0>(edges[j]);
            long end = get<1>(edges[j]);
            long cost = get<2>(edges[j]);

            if (dist[start] != LONG_MAX && dist[end] > dist[start] + cost) {
                dist[end] = dist[start] + cost;
            }    
        } 
    }

    bool minusCycle = false;

    //음수 사이클 체크
    for (int i = 0; i < M; i++) {
        edge mEdge = edges[i];
        long start = get<0>(mEdge);
        long end = get<1>(mEdge);
        long cost = get<2>(mEdge);

        if (dist[start] != LONG_MAX && dist[end] > dist[start] + cost) {
            minusCycle = true;
        }
    }

    if (!minusCycle) {
        for (int i = 2; i <= N; i++) {
            if (dist[i] == LONG_MAX)
                cout << -1 << '\n';
            else
                cout << dist[i] << '\n';
        }
    }
    else
        cout << -1 << '\n';

    return 0;
}