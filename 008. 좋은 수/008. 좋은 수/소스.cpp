#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> A(N, 0);
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());

	long sum = 0;
	int count = 0;
	
	int start_index = 0;
	int end_index =  N - 1;

	if (N < 3) {
		return count;
	}

	for (int k=0; k<N; k++){
		int num_index = k;
		while (start_index < end_index) {
			sum = A[start_index] + A[end_index];
			if (sum == A[num_index]) {
				if (start_index != k && end_index != k) {
					count++;
					break;
				}
				else if (start_index == k) {
					start_index++;
				}
				else if (end_index == k) {
					end_index--;
				}
			}
			else if (sum < A[num_index]) {
				start_index++;
			}
			else if (sum > A[num_index]) {
				end_index--;
			}
		}
		start_index = 0;
		end_index = N - 1;
	}
	
	cout << count;
}