#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

void solve(int N) {
	stack<pair<long long,long long>> st; //height, start_idx of using that height
	long long max_area = 0;

	for (int i = 0; i <= N; i++) {
		long long h;
		if (i < N) cin >> h;
		else h = 0; //마지막에 높이 0을 넣어서 스택을 비움

		long long start_idx = i;

		//현재 들어온 높이보다 스택에 더 높은 높이가 있을때
		while (!st.empty() && st.top().first > h) {
			long long height = st.top().first;
			start_idx = st.top().second; //이 높이가 시작됐던 가장 왼쪽 위치
			st.pop();
			//현재 들어온 높이에 맞춰서 넓이 다시 계산.
			max_area = max(max_area, height * (i - start_idx));
		}
		//새로 들어온 막대 넣어주기.
		//현재 들어온 막대가 제일 높은 경우 그냥 현재 막대를 바로 넣음
		//--> 다음 막대가 현재보다 더 높은경우 스택에 있는 낮은 높이들을 하나씩 비교, 최대넓이 계산함.
		st.push({ h, start_idx });
	}
	cout << max_area << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;

	while (N != 0) {
		solve(N);
		cin >> N;
	}

	return 0;
}