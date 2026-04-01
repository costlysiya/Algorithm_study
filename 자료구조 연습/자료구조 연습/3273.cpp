#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, x;
	cin >> n;

	vector<int> nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	cin >> x;

	sort(nums.begin(), nums.end());

	int left = 0, right = n-1;
	int cnt = 0;

	while (left < right) {
		int cal = nums[left] + nums[right];
		if (cal == x) {
			cnt++;
			left++; right--;
		} 
		else if (cal > x) {
			right--;
		}
		else {
			left++;
		}
	}

	cout << cnt;
	return 0;
}