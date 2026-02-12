#include <iostream>
#include <stack>
using namespace std;

stack<int> mystack;
int A[1000000] = {};
int answer[1000000] = {};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	mystack.push(0);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 1; i < N; i++) {
		while (!mystack.empty() && A[i] > A[mystack.top()]) {
			answer[mystack.top()] = A[i];
			mystack.pop();
		}
		mystack.push(i);
	}

	while (!mystack.empty()) {
		answer[mystack.top()] = -1;
		mystack.pop();
	}
	
	for (int i = 0; i < N; i++) {
		cout << answer[i] << " ";
	}
}