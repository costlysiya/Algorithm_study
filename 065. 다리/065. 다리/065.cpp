#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

void munion(int a, int b);
int find(int a);
void BFS(int i, int j);

static int dr[] = { -1, 0, 1, 0 };
static int dc[] = { 0, 1, 0, -1 };
static int map[101][101];
static bool visited[101][101]={ false, };
static vector<int> parent;
static int N, M, sNum; //sNum=섬의 번호
static vector<vector<pair<int, int>>> sumlist; //모든 섬별 좌표 저장
static vector<pair<int, int>> mlist; //하나의 섬 정보 (섬에 속한 좌표) 저장 

typedef struct Edge {
	int s, e, v;
	bool operator>(const Edge& temp) const {
		return v > temp.v;
	}
}Edge;

static priority_queue<Edge, vector<Edge>, greater<Edge>> pq;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	sNum = 1;

	//섬의 일부이고 방문한적 없으면 BFS수행

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] != 0 && visited[i][j] != true) {
				BFS(i, j); //섬 하나가 어디까진지 표시.
				sNum++;
				sumlist.push_back(mlist); //하나의 섬 정보를 sumlist에 넣어줌
			}
		}
	}

	//섬의 각 지점에서 만들 수 있는 모든 에지 저장
	for (int i = 0; i < sumlist.size(); i++) {
		vector<pair<int, int>> now = sumlist[i];

		for (int j = 0; j < now.size(); j++) {
			int r = now[j].first;
			int c = now[j].second;
			int now_S = map[r][c]; // 지금 섬 번호

			for (int d = 0; d < 4; d++) { //상->우->하->좌 탐색
				int tempR = dr[d];
				int tempC = dc[d];
				int blength = 0;

				while (r + tempR >= 0 && r + tempR < N && c + tempC >= 0 && c + tempC < M) {
					if (map[r + tempR][c + tempC] == now_S) { //같은 섬일 때
						break;
					}
					else if(map[r + tempR][c + tempC] !=0 ){ //다른 섬일 때
						if (blength > 1) { //다리 길이가 1보다 클 때
							pq.push(Edge{ now_S, map[r + tempR][c + tempC] , blength });
						}
						break;
					}
					else { //바다일 때
						blength++;
					}

					//한방향으로 계속 탐색하기 위해
					if (tempR < 0) tempR--;
					else if (tempR > 0) tempR++;
					else if (tempC < 0) tempC--;
					else if (tempC > 0) tempC++;
				}
			}
		}
	}


	//최소 신장 트리 알고리즘 이용
	parent.resize(sNum);

	for (int i = 0; i < parent.size(); i++) {
		parent[i] = i;
	}

	int useEdge = 0; 
	int result = 0;

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		//부모가 다른 경우, 연결
		if (find(now.s) != find(now.e)) {
			munion(now.s, now.e);
			result = result + now.v;
			useEdge++;
		}
	}

	if (useEdge == sNum - 2) { //섬 번호를 1부터 매겼기 때문에 -2함
		cout << result << '\n';
	}
	else { //useEdge 수가 충족이 안되는 경우 모든 섬이 연결되지 않았음을 뜻함
		cout << -1 << '\n';
	}
	return 0;
}

void munion(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		parent[b] = a;
	}
}

int find(int a) {
	if (a == parent[a]) return a;
	else {
		return parent[a] = find(parent[a]);
	}
}

void BFS(int i, int j) {
	queue<pair<int, int>> myqueue;
	mlist.clear();

	myqueue.push(make_pair(i, j));
	mlist.push_back(make_pair(i, j));
	visited[i][j] = true;
	map[i][j] = sNum;

	while (!myqueue.empty()) {
		int r = myqueue.front().first;
		int c = myqueue.front().second;
		myqueue.pop();

		for (int d = 0; d < 4; d++) {
			int tempR = dr[d];
			int tempC = dc[d];

			while (r + tempR >= 0 && r + tempR < N && c + tempC >= 0 && c + tempC < M) {
				//방문한 적 없고 바다가 아닐때, 같은 섬으로 취급
				if (visited[r + tempR][c + tempC] == false && map[r + tempR][c + tempC] != 0) {
					int now_i = r + tempR;
					int now_j = c + tempC;

					map[now_i][now_j] = sNum;
					visited[now_i][now_j] = true;
					mlist.push_back(make_pair(now_i, now_j));
					myqueue.push(make_pair(now_i, now_j));
				}
				else { //다른 섬이거나 바다 일 때, 다른 방향으로 탐색 시작
					break;
				}

				//직선 상에 있는 땅만 찾기
				if (tempR < 0) tempR--;
				else if (tempR > 0) tempR++;
				else if (tempC < 0) tempC--;
				else if (tempC > 0) tempC++;
			}
		}
	}
}