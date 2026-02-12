#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string>split(string input, char deli) {
	vector<string>result;
	stringstream mystream(input);
	string splitdata;

	while (getline(mystream, splitdata, deli)) {
		result.push_back(splitdata);
	}
	return result;
}

int mySum(string a) {
	int sum = 0;
	vector<string> tmp = split(a, '+');

	for (int i = 0; i < tmp.size(); i++) {
		sum += stoi(tmp[i]);
	}
	return sum;
}

int main() {
	string example;
	cin >> example;

	int answer = 0;

	vector<string>str = split(example, '-');

	for (int i = 0; i < str.size(); i++) {
		int tmp = mySum(str[i]);
		
		if (i == 0) {
			answer = tmp;
		}
		else {
			answer -= tmp;
		}
	}
	cout << answer;
}