#include <iostream>
using namespace std;

int main() {
	int count = 1;
	long sum = 1;
	int N;
	cin >> N;

	int start_index = 1;
	int end_index = 1;

	while (end_index != N) {
		if (sum < N) {
			end_index++;
			sum += end_index;
		}
		else if (sum > N) {
			sum -= start_index;
			start_index++;
		}
		else {
			count++;
			end_index++;
			sum += end_index;
		}
	}
	cout << count;
}