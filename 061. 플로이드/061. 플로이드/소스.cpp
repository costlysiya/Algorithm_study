#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

static int n, m;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> m;

    vector<vector<long>> Dist(n+1, vector<long>(n+1, LONG_MAX));

    for (int i = 0; i < n+1; i++) {
        Dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        if (Dist[s][e] > c) {
            Dist[s][e] = c;
        }
    }

    for (int k = 1; k < n+1; k++) {
        for (int s = 1; s < n+1; s++) {
            for (int e = 1; e < n+1; e++) {
                //오버플로우 방지를 위해 확인
                if (Dist[s][k] != LONG_MAX && Dist[k][e] != LONG_MAX) {
                    Dist[s][e] = min(Dist[s][e], Dist[s][k] + Dist[k][e]);
                }
            }
        }
    }

    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < n+1; j++) {
            if (Dist[i][j] == LONG_MAX) {
                cout << 0;
            }
            else {
                cout << Dist[i][j];
            }
            cout << " ";
        }
        cout << '\n';
    }
    return 0;
}