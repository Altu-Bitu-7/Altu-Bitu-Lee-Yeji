#include <iostream>
#include <set>
#include <string>

using namespace std;

// Function to insert n strings into a set
void populateSet(set<string>& s, int n) {
	string input;

	for (int i = 0; i < n; i++) {
		cin >> input;
		s.insert(input);
	}
}

int countMatchingStrings(const set<string>& s, int m) {
	string input;
	int ans = 0;

	for (int i = 0; i < m; i++) {
		cin >> input;

		if (s.find(input) != s.end())
			ans++;
	}

	return ans;
}

int main() {

	set<string> s;
	int n, m;

	cin >> n >> m;

	populateSet(s, n);
	
	cout << countMatchingStrings(s, m) << "\n";
	
	return 0;
}