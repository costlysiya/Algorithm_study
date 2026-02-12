#include <iostream>
#include <cmath>
using namespace std;
long A[10000001] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long minimum, maximum;
	cin >> minimum >> maximum;



	for (int i = 2; i <= 10000000; i++) {
		A[i] = i;
	}

	for (int i = 2; i <= sqrt(10000001); i++) {
		if (A[i] == 0) continue;
		for (int j = i+i; j < 10000001; j=j+i) {
			A[j] = 0;
		}
	}

	int cnt = 0;

	for (int i = 2; i <= 10000000; i++) {
		if (A[i] != 0) {
			long tmp = A[i];
			while ((double)A[i] <= (double)maximum / (double)tmp) {
				if ((double)A[i] >= (double)minimum / (double)tmp) {
					cnt++;
				}
				tmp *= A[i];
			}
		}
	}

	cout << cnt;
}