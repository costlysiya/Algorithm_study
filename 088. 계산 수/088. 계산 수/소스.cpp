#include <iostream>
#include <cmath>
using namespace std;

//D[i][j] = 길이가 i이고 마지막 숫자가 j인 계단의 개수
long long D[101][10];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i < 10; i++) {
		D[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		D[i][0] = D[i - 1][1];
		D[i][9] = D[i - 1][8];
		for (int j = 1; j < 9; j++) {
			D[i][j] = (D[i - 1][j - 1] + D[i - 1][j + 1])%1000000000;
		}
	}

	long answer = 0;
	for (int j = 0; j <= 9; j++) {
		answer = (answer + D[N][j]) % 1000000000;
	}

	cout << answer;
	return 0;
}