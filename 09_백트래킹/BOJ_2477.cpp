#include <iostream>
#include <vector>

using namespace std;

const int EDGE_COUNT = 6;  // 육각형의 변 개수를 상수로 정의

// 육각형의 면적을 계산하는 함수
int calculateArea(const vector<pair<int, int>>& edges, int n) {
    int max_wid = 0, max_hei = 0;
    int max_wid_idx = 0, max_hei_idx = 0;

    // 가장 큰 가로, 세로 길이와 인덱스 찾기
    for (int i = 0; i < EDGE_COUNT; ++i) {
        if (edges[i].first == 1 || edges[i].first == 2) {
            if (edges[i].second > max_wid) {
                max_wid = edges[i].second;
                max_wid_idx = i;
            }
        }
        else if (edges[i].first == 3 || edges[i].first == 4) {
            if (edges[i].second > max_hei) {
                max_hei = edges[i].second;
                max_hei_idx = i;
            }
        }
    }

    // 작은 직사각형의 변 찾기 (큰 변에 인접한 두 변)
    int min_wid = edges[(max_wid_idx + 3) % EDGE_COUNT].second;
    int min_hei = edges[(max_hei_idx + 3) % EDGE_COUNT].second;

    // 면적 계산
    int max_rec = max_wid * max_hei;
    int min_rec = min_wid * min_hei;
    int rec = max_rec - min_rec;

    return rec * n;
}

int main() {
    vector<pair<int, int>> edges(EDGE_COUNT);

    int n;
    cin >> n;

    for (int i = 0; i < EDGE_COUNT; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    // 영역 계산 함수 호출
    cout << calculateArea(edges, n) << "\n";

    return 0;
}
