#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string str;
    stack<char> chars;

    while (true) {
        // getline���� �� �� ��°�� �ޱ�
        getline(cin, str);
        if (str == ".") break;

        bool isBalanced = true;

        for (char ch : str) {
            // ���� ��ȣ�� �ܼ��� ���ÿ� �ֱ⸸ �ϱ�
            if (ch == '[')
                chars.push('[');
            else if (ch == '(')
                chars.push('(');

            // ������ ��ȣ �˰���
            // 1. ���� ��ȣ�� ������ �ִ��� Ȯ���ϱ�
            // 2. ���ٸ� isBalanced�� false�� ó���ϰ� break ��Ű��
            else if (ch == ']') {
                if (!chars.empty() && chars.top() == '[')
                    chars.pop();
                else {
                    isBalanced = false;
                    break;
                }
            }
            else if (ch == ')') {
                if (!chars.empty() && chars.top() == '(')
                    chars.pop();
                else {
                    isBalanced = false;
                    break;
                }
            }
        }

        // ���� �� �ٿ� ���� ó���ϱ�
        if (isBalanced && chars.empty())
            cout << "yes\n";
        else
            cout << "no\n";

        // ���� ����
        while (!chars.empty()) chars.pop();
    }

    return 0;
}
