#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &A, int a, int b) {
	int tmp = A[a];
	A[a] = A[b];
	A[b] = tmp;
}

int find_pivot(vector<int> &A, int start, int end) {
	if ( start + 1 == end) {
		if (A[start] > A[end]) swap(A, start, end);
		return end;
	}

	int M_index = (start + end) / 2;
	swap(A, start, M_index);

	int pivot = A[start];
	int i = start + 1;
	int j = end;

	while (i <= j) {
		while (j >= start + 1 && A[j] > pivot) j--;
		while (i <= end && A[i] < pivot) i++;

		if (i < j) swap(A, i, j);
		else break;
	}
	A[start] = A[j];
	A[j] = pivot;
	return j; //경계부분
}

void quick_sort(vector<int> &A, int start, int end, int K) {
	int pivot = find_pivot(A, start, end);
	if (pivot == K) return;
	else if (K < pivot) quick_sort(A, start, pivot - 1, K);
	else quick_sort(A, pivot + 1, end, K);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int>A(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	quick_sort(A, 0, N - 1, K - 1);
	cout << A[K - 1];
}