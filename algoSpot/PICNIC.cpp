// 소풍

#include <iostream>
#include <string.h>

using namespace std;

int test_case, n, m;
bool comp[11], friends[11][11];

int dfs() {
	int ret = 0;
	int idx;
	for (idx = 0; idx < n; idx++)
		if (!comp[idx]) break;
	if (idx == n) return 1;

	for (int i = idx + 1; i < n; i++) {
		if (!comp[i] && friends[idx][i]) {
			comp[idx] = comp[i] = true;
			ret += dfs();
			comp[idx] = comp[i] = false;
		}
	}
	return ret;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> test_case;
	while (test_case--) {
		memset(comp, false, sizeof(comp));
		memset(friends, false, sizeof(friends));
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			friends[a][b] = friends[b][a] = true;
		}
		cout << dfs() << '\n';
	}
	return 0;
}