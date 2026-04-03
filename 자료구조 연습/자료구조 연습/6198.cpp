#include<iostream>
#include<stack>
#include<vector>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int>st;
	int N; cin >> N;
	long long cnt = 0;

	for (int i = 1; i <= N; i++) {
		int height;
		cin >> height; 

		//지금 들어온 빌딩을 볼 수 있는 왼쪽 빌딩들만 stack에 남기기.
		//--> 스택에 남아있는 개수 만큼이 현재 빌딩을 볼 수 있는 빌딩의 수.
		//출력은 각 빌딩에서 볼 수 있는 건물의 수의 합산이므로 
		// '나를 볼 수 있는 건물들'의 수를 매번 더해줘도 정답을 구할 수 있음
		while (!st.empty()) {
			auto last = st.top();
			if (last <= height) st.pop();
			else break;
		}
		cnt += st.size();
		st.push(height);
	}
	cout << cnt;
}