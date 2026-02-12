#include <iostream>
#include <cmath>
#include <string>

using namespace std;
long A[10000001];

bool check_P(int n) {
	string tmp_str = to_string(n);
	char const* tmp = tmp_str.c_str();

	int start = 0;
	int end = tmp_str.size()-1;

	while (start < end) {
		if (tmp[start] != tmp[end]) return false;
		start++; end--;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long N; 
	cin >> N;

	for (int i = 2; i < 10000001; i++) {
		A[i] = i;
	}

	for (int i = 2; i < sqrt(10000001); i++) {
		if (A[i] == 0) continue;
		for (int j = i + i; j < 10000001; j = j + i) {
			A[j] = 0;
		}
	}

	//for (int i = N; i < 1000001; i++) {
	//	if (A[i] != 0 && check_P(A[i])) {
	//		cout << A[i];
	//		break;
	//	}
	//} Æ²·ÈÀ½

	int i = N;
	while (true) {
		if (A[i] != 0) {
			int result = A[i];
			if (check_P(result)) {
				cout << result << '\n';
				break;
			}
		}
		i++;
	}
}