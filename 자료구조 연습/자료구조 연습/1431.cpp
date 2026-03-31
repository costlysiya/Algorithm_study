#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>

using namespace std;

bool cmp(const string& a, const string& b) {
	//1. 길이 비교
	if (a.size() != b.size()) return a.size() < b.size();

	//2. 숫자 합 비교
	int a_cnt = 0, b_cnt = 0;
	for (char c : a) {
		if (c >= '1' && c <= '9') a_cnt += c - '0';
	}
	for (char c : b) {
		if (c >= '1' && c <= '9') b_cnt += c - '0';
	}
	if (a_cnt != b_cnt) return a_cnt < b_cnt; //cnt가 작은게 먼저

	//3. 사전순 비교
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == b[i]) continue;
		bool a_is_num = isdigit(a[i]);
		bool b_is_num = isdigit(b[i]);
		if (a_is_num != b_is_num) return a_is_num; //숫자인게 먼저
		return a[i] < b[i];
	}

	return false;
}

int main() {
	int N;
	cin >> N;
	vector<string> serial(N);
	for (int i = 0; i < N; i++) {
		cin >> serial[i];
	}

	sort(serial.begin(), serial.end(), cmp);
	
	for (string s : serial) {
		cout << s << '\n';
	}

	return 0;
}