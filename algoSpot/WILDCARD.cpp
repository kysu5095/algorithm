// Wildcard

#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int test_case, n;
int dp[102][102];
string wild, file;
vector<string> v;

bool Wildcard(int w, int f) {
	int& ret = dp[w][f];
	if (ret != -1) return ret;

	if (w < wild.size() && f < file.size() && (wild[w] == '?' || wild[w] == file[f]))
		return ret = Wildcard(w + 1, f + 1);
	if (w == wild.size() && f == file.size()) return 1;
	if (wild[w] == '*') {
		if (Wildcard(w + 1, f) || Wildcard(w, f + 1))
			return ret = 1;
	}

	return ret = 0;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> test_case;
	while (test_case--) {
		v.clear();
		cin >> wild;
		cin >> n;
		for (int i = 0; i < n; i++) {
			memset(dp, -1, sizeof(dp));
			cin >> file;
			if (Wildcard(0, 0))
				v.push_back(file);
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << '\n';
	}
	return 0;
}