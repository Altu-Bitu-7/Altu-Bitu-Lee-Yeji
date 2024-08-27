#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string str;
    stack<char> chars;

    while (true) {
        // getline으로 한 줄 통째로 받기
        getline(cin, str);
        if (str == ".") break;

        bool isBalanced = true;

        for (char ch : str) {
            // 왼쪽 괄호는 단순히 스택에 넣기만 하기
            if (ch == '[')
                chars.push('[');
            else if (ch == '(')
                chars.push('(');

            // 오른쪽 괄호 알고리즘
            // 1. 왼쪽 괄호가 직전에 있는지 확인하기
            // 2. 없다면 isBalanced도 false로 처리하고 break 시키기
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

        // 들어온 한 줄에 대한 처리하기
        if (isBalanced && chars.empty())
            cout << "yes\n";
        else
            cout << "no\n";

        // 스택 비우기
        while (!chars.empty()) chars.pop();
    }

    return 0;
}
