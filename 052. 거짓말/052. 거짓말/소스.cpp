#include <iostream>
#include <vector>
using namespace std;

vector<int>trueP;
int A[51] = { 0 };

int find(int idx) {
	if (idx == A[idx]) return idx;
	else {
		return A[idx] = find(A[idx]);
	}
}

void Union(int a, int b) {
	int a_root = find(a);
	int b_root = find(b);

	a_root < b_root ? A[b_root] = a_root : A[a_root] = b_root;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;	cin >> N >> M;
	int n;	cin >> n;

	for (int i = 0; i <= N; i++) {
		A[i] = i;
	}

	vector<vector<int>>party;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		trueP.push_back(x);
	}
	
	for (int i = 0; i < M; i++) {
		int k;	cin >> k;
		vector<int>p;
		for (int j = 0; j < k; j++) {
			int x;	cin >> x;
			p.push_back(x);
		}
		party.push_back(p);
	}

	for (int i = 0; i < M; i++) {
		int firstPeople = party[i][0];
		for (int j = 1; j < party[i].size(); j++) {
			Union(firstPeople, party[i][j]);
		}
	}

	int cnt = 0;

	for (int i = 0; i < party.size(); i++) {
		bool take = true;
		int cur = party[i][0];
		for (int j = 0; j < trueP.size(); j++) {
			if (find(cur) == find(trueP[j])) {
				take = false;
				break;
			}
		}
		if (take) cnt++;
	}
	cout << cnt;

}