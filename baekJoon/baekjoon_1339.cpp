// 단어 수학

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

int n, res = 0;
vector<string> v;
map<char, int> m;

void cal() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int tmp_sum = 0;
		int len = v[i].length();
		for (int j = 0; j < len; j++) 
			tmp_sum += ((m.find(v[i][j])->second) * pow(10, len - 1 - j));
		sum += tmp_sum;
	}
	res = max(res, sum);
}

void dfs(int cnt) {
	if (cnt == 10) {
		cal();
		return;
	}
	map<char, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second == -1) {
			iter->second = cnt;
			dfs(cnt + 1);
			iter->second = -1;
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int cnt = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(str);
		for (int j = 0; j < str.length(); j++) 
			m[str[j]] = -1;
	}
	cnt = m.size();
	dfs(10 - cnt);
	cout << res << '\n';
	return 0;
}