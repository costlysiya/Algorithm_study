#include <iostream>
#include <vector>
using namespace std;

vector<int> A;
vector<int> tmp;

void merge(int start, int end) {

	int mid = (start + end) / 2;
	int i = start, j = mid + 1, k = start;

	while (i <= mid && j <= end) {
		if (A[i] <= A[j])
			tmp[k++] = A[i++];
		else
			tmp[k++] = A[j++];
	}

	int z = i > mid ? j : i;

	while (k <= end)
		tmp[k++] = A[z++];

	for (int i = start; i <= end; i++) {
		A[i] = tmp[i];
	}
	
}

void partition(int start, int end) {
	int mid;
	if (start < end) {
		mid = (start + end) / 2;
		partition(start, mid);
		partition(mid + 1, end);
		merge(start, end);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	A = vector<int>(N + 1, 0);
	tmp = vector<int>(N + 1, 0);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	partition(0, N - 1);

	for (int i = 0; i < N; i++) {
		cout << A[i] << '\n';
	}
}