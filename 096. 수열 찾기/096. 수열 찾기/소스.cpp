#include <iostream>
#include <vector>
using namespace std;

static int N, maxLength;
static int B[1000001]; //길이가 i인 증가 부분 수열 중 가장 작은 마지막 값
static int A[1000001]; //수열 저장
static int D[1000001]; //0~i탐색시, i를 포함하는 최장 수열 길이 저장
static int ans[1000001]; 

int binarysearch(int l, int r, int now) { //now값 보다 처음으로 커지거나 같은 값 찾기
	int mid;
	while (l < r) {
		mid = (l + r) / 2;
		if (B[mid] >= now) r = mid; //mid값 또한 후보에 들어감
		else {
			l = mid + 1;
		}
	}
	return r;
}



int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	int index;
	B[++maxLength] = A[1];
	D[1] = 1;

	for (int i = 2; i <= N; i++) {
		if (B[maxLength] < A[i]) { //들어온 값이 현재 최장 수열의 최댓값 보다 큼
			B[++maxLength] = A[i];
			D[i] = maxLength;
		}
		else { //들어온 값이 현재 최장 수열의 최댓값 보다 작거나 같음
			//B배열에서 현재 들어온 값보다 처음으로 크거나 같아지는 원소의 인덱스 찾음
			index = binarysearch(1, maxLength, A[i]);
			B[index] = A[i];// 그 값을 현재 값으로 대체함
			D[i] = index;
		}
	}

	cout << maxLength << '\n';
	index = maxLength;
	int x = B[maxLength] + 1;

	for (int i = N; i >= 1; i--) {
		if (D[i] == index && A[i] < x) { //최대길이인 곳, 현재 최댓값보다 작으면
			ans[index] = A[i]; //정답 배열에 추가
			x = A[i]; //현재 최댓값 갱신
			index--; //최대 길이 -1
		}
	}

	for (int i = 1; i <= maxLength; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}