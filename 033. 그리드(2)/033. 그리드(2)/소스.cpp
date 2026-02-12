#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct cmp {
	bool operator()(int& x, int& y) {
		if (x < y) return false;
		else return true;
	}
};

int main() {
	int N;
	cin >> N;

	priority_queue<int, vector<int>, cmp>cards;

	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		cards.push(k);
	}

	int cnt = 0;

	while (cards.size()!=1) {
		int mytop = cards.top();
		cards.pop();
		int mytop2 = cards.top();
		cards.pop();
		cnt += mytop + mytop2;
		cards.push(mytop + mytop2);
	}

	cout << cnt;
}