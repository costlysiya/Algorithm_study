#include <iostream>
#include <climits>
using namespace std;
static int INF = 1000000 * 16 + 1;
static int N;
static int W[16][16]; // 비용 저장
//현재 i에 있을때, [j] 리스트 만큼 방문했고, 남은 도시 모두를 경유하는 최소비용
//j에는 2진수로 방문한 도시 표시. 1이면 방문, 0이면 미방문
static int D[16][1<<16]; 

int tsp(int c, int v) { //현재 어디에 있고, 어디를 방문했는지(비트마스크) 입력 받음
	if (v == (1 << N) - 1) {//모든 노드를 방문했을 때
		//길이 없으면 INT_MAX반환
		return W[c][0] == 0 ? INF : W[c][0];
	}

	if (D[c][v] != 0) return D[c][v];

	int min_val = INF;

	for (int i = 0; i < N; i++) {
		//방문한 적 없고, 갈 수 있을 때
		if ((v & (1 << i))==0 && W[c][i] != 0) {
			min_val = min(min_val, tsp(i, (v | (1 << i))) + W[c][i]);
		}

	}
	D[c][v] = min_val;
	return D[c][v];
}

int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}


	cout << tsp(0, 1);

	return 0;
}