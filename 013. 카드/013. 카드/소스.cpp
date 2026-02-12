#include <iostream>
#include <queue>
using namespace std;

queue<int> myqueue;

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		myqueue.push(i);
	}

	while (myqueue.size()>1) {
		myqueue.pop();
		int tmp = myqueue.front();
		myqueue.push(tmp);
		myqueue.pop();
	}
	cout << myqueue.front();
}