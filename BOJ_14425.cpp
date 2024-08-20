#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {

	set<string> s;
	int n, m;

	string input;
	int ans = 0;

	cin >> n >> m;


	for (int i = 0; i < n; i++) {
		cin >> input;
		s.insert(input);
	}

	for (int i = 0; i < m; i++) {
		cin >> input;

		if (s.find(input) != s.end())
			ans++;
	}

	cout << ans << "\n";
	
	return 0;
}