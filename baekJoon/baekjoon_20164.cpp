// 홀수 홀릭 호석

#include <iostream>
#include <string>
#include <limits.h>
#include <algorithm>

using namespace std;


int max_v = INT_MIN, min_v = INT_MAX;
string n;

void dfs(string str, int s) {
	int cnt = 0;
	for (auto ch : str)
		if ((ch - '0') % 2 == 1) cnt++;
	if (str.size() == 1) {
		min_v = min(min_v, cnt + s);
		max_v = max(max_v, cnt + s);
		return;
	}
	if (str.size() == 2) {
		int next_num = (str[0] - '0') + (str[1] - '0');
		dfs(to_string(next_num), cnt + s);
	}
	else {
		for (int i = 1; i < str.size() - 1; i++) {
			for (int j = i + 1; j < str.size(); j++) {
				string next1 = str.substr(0, i);
				string next2 = str.substr(i, j - i);
				string next3 = str.substr(j);
				int next_num = stoi(next1) + stoi(next2) + stoi(next3);
				dfs(to_string(next_num), cnt + s);
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	dfs(n, 0);
	cout << min_v << " " << max_v << '\n';
	return 0;
}