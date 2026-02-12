#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, max_score = 0;
	float sum = 0;
	vector<int> scores;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int score = 0;
		cin >> score;
		sum += score;
		scores.push_back(score);

		if (score > max_score) {
			max_score = score;
		}
	}

	cout << sum / max_score * 100/N;
	return 0;
}