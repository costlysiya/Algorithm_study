#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {

	priority_queue<int, vector<int>, greater<int>> minus;
	priority_queue<int, vector<int>, less<int>> plus;
	vector<int> answerV;

	int N;
	bool zero = false;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;

		if (tmp < 0) {
			minus.push(tmp);
		}
		else if (tmp > 0) {
			plus.push(tmp);
		}
		else
			zero = true;
	}

	int num1, num2;

	while (plus.size() > 1) {
		num1 = plus.top();
		plus.pop();
		num2 = plus.top();
		plus.pop();
		if (num1!=1 && num2!=1)
			answerV.push_back(num1 * num2);
		else {
			answerV.push_back(num1);
			answerV.push_back(num2);
		}
	}

	if (!plus.empty())
		answerV.push_back(plus.top());

	while (minus.size() > 1) {
		num1 = minus.top();
		minus.pop();
		num2 = minus.top();
		minus.pop();
		answerV.push_back(num1 * num2);
	}

	if (!minus.empty() && !zero) {
		answerV.push_back(minus.top());
	}
		

	int sum = 0;

	for (int i = 0; i < answerV.size(); i++) {
		sum += answerV[i];
	}

	cout << sum;
}