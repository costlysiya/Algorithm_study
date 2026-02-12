#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> V(32001);
vector<int>cnt(32001,0);

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		V[x].push_back(y);
		cnt[y]++;
	}


	queue<int> ans;

	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) ans.push(i);
	}

	while(!ans.empty()){
		int now = ans.front();
		ans.pop();
		cout << now << " ";
		for (int next : V[now]) {
			cnt[next]--;
			if (cnt[next] == 0) {
				ans.push(next);
			}
		}
	}
}