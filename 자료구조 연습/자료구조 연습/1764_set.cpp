#include <bits/stdc++.h>
using namespace std;
int N, M;

int main() {
	cin >> N >> M;
	//set은 자동정렬, find 속도 O(logN)으로 매우 빠름
	set<string> listen;
	vector<string> answer;

	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;
		listen.insert(name);
	}

	for (int i = 0; i < M; i++) {
		string name;
		cin >> name;

		if (listen.find(name) != listen.end()) {
			answer.push_back(name);
		}
	}

	cout << answer.size() << '\n';
	sort(answer.begin(), answer.end());
	for (string s : answer) {
		cout << s << '\n';
	}
	return 0;

}