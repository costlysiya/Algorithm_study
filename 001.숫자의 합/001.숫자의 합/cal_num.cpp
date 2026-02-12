#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, sum = 0;
	string nums;
	cin >> N;
	cin >> nums;

	for (int i = 0; i < nums.length(); i++) {
		sum += nums[i] - '0';
	}
	cout << sum;
	return 0;
}