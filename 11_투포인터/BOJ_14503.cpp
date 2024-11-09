#include <iostream>
#include <vector>

using namespace std;

// 방향 설정 (북, 동, 남, 서 순서)
int dx[4] = { -1, 0, 1, 0 }; 
int dy[4] = { 0, 1, 0, -1 }; 

// 청소 영역 계산 함수
int cleanRoom(int n, int m, int x, int y, int dir, vector<vector<int>>& room) {
    int cleaned = 0; // 청소한 영역 수
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    while (true) {
        // 현재 위치 청소
        if (!visited[x][y]) {
            visited[x][y] = true;
            cleaned++;
        }

        bool moved = false;

        // 4방향 탐색
        for (int i = 0; i < 4; i++) {
            dir = (dir + 3) % 4; // 왼쪽으로 회전
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // 청소 가능한 곳 발견 시 이동
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && room[nx][ny] == 0 && !visited[nx][ny]) {
                x = nx;
                y = ny;
                moved = true;
                break;
            }
        }

        // 네 방향 모두 청소가 되어 있거나 벽인 경우
        if (!moved) {
            int backDir = (dir + 2) % 4;
            int bx = x + dx[backDir];
            int by = y + dy[backDir];

            // 뒤로 이동 가능 시 후진
            if (bx >= 0 && bx < n && by >= 0 && by < m && room[bx][by] == 0) {
                x = bx;
                y = by;
            }
            else {
                // 후진도 불가능하면 종료
                break;
            }
        }
    }

    return cleaned;
}

int main() {
    int n, m;
    cin >> n >> m;
    int x, y, dir;
    cin >> x >> y >> dir;

    vector<vector<int>> room(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }

    int result = cleanRoom(n, m, x, y, dir, room);

    cout << result << endl;

    return 0;
}
