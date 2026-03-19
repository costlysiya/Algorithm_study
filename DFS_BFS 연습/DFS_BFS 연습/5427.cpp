#include <bits/stdc++.h>
using namespace std;

int N, M;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int fire_dist[1001][1001];
int s_dist[1001][1001];


void solve() {
    cin >> M >> N; // 가로 M, 세로 N
    vector<string> str(N);

    queue<pair<int, int>> Fire;
    queue<pair<int, int>> Person;

    for (int i = 0; i < N; i++) {
        cin >> str[i];
        for (int j = 0; j < M; j++) {
            fire_dist[i][j] = 1e9; // 매우 큰 값으로 초기화 
            s_dist[i][j] = -1;
            if (str[i][j] == '*') { 
                Fire.push({ i, j });
                fire_dist[i][j] = 0;
            }
            else if (str[i][j] == '@') {
                Person.push({ i, j });
                s_dist[i][j] = 0;
            }
        }
    }

    // 1. 불 BFS
    while (!Fire.empty()) {
        auto now = Fire.front(); Fire.pop();
        for (int i = 0; i < 4; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (fire_dist[nx][ny] == 1e9 && str[nx][ny] != '#') {
                fire_dist[nx][ny] = fire_dist[now.first][now.second] + 1;
                Fire.push({ nx, ny });
            }
        }
    }

    // 2. 상근이 BFS
    while (!Person.empty()) {
        auto now = Person.front(); Person.pop();
        for (int i = 0; i < 4; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            // 범위 밖 = 탈출 성공
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
                cout << s_dist[now.first][now.second] + 1 << '\n';
                return; // solve 함수 종료 후 다음 테스트 케이스로
            }

            if (s_dist[nx][ny] == -1 && str[nx][ny] != '#' && s_dist[now.first][now.second] + 1 < fire_dist[nx][ny]) {
                s_dist[nx][ny] = s_dist[now.first][now.second] + 1;
                Person.push({ nx, ny });
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}