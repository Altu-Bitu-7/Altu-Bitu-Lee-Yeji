#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> dijkstra(int v, int start, vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(v + 1, INF); // 최단 거리 저장
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push(make_pair(0, start)); // (거리, 노드)

    while (!pq.empty()) {
        pair<int, int> current = pq.top();
        int curDist = current.first;
        int curNode = current.second;
        pq.pop();

        if (curDist > dist[curNode]) continue;  // 이미 처리된 거리보다 크면 무시

        for (size_t i = 0; i < adj[curNode].size(); i++) {
            int nextNode = adj[curNode][i].first;
            int weight = adj[curNode][i].second;

            if (dist[curNode] + weight < dist[nextNode]) {
                dist[nextNode] = dist[curNode] + weight;
                pq.push(make_pair(dist[nextNode], nextNode));
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int v, e, start;
    cin >> v >> e >> start;

    vector<vector<pair<int, int>>> adj(v + 1);

    // 간선 정보 입력
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }

    vector<int> dist = dijkstra(v, start, adj);

    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF) {
            cout << "INF\n";
        }
        else {
            cout << dist[i] << "\n";
        }
    }

    return 0;
}
