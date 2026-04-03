#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	stack<int> st;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string commend;
		cin >> commend;
		
		if (commend == "push") {
			int x; cin >> x;
			st.push(x);
		}
		else if (commend == "pop") {
			if (!st.empty()) {
				cout << st.top() <<'\n';
				st.pop();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (commend == "size") {
			cout << st.size() << '\n';
		}
		else if (commend == "empty") {
			cout << (st.empty()) ? 1 : 0;
			cout << '\n';
		}
		else if (commend == "top") {
			if (!st.empty()) {
				cout << st.top() << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
	}

	return 0;
}