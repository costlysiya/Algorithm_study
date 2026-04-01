#include <iostream>
#include <list>
#include <vector>
using namespace std;
list<int> circle;

int main() {
	int N, K; 
	cin >> N >> K;
	
	vector<int>answer;
	
	for (int i = 1; i <= N; i++) {
		circle.push_back(i);
	}

	//첫번째 out 출력
	auto it = circle.begin();
	cout << "<";
	
	while (!circle.empty()) {
		for (int i = 0; i < K - 1; i++) { //next 쓰면 K개 가는 중에 끝에 도달한 경우 처리 어렵.
			it++;
			if (it == circle.end()) it = circle.begin();
		}
		cout << *it;
		it = circle.erase(it);
		//삭제 한 다음이 없으면 다시 젤 앞으로 포인터 옮겨줌
		if (it == circle.end()) it = circle.begin();

		if (!circle.empty()) {
			cout << ", ";
		}
	}

	cout << ">";
	return 0;
}