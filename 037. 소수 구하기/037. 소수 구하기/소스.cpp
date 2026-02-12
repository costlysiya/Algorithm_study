#include<iostream>
#include<vector>
using namespace std;
bool A[1000001] = { false };

int main() {
	int M, N;
	cin >> M >> N;


	for (int i = 0; i <= N; i++) {
		A[i] = true;
	}

	A[1] = false;

	for (int i = 2; i <= N; i++) {
		if (A[i] == true) {
			for (int j = 2; j * i <= N; j++) {
				A[j * i] = false;
			}
		}
	}

	for (int i = M; i <= N; i++) {
		if (A[i] == true) cout << i << '\n';
	}
}