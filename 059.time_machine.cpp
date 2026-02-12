#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> edge;
static int N, M;
static vector<edge> edges;
static vector<int> dist;


int main(){
    cin>>N>>M;
    edges.resize(M+1);
    dist.resize(N+1);

    for(int i=0; i<M; i++){
        int s, e, cost;
        cin>>s>>e>>cost;
        edges[i] = make_tuple(s,e,cost);
    }

    for (int i=0; i<M; i++){
        int start = get<0>(edges[i]);
        int end = get<1>(edges[i]);
        int weight = get<2>(edges[i]);

        cout << start << " -> " << end << " (cost: " << weight << ")\n";
    }

    return 0;
}