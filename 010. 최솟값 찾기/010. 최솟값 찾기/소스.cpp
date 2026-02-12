#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;
	cin >> N >> L;

	typedef pair<int, int> Node;
	deque<Node> mydeque;

	for (int i = 0; i < N; i++) {
		int now;
		cin >> now;
		
		while (mydeque.size() && mydeque.back().second > now) {
			mydeque.pop_back();
		}

		mydeque.push_back(Node(i,now));

		if ( mydeque.front().first <= i - L) {
			mydeque.pop_front();
		}

		cout << mydeque.front().second << " ";
	}
}