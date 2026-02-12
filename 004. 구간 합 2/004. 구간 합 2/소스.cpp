#include <iostream>
using namespace std;


int S[1025][1025] = { 0 };

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		int tmp;
		for (int j = 1; j <= N; j++) {
			cin >> tmp;
			S[i][j] = S[i][j - 1] + tmp;
		}
	}

	for (int i = 0; i < M; i++) {
		int startX, startY, endX, endY;
		cin >> startX >> startY >> endX >> endY;
		int sum = 0;
		for (int j = startX; j <= endX; j++) {
			sum += S[j][endY] - S[j][startY - 1];
		}
		cout << sum << "\n";
	}
}