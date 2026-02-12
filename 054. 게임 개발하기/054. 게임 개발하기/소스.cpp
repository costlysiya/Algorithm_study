#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<vector<int>> A;
	vector<int> T;
	vector<int> indegree;
	vector<int> ans;
	queue<int> Q;

	A.resize(N + 1);
	T.resize(N + 1);
	indegree.resize(N + 1);
	ans.resize(N + 1);

	for (int i = 1; i < N + 1; i++) {
		int a;
		cin >> a;
		T[i] = a;
		cin >> a;
		while (a != -1) {
			A[a].push_back(i);
			indegree[i]++;
			cin >> a;
		}
	}

	for (int i = 1; i < N + 1; i++) {
		if (indegree[i] == 0) {
			Q.push(i);
		}
	}

	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		//cout << "now: " << now << endl;
		for (int next : A[now]) {
			indegree[next]--;
			ans[next] = max(ans[next], ans[now] + T[now]);
			if (indegree[next] == 0) {
				Q.push(next);
				//cout << "ans[" << next << "]: " << ans[next] << endl;
			}
		}
	}

	for (int i = 1; i < N + 1; i++) {
		cout << ans[i] + T[i] << endl;
	}

	//for (int i = 1; i < N + 1; i++) {
	//	cout << "i: " << i << ", ";
	//	for (int a:A[i]) {
	//		cout << a << " ";
	//	}
	//	cout << endl;
	//}

}