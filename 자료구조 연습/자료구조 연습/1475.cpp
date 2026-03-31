#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string roomnum;
	cin >> roomnum;

	vector<int> cnt(11);

	for (char c : roomnum) {
		if (c == '6' || c == '9') {
			if (cnt[6] > cnt[9]) cnt[9]++;
			else cnt[6]++;
		}
		else {
			cnt[c - '0']++;
		}
	}

	sort(cnt.begin(), cnt.end(), greater<>());
	cout << cnt[0];

	return 0;
}