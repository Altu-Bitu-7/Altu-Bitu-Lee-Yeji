#include <iostream>
#include <vector>

using namespace std;

// TEST CASE는 다 올바르게 나오는데 틀렸습니다 뜨는 상태
// 질문 게시퍈, CHATGPT 등으로 반례 찾아보고 코드 비교도 해봤는데 모르겠어서 일단 제출합니다

// resetwheel 함수에서는 값으로 반환하고
vector<char> resetWheel(int n) {
	vector<char> wheel(n, '?');

	return wheel;
}

// 시계 방향으로 돌리면 바퀴는 시계 반대 방향으로 이동
int calculatePosition(int n, int position, int inc) {
	return (position - inc + n) % n;
}

int rotates(int n, int k, vector<char>& wheel, bool& flag) {
	// 알파벳 사용 여부 체크
	vector<bool> alphabets(26, false);
	// 현재 바퀴의 인덱스 위치
	int current_position = 0;
	int inc;
	char letter;

	for (int i = 0; i < k; i++) {
		cin >> inc >> letter;

		current_position = calculatePosition(n, current_position, inc);

		// 해당 위치가 비어 있다면
		if (wheel[current_position] == '?') {
			// 이미 사용된 알파벳인지 확인
			if (alphabets[letter - 'A']) {
				flag = false;
			}
			// 이미 사용된 알파벳이 아니라면
			// 알파벳 사용 기록하고 바퀴에 알파벳 채움
			else {
				alphabets[letter - 'A'] = true;
				wheel[current_position] = letter;
			}
		}
		else if (wheel[current_position] != letter) {
			flag = false;
		}
	}

	return current_position;
}

int main() {
	int n, k;
	cin >> n >> k;

	vector<char> lucky_wheel = resetWheel(n);

	bool flag = true;
	int final_position = rotates(n, k, lucky_wheel, flag);

	if (flag == false ) {
		cout << "!";
		return 0;
	}
	else {
		// 출력: final_position(마지막 current_position)부터 출력
		// true를 반환하는 경우에도 main에서 출력하게 하려면?
		for (int i = 0; i < n; i++) {
			cout << lucky_wheel[final_position++];
			final_position %= n;
		}
	}

	return 0;
}