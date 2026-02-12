#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	int A[1000] = { 0 };

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}


	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < N - i - 1; j++) {
			if (A[j] > A[j + 1]) {
				int tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
				cnt++;
			}
		}
		if (cnt == 0)
			break;
	}

	for (int i = 0; i < N; i++) {
		cout << A[i] << "\n";
	}
}