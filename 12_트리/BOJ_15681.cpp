#include <iostream>
#include <vector>

using namespace std;

// 서브트리 크기를 계산하는 함수
int calculateSubtree(int node, int parent, vector<vector<int>>& tree, vector<int>& size) {
    size[node] = 1; // 자신을 포함하므로 초기 크기 1로 설정

    for (int child : tree[node]) {
        if (child != parent) {
            size[node] += calculateSubtree(child, node, tree, size);
        }
    }

    return size[node];
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    int n, r, q;
    cin >> n >> r >> q;

    vector<vector<int>> tree(n + 1); // 트리의 인접 리스트
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> size(n + 1, 0); // 서브트리 크기를 저장하는 배열

    // 루트 노드를 기준으로 서브트리 크기 계산
    calculateSubtree(r, -1, tree, size);

    /*
        루트 노드는 부모가 없기 때문에 "부모 없음"을 나타내기 위해 -1 사용
        => 역방향 탐색 방지
    */

    // 쿼리 처리
    for (int i = 0; i < q; i++) {
        int node;
        cin >> node;
        cout << size[node] << endl;
    }

    return 0;
}
