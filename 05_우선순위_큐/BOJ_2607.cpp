#include <iostream>
#include <vector>

using namespace std;

// 기준이 될 첫 번째 string의 알파벳 수를 세는 메서드
// 추가/삭제를 모두 처리할 수 있도록 delta 매개변수 추가
void count(string str, vector<int>& alpha, int delta) {
	for (auto ch : str) {
		int idx = ch - 'A';
		alpha[idx] += delta;
	}

	return;
}

bool solution(string instr, vector<int> alpha) {
	// 철자 하나씩 들어오는데로 standard의 알파벳 배열에서 빼주기
	count(instr, alpha, -1);

	// 철자 차이 계산을 위한 변수
	int diff = 0;

	for (int i = 0; i < alpha.size(); i++) {
		diff += abs(alpha[i]);  // 절대값을 더해 알파벳 차이를 계산
	}

	// 알파벳 차이가 2 이하면 비슷한 단어로 취급
	if (diff <= 2)
		return true;

	return false;
}

// 첫 string을 입력 받고 초기 설정을 해주는 메서드
void getFirstString(string str, vector<int>& alpha) {
	count(str, alpha, 1);

	return;
}

// string을 입력 받으며 첫 string과 비교해주는 메서드
int getStrings(int n, const vector<string>& strings, vector<int>& alpha) {
	int ans = 0;
	
	// 입출력을 main에서만 제어할 수 있도록 스트링 배열에 입력 문자열들 저장
	for(int i = 1; i < n; ++i) {
		if (solution(strings[i], alpha)) {
			ans++;
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

	int n;
	cin >> n;

	// 
	vector<string> strings(n);
	for (int i = 0; i < n; ++i) {
		cin >> strings[i];
	}
	
	vector<int> alpha(26, 0);
	getFirstString(strings[0], alpha);


	cout << getStrings(n, strings,alpha) << "\n";

	return 0;
}