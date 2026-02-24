#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	int D[100] = { 0 };
	int T[16];
	int P[16];
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}


	for (int i = N; i > 0; i--) {
		int time = T[i];
		if (i + time <= N+1) {
			D[i] = max(D[i + 1], D[i + time] + P[i]); //상담 안하고 건너 뛴 경우와 상담 하는 경우 비교
		}
		else {
			D[i] = D[i + 1];
		}
		//cout << "D[" << i << "] = " << D[i] << endl;
	}

	cout << D[1];

	return 0;
}