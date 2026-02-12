#include <iostream>
#include <vector>
using namespace std;

int N;

bool isPrime(int num) {
	for (int i = 2; i <= num/2; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

void DFS(int num, int n) { //n: 자릿수
	//cout << "num: " << num << " 자릿수: " << n << endl;
	if (n == N) { //자릿수 다 채워지면 끝
		if (isPrime(num)) cout << num << '\n';
		return;
	}
	for (int i = 1; i < 10; i++) {
		if (i % 2 == 0) continue;

		if (isPrime(num * 10 + i)) //소수인 경우에만 다음 DFS호출
			DFS(num * 10 + i, n + 1);

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);
	
}