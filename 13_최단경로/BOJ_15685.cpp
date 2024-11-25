#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

// 방향 벡터 (우, 상, 좌, 하)
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

// 드래곤 커브를 생성하는 함수
void generateDragonCurve(vector<vector<int>>& map, int x, int y, int d, int g) {
    vector<int> directions = { d }; // 초기 방향 저장
    map[x][y] = 1;

    // 0세대 처리
    x += dx[d];
    y += dy[d];
    map[x][y] = 1;

    // g세대까지 드래곤 커브 생성
    for (int generation = 0; generation < g; generation++) {
        int size = directions.size();
        for (int i = size - 1; i >= 0; i--) {
            int newDir = (directions[i] + 1) % 4; // 90도 회전
            x += dx[newDir];
            y += dy[newDir];
            map[x][y] = 1; // 드래곤 커브의 새로운 점
            directions.push_back(newDir); // 새로운 방향 추가
        }
    }
}

// 네 점이 모두 1인 정사각형의 개수를 세는 함수
int countSquares(const vector<vector<int>>& map) {
    int count = 0;
    for (int i = 0; i < MAX - 1; i++) {
        for (int j = 0; j < MAX - 1; j++) {
            if (map[i][j] == 1 && map[i][j + 1] == 1 &&
                map[i + 1][j] == 1 && map[i + 1][j + 1] == 1) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> map(MAX, vector<int>(MAX, 0)); // 100x100 맵 초기화

    for (int i = 0; i < n; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        // 드래곤 커브 생성
        generateDragonCurve(map, x, y, d, g);
    }

    // 정사각형 개수 계산
    int result = countSquares(map);

    // 결과 출력
    cout << result << endl;

    return 0;
}
