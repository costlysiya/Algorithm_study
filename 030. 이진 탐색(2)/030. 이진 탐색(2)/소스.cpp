#include <iostream>
#include <vector>
using namespace std;
vector<int> A;
int N, M;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	A = vector<int>(N, 0);
	int videos = 0;

	int start = 0;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (start < A[i]) start = A[i];
		videos += A[i];
	}

	int end = videos;
	int cnt = 1;
	

	while (start <= end) {
		int sum = 0;
		int mid = (start + end) / 2;
		cnt = 1;
		for (int i = 0; i < N; i++) {
			if (sum + A[i] > mid) {
				sum = A[i];
				cnt++;
			}
			else {
				sum += A[i];
			}
		}

		if (cnt <= M) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}

	}
	cout << start << endl;
}