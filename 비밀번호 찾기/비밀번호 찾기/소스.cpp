#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<string, string>> note;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	note.resize(N+1);

	for (int i = 0; i < N; i++) {
		string webpage, pw;
		cin >> webpage >> pw;
		note[i] = { webpage, pw };
	}

	sort(note.begin(), note.end());

	for (int i = 0; i < M; i++) {
		string target;
		cin >> target;
		
		int start = 0; int end = N;
		while (start <= end) {
			auto mid = note[(start + end) / 2];
			if (target == mid.first) {
				cout << mid.second << '\n';
				break;
			}
			else if (target < mid.first) {
				end = (start + end) / 2 - 1;
			}
			else {
				start = (start + end) / 2 + 1;
			}
		}
	}

	return 0;
}