#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> mypair;

mypair A[500000];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		A[i] = { tmp, i };
	}

	sort(A, A + N);

	int max = 0;

	for (int i = 0; i < N; i++) {
		if (A[i].second - i + 1 > max) {
			max = A[i].second - i + 1;
		}
	}
	cout << max;
}