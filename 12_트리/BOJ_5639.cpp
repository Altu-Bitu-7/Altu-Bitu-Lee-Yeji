#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// 후위 순회를 재귀적으로 수행하는 함수
void postOrder(vector<int>& preorder, int& idx, int min, int max) {
    if (idx >= preorder.size()) return;

    int node = preorder[idx];

    // 범위를 벗어난 경우 반환
    if (node < min || node > max) return;

    idx++; // 현재 노드 처리

    // 좌우 서브트리 순회
    postOrder(preorder, idx, min, node);
    postOrder(preorder, idx, node, max);

    // 후위 순회 출력
    cout << node << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
      
    vector<int> preorder;
    int value;

    // 전위 순회 입력 받기 (EOF까지)
    while (cin >> value) {
        preorder.push_back(value);
    }

    int idx = 0;

    // 후위 순회 수행
    postOrder(preorder, idx, numeric_limits<int>::min(), numeric_limits<int>::max());

    return 0;
}
