#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> A;

void swap(int idx1, int idx2) {
	int tmp = A[idx1];
	A[idx1] = A[idx2];
	A[idx2] = tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		A.push_back(stoi(s.substr(i, 1)));
	}

	for (int i = 0; i < s.size(); i++) {
		int maxIndex = max_element(A.begin() + i, A.end()) - A.begin();
		swap(maxIndex, i);
	}

	for (int i = 0; i < A.size(); i++) {
		cout << A[i];
	}
}