#include <bits/stdc++.h>
using namespace std;

int leftchild[10001];
int rightchild[10001];
int cnt;

int dfs(int node, int mid, vector<int>& num) {
    int l = 0, r = 0;
    if (leftchild[node] != -1) {
        l = dfs(leftchild[node], mid, num);
    }
    if (rightchild[node] != -1) {
        r = dfs(rightchild[node], mid, num);
    }
    // total이 mid값 보다 큰 경우 자식을 잘라내서 mid값 보다 작도록 만들어야함.
    int total = num[node] + l + r;
    //합산 자식들 + 자기 자신이 정해둔 mid값보다 작거나 같을때
    if (total <= mid) return total;

    //한쪽만 잘라내도 되는 경우
    if (num[node] + min(l, r) <= mid) {
        cnt++;
        return num[node] + min(l, r);
    }
    //양쪽 자식 모두 잘라내야할 때
    cnt += 2;
    return num[node];
}

//그룹 수가 k보다 작은지 확인하는 함수
bool canDivide(int mid, int k, int root, vector<int>& num) {
    cnt = 0;
    dfs(root, mid, num);
    return cnt + 1 <= k;
}

int solution(int k, vector<int> num, vector<vector<int>> links) {
    memset(leftchild, -1, sizeof(leftchild));
    memset(rightchild, -1, sizeof(rightchild));

    vector<bool> isChild(num.size(), false);
    for (int i = 0; i < num.size(); i++) {
        leftchild[i] = links[i][0];
        rightchild[i] = links[i][1];
        //어떤 노드의 자식인 경우 isChild = true
        if (leftchild[i] != -1) isChild[leftchild[i]] = true;
        if (rightchild[i] != -1) isChild[rightchild[i]] = true;
    }

    int root = -1;
    for (int i = 0; i < num.size(); i++) {
        if (!isChild[i]) {
            root = i;
            break;
        }
    }

    int lo = *max_element(num.begin(), num.end());
    int hi = accumulate(num.begin(), num.end(), 0);

    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (canDivide(mid, k, root, num)) hi = mid;
        else lo = mid + 1;
    }

    return lo;
}