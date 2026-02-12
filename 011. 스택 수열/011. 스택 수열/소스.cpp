#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int N;
	cin >> N;

	int num = 1;
	stack<int> mystack;
	vector<char> answer;
	bool tf = true;

	for (int i = 0; i < N; i++) {
		int now;
		cin >> now;

		if (now >= num) {
			while (num <= now) {
				mystack.push(num);
				answer.push_back('+');
				num++;
			}
			mystack.pop();
			answer.push_back('-');
		}
		else {
			if (mystack.top() == now) {
				mystack.pop();
				answer.push_back('-');
			}
			else {
				tf = false;
			}
		}
	}

	if (tf == false) {
		cout << "NO";
	}
	else {
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << '\n';
		}
	}

}