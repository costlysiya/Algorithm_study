#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	stack<pair<int,int>> st; //order, height

	for (int i = 1; i <= N; i++) {
		int x; 
		cin >> x;

		//앞에 있는게 나보다 더 작은경우 pop함
		//--> 내 뒤에 오는것들은 모두 나에게 신호가 올 것이기 때문
		while (!st.empty() && st.top().second < x) {
			st.pop();
		}

		if (!st.empty()) {
			cout << st.top().first << " ";
		}
		else {
			cout << 0 << " ";
		}

		st.push({i, x });
	}
	
	return 0;
}