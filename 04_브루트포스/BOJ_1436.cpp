#include <iostream>
#include <string>

using namespace std;

// 숫자에서 666이 포함되어 있는지 확인하는 함수
bool contains666(int num) {
	int consecutiveSixes = 0;

	while (num > 0) {
		if (num % 10 == 6) {
			consecutiveSixes++;
			if (consecutiveSixes == 3) {
				return true; // 666을 찾음
			}
		}
		// 6이 연속되지 않으면 초기화
		else {
			consecutiveSixes = 0;	
		}

		// 다음 자리수로 이동
		num /= 10;	
	}

	return false;
}

int apocalypseNumber(int n) {
	int num = 666;
	int count = 0;

	while (true) {
		/*
		666 string으로 변환 후 666을 포함하는지 확인하는 메서드
		string str_num = to_string(num);

		if (str_num.find("666") != string::npos) {
		*/
		
		// int형 그대로 666을 포함하는지 확인하는 메서드
		if (contains666(num)) {
			count++;
		}

		if (count == n) {
			break;
		}
		
		num++;
	} 
	return num;
}

int main() {
	int n; int ans;
	cin >> n;

	ans = apocalypseNumber(n);
	cout << ans << endl;

	return 0;
}