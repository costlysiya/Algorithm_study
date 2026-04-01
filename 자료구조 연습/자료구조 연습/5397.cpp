#include <iostream>
#include <list>
#include <string>
using namespace std;

void solve() {
	list<char>clist;
	string str;
	cin >> str;

	auto it = clist.begin(); //it은 해당 문자의 앞쪽에 달린 커서라 생각.
	for (char c : str) {
		if (c == '<') {
			if (it != clist.begin()) it--; //하나 앞 가리키기
			else continue;
		}
		else if (c == '-') {
			if (it != clist.begin()) it = clist.erase(--it); //필수: erase하고 it으로 다시 받아주기
			else continue;
		}
		else if (c == '>') {
			if (it != clist.end()) it++;
			else continue;
		}
		else{
			clist.insert(it, c);
		}
	}

	for (char c : clist) {
		cout << c;
	}
	cout << endl;
}

int main() {
	int testN;
	cin >> testN;

	for (int i = 0; i < testN; i++) {
		solve();
	}

	return 0;
}