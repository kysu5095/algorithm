// Secret Sharing

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n;
vector<string> v;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end(), [](string& str1, string& str2) {
		if (str1 + str2 < str2 + str1) return true;
		else return false;
		});
	string res = "";
	for (int i = 0; i < n; i++) {
		if (v[i][0] == '0') continue;
		string next = v[i];
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			next += v[j];
		}
		if (res == "") res = next;
		else res = res > next ? next : res;
	}
	if (res == "") cout << "INVALID\n";
	else cout << res << '\n';
	return 0;
}