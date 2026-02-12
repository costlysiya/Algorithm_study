#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int>coin_value(N, 0);

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (tmp > K)
			break;
		coin_value.push_back(tmp);
	}

	int left = K;
	int cnt = 0;

	for (int i = coin_value.size() - 1; i >= 0; i--) {
		cnt += left / coin_value[i];
		left %= coin_value[i];

		if (left == 0) {
			cout << cnt;
			break;
		}
	}


}