#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

// 뱀의 게임 시뮬레이션 함수
int simulate(int n, vector<vector<int>>& board, vector<pair<int, char>>& moves) {
    deque<pair<int, int>> snake; // 뱀의 위치를 저장하는 덱
    snake.push_back(make_pair(0, 0)); // 뱀 초기 위치
    board[0][0] = 2;                  // 뱀의 위치 표시 (2)

    int time = 0;
    int dir = 0; // 초기 방향 (동쪽)
    int moveIdx = 0;

    while (true) {
        time++;

        // 뱀의 머리 이동
        int nx = snake.front().first + dx[dir];
        int ny = snake.front().second + dy[dir];

        // 이동 후 충돌 체크 (벽 또는 몸체)
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == 2) {
            break;
        }

        // 이동한 위치를 뱀의 머리로 추가
        snake.push_front(make_pair(nx, ny));

        // 사과가 있는 경우와 없는 경우 처리
        if (board[nx][ny] == 1) {
            board[nx][ny] = 2; // 사과를 먹고 뱀 채우기
        }
        else {
            board[nx][ny] = 2;             // 이동한 위치를 뱀 채우기
            pair<int, int> tail = snake.back(); // 꼬리 제거
            snake.pop_back();
            board[tail.first][tail.second] = 0;
        }

        // 방향 전환 체크
        if (moveIdx < moves.size() && moves[moveIdx].first == time) {
            char turn = moves[moveIdx].second;

            if (turn == 'L') {
                dir = (dir + 3) % 4; // 왼쪽 회전
            }
            else if (turn == 'D') {
                dir = (dir + 1) % 4; // 오른쪽 회전
            }

            moveIdx++;
        }
    }

    return time;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> board(n, vector<int>(n, 0)); // 보드 초기화

    // 사과 위치 입력
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        board[x - 1][y - 1] = 1; // 사과는 1로 표시
    }

    int l;
    cin >> l;
    vector<pair<int, char>> moves(l);

    // 방향 변환 정보 입력
    for (int i = 0; i < l; i++) {
        cin >> moves[i].first >> moves[i].second;
    }

    // 시뮬레이션 실행
    int result = simulate(n, board, moves);
    cout << result << endl;

    return 0;
}
