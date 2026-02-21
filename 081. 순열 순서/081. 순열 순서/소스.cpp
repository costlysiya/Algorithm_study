#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int N, option;
static long long D[21];



int main() {
	cin >> N;
	cin >> option;

	D[0] = 1;
	for (int i = 1; i <= N; i++) {
		D[i] = D[i - 1] * i;
	}

	vector<int> nums;
	for (int i = 1; i <= N; i++) {
		nums.push_back(i);
	}

	if (option == 1) {
		long long k;
		
		cin >> k;

		vector<int> answer(N);

		k--; //경계값 오류 제거 
		for (int i = 1; i <= N; i++) {
			int idx = k / D[N - i];
			k %= D[N - i];

			cout << nums[idx] << " "; // 사용할 수 있는 숫자 중 idx번째 출력
			nums.erase(nums.begin() + idx); // 사용한 숫자 제거
		}
	}
	if (option == 2) {
		vector<int> quest(N,0);
		for (int i = 0; i < N; i++) {
			cin >> quest[i];
		}

		long long k = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < nums.size(); j++) {
				if (nums[j] == quest[i]) { //현재 숫자가 남은 숫자 중 몇번쨰(j) 작은 숫자인가
					k += (long long)j * D[N - 1 - i];  //j개의 그룹이 이미 지나감
					nums.erase(nums.begin() + j);
					break;
				}
			}
		}
		cout << k;
	}


	return 0;
}