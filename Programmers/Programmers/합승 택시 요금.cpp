#include <bits/stdc++.h>
using namespace std;

int dist[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int ans = INT_MAX;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = (i == j) ? 0 : 1e9;
        }
    }

    for (vector<int> v : fares) {
        dist[v[0]][v[1]] = v[2];
        dist[v[1]][v[0]] = v[2];
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] == 1e9 || dist[k][j] == 1e9) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        if (dist[s][k] == 1e9 || dist[k][a] == 1e9 || dist[k][b] == 1e9) continue;
        ans = min(ans, dist[s][k] + dist[k][a] + dist[k][b]);
    }

    return ans;
}