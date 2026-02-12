#include <iostream>
#include <vector>
using namespace std;

static int N;

// 1. 전위 순회 (Root -> Left -> Right)
void preOrder(vector<vector<char>>& tree, int index) {
    cout << char(index + 'A'); // 루트 먼저 출력

    if (tree[index][0] != NULL) { // 왼쪽 자식이 있다면 방문
        preOrder(tree, tree[index][0] - 'A');
    }
    if (tree[index][1] != NULL) { // 오른쪽 자식이 있다면 방문
        preOrder(tree, tree[index][1] - 'A');
    }
}

// 2. 중위 순회 (Left -> Root -> Right)
void inOrder(vector<vector<char>>& tree, int index) {
    if (tree[index][0] != NULL) { // 왼쪽 자식 먼저 방문
        inOrder(tree, tree[index][0] - 'A');
    }

    cout << char(index + 'A'); // 루트 출력

    if (tree[index][1] != NULL) { // 오른쪽 자식 방문
        inOrder(tree, tree[index][1] - 'A');
    }
}

// 3. 후위 순회 (Left -> Right -> Root)
void postOrder(vector<vector<char>>& tree, int index) {
    if (tree[index][0] != NULL) {
        postOrder(tree, tree[index][0] - 'A');
    }
    if (tree[index][1] != NULL) {
        postOrder(tree, tree[index][1] - 'A');
    }
    cout << char(index + 'A');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    vector<vector<char>> tree(26, vector<char>(2, NULL));

    for (int i = 0; i < N; i++) {
        char parent, leftnode, rightnode;
        cin >> parent >> leftnode >> rightnode;

        if (leftnode != '.') {
            tree[parent - 'A'][0] = leftnode;
        }
        if (rightnode != '.') {
            tree[parent - 'A'][1] = rightnode;
        }
    }

    preOrder(tree, 0); cout << "\n";
    inOrder(tree, 0); cout << "\n";
    postOrder(tree, 0); cout << "\n";

    return 0;
}