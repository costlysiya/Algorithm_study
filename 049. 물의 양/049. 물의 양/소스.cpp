#include <iostream>
#include <queue>
using namespace std;

static int Sender[] = { 0, 0, 1, 1, 2, 2 };
static int Receiver[] = { 1, 2, 0, 2, 0, 1 };
static bool visited[201][201];
static bool answer[201];
static int now[3];//그냥 가능한 최대 용량이라 생각.

void BFS();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> now[0] >> now[1] >> now[2];
	BFS();

	for (int i = 0; i < 201; i++) {
		if (answer[i]) cout << i << " ";
	}

}

void BFS() {
	queue<pair<int, int>>myqueue;
	myqueue.push(make_pair(0, 0));
	visited[0][0] = true;
	answer[now[2]] = true;

	while (!myqueue.empty()) {
		pair<int, int> p = myqueue.front();
		myqueue.pop();
		int A = p.first;
		int B = p.second;
		int C = now[2] - A - B;

		for (int i = 0; i < 6; i++) {
			int next[] = { A,B,C }; //현재 A,B,C에 들어있는 물 양
			next[Receiver[i]] += next[Sender[i]]; //물 보냄
			next[Sender[i]] = 0;

			if (next[Receiver[i]] > now[Receiver[i]]) { //넘치는 경우
				next[Sender[i]] = next[Receiver[i]] - now[Receiver[i]]; //넘치는 만큼 다시 담음
				next[Receiver[i]] = now[Receiver[i]]; //밭는 쪽은 가득
			}
			if (!visited[next[0]][next[1]]) { //방문한적있는 패턴인지 체크
				visited[next[0]][next[1]] = true;
				myqueue.push(make_pair(next[0], next[1]));
				if (next[0] == 0) {
					answer[next[2]] = true; //A의 물의 양이 0일때 C의 물 용량을 정답으로 저장
				}
			}
		}
	}
}