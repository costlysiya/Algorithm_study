#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
	string str; int M;
	cin >> str >> M;

	list<char>clist;

	for (char c : str) {
		clist.push_back(c);
	}

	auto it = clist.end();

	for (int k = 0; k < M; k++) {
		char mode;
		cin >> mode;
		if (mode == 'L' && it!= clist.begin()) {
			it--;
		}
		else if (mode == 'D' && it != clist.end()) {
			it++;
		}
		else if (mode == 'B' && it!= clist.begin()) {
			it--;
			it = clist.erase(it);
		}
		else if (mode == 'P') {
			char x;
			cin >> x;
			clist.insert(it, x);
		}

	}

	for (char c : clist) {
		cout << c;
	}


	return 0;
}