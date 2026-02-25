#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// DP[i][0]: 하나도 안 지웠을 때 i번째 수를 반드시 포함한 최댓값
// DP[i][1]: 이미 하나 지웠을 때거나 i번째 수를 지웠을때 최댓값 
long long DP[100001][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) cin >> nums[i];

    // 초기값 설정
    DP[0][0] = nums[0]; // 첫 번째 수는 무조건 포함 (하나도 안 지움)
    DP[0][1] = 0;       // 첫 번째 수를 지우면 합이 0이지만, 연속합은 최소 1개는 골라야 하므로 
    // 실제로는 첫 번째 수를 지운 경우는 고려하지 않거나 nums[0]으로 둡니다.


    long long max_value = nums[0];

    for (int i = 1; i < N; i++) { //i는 인덱스 값
        // 1. 하나도 안 지우는 경우
        // (이전까지의 합 + 현재 수) vs (그냥 현재 수부터 새로 시작)
        DP[i][0] = max((long long)nums[i], DP[i - 1][0] + nums[i]);

        // 2. 하나를 지우는 경우
        // (이미 앞에서 하나 지움 + 현재 수 포함) vs (이번에 현재 수를 처음으로 지움 = DP[i-1][0])
        DP[i][1] = max(DP[i - 1][1] + nums[i], DP[i - 1][0]);

        // 전체 최댓값 갱신
        max_value = max({ max_value, DP[i][0], DP[i][1] });
    }

    cout << max_value;

    return 0;
}