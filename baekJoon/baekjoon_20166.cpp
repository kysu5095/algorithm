// 문자열 지옥에 빠진 호석

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int n, m, K;
char arr[11][11];
int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
vector<string> v;
set<string> s;
map<string, int> god;

void dfs(int y, int x, int idx, string cur) {
	cur += arr[y][x];
	auto iter = s.find(cur);
	if (iter != s.end()) god[cur]++;
	if (idx + 1 == 5) return;
	for (int i = 0; i < 8; i++)
		dfs((y + n + dy[i]) % n, (x + m + dx[i]) % m, idx + 1, cur);
	return;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> K;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int k = 0; k < K; k++) {
		string str;
		cin >> str;
		s.insert(str);
		v.push_back(str);
		god[str] = 0;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dfs(i, j, 0, "");
	for (int i = 0; i < v.size(); i++)
		cout << god[v[i]] << '\n';
	return 0;
}