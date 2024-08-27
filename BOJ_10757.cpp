#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// string���� ���� ����
// idea: �޾ƿø��� ��� ������ ���ΰ�
// idea: �ڸ����� ���� ����ϴ� ��� -> 1�� �ڸ����� ����
string addStrings(const string& num1, const string& num2) {
	string result;	// �����
	int carry = 0;	// �޾ƿø� �� ��
	int sum = 0;	// �ݺ������� �� �ڸ��� ������ Ȱ���� ����

	// ������ ������ �ڸ��� ���� �ڸ��� �������ֱ�
	int i = num1.size() - 1, j = num2.size() - 1;

	// idea: ���� ���� �ڸ��� ������ ������

	while (i >= 0 || j >= 0 || carry) {
		// �޾ƿ÷��� ������ �ݿ�
		sum = carry;
		// �� ������ �ƽ�Ű �ڵ� ������ 0��ŭ ���� ���� ��¥ ������ ��
		if (i >= 0) sum += num1[i--] - '0';
		if (j >= 0) sum += num2[j--] - '0';

		// �޾� �ø�
		carry = sum / 10;
		// ���� �� �ڸ����� '0'�� ���ؼ� �ٽ� string �� �ο�
		result.push_back(sum % 10 + '0');
	}

	reverse(result.begin(), result.end());
	return result;
}

int main() {

	string a, b;

	cin >> a >> b;

	cout << addStrings(a, b);

	return 0;
}