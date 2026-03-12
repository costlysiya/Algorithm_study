#include <iostream>
#include <cmath>
using namespace std;

int parent[3001];
int L[3001][4];

int ccw(long x1, long y1, long x2, long y2, long x3, long y3) {
	long c = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
	
	if (c > 0) return 1;
	if (c == 0) return 0;
	return -1;
}

bool isOverlab(long x1, long y1, long x2, long y2, long x3, long y3, long x4, long y4) {
	if (min(x1, x2) <= max(x3, x4) && min(x3, x4) <= max(x1, x2) && min(y1, y2) <= max(y3, y4) && min(y3, y4) <= max(y1, y2)) {
		return true;
	}
	return false;
}

bool isCross(long x1, long y1, long x2, long y2, long x3, long y3, long x4, long y4) {
	int abc = ccw(x1, y1, x2, y2, x3, y3);
	int abd = ccw(x1, y1, x2, y2, x4, y4);
	int cda = ccw(x3, y3, x4, y4, x1, y1);
	int cdb = ccw(x3, y3, x4, y4, x2, y2);

	if (abc * abd == 0 && cda * cdb == 0) {
		return isOverlab(x1, y1, x2, y2, x3, y3, x4, y4);
	}
	else if (abc * abd <= 0 && cda * cdb <= 0) {
		return true;
	}
	return false;

}

int find(int i) {
	if (parent[i] < 0) {
		return i;
	}
	return parent[i] = find(parent[i]);
}

void Union(int i, int j) {
	int p = find(i);
	int q = find(j);

	if (p == q) { //이미 연결된 경우
		return;
	}
	parent[p] += parent[q]; //p의 부모노드에 q가 속한 선분 그룹의 선분 수 더하기
	parent[q] = p;
}

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		parent[i] = -1;
	}

	for (int i = 1; i <= N; i++) {
		cin >> L[i][0] >> L[i][1] >> L[i][2] >> L[i][3];
		for (int j = 1; j < i; j++) {
			if(isCross(L[j][0],L[j][1],L[j][2],L[j][3],L[i][0], L[i][1],L[i][2], L[i][3])){
				Union(i, j);
			}
		}
	}

	int ans = 0, res = 0;

	for (int i = 1; i <= N; i++) {
		if (parent[i] < 0) { //음수면 부모 노드
			ans++; //그룹의 수 ++
			res = min(res, parent[i]); 
		}
	}
	cout << ans << '\n';
	cout << -res;


	return 0;
}