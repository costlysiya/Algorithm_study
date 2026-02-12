#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<int> A;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
	}

	for (int i = 1; i < N; i++) {
		int insert_point = i;
		int insert_value = A[i];

		for (int j = i - 1; j >= 0; j--) {
			if (A[j] < A[i]) { //´õ ÀÛÀº °ªÀÌ¸é insertpoint ¹Ù²ãÁÜ.
				insert_point = j + 1;
				break;
			}
			if (j == 0) {
				insert_point = 0;
			}
		}
		for (int j = i; j > insert_point; j--) {
			A[j] = A[j - 1];
		}
		A[insert_point] = insert_value;
	}

	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += A[i] * (N - i);
	}

	cout << sum;
}