#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<vector<int>> floyd(int n, vector<vector<int>>& g) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (g[i][k] != INF && g[k][j] != INF) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
    }
    return g;
}

// 순서를 알 수 있는 학생 수 계산
int countKnown(int n, vector<vector<int>>& g) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (g[i][j] != INF || g[j][i] != INF) {
                cnt++;
            }
        }
        if (cnt == n) {
            res++;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1, vector<int>(n + 1, INF));

    // 자기 자신으로의 거리 0으로 초기화
    for (int i = 1; i <= n; i++) {
        g[i][i] = 0;
    }

    // 입력
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u][v] = 1; // u가 v보다 작음
    }

    g = floyd(n, g);

    cout << countKnown(n, g) << "\n";

    return 0;
}
