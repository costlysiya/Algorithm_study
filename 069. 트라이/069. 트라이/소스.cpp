#include <iostream>
#include <vector>
using namespace std;

static int N, M;

class Node {
public:
	Node* next[26];
	bool isEnd;
	Node() : isEnd(false) { //생성자
		fill(next, next + 26, nullptr);
	}

	~Node() { //소멸자
		for (auto& child : next)
			delete child;
	}

	void insert(const char* key) { //문자열을 한 글자씩 쪼개어 트리에 등록
		if (*key == 0) {
			isEnd = true;
		}
		else {
			int next_index = *key - 'a';
			if (next[next_index] == nullptr) {
				next[next_index] = new Node(); //해당 글자의 노드가 없으면 새로 만듦
			}
			next[next_index]->insert(key + 1); //다음 글자로 넘어감
		}
		
	}

	Node* find(const char* key) { //특정 단어가 트리에 존재하는지 확인
		if (*key == 0) {
			return this;
		}
		int next_index = *key - 'a';

		if (next[next_index] == nullptr) {
			return nullptr;
		}
		return next[next_index]->find(key + 1);
	}
};

int main() {
	cin >> N >> M;
	Node* root = new Node();

	while (N > 0) {
		char text[501];
		cin >> text;
		root->insert(text);
		N--;
	}

	int count = 0;

	while (M > 0) {
		char text[501];
		cin >> text;
		Node* result = root->find(text);

		if (result && result->isEnd) {
			count++;
		}
		M--;
	}
	cout << count << '\n';

	return 0;
}