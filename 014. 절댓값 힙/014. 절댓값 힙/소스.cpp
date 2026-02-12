#include <iostream>
#include <queue>
#include<cmath>
using namespace std;

struct cmp {
	//bool operator()(int x, int y) {
	//	if (abs(x) > abs(y)) {
	//		return true;
	//	}
	//	else if (abs(x) == abs(y)) {
	//		if (x > y) {
	//			return true;
	//		}
	//	}
	//	return false;
	//}

	bool operator()(int x, int y) {
		if (abs(x) == abs(y)) {
			return x > y;
		}
		else {
			return abs(x) > abs(y);
		}
	}
};

priority_queue<int, vector<int>, cmp> pq;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;

		if (tmp == 0 && !pq.empty()) {
			cout << pq.top() << "\n";
			pq.pop();
		}
		else if (tmp == 0 && pq.empty()) {
			cout << 0 << "\n";
		}
		else {
			pq.push(tmp);
		}
	}
}