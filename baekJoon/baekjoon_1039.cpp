// 교환

#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

string n;
int k;
int visited[10][1000001] = { {0, }, };

int dfs(string str, int cnt) {
	if (cnt == k) {
		return stoi(str);
	}
	int& ret = visited[cnt][stoi(str)];
	if (ret != -1) return ret;
	int len = str.length();
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			swap(str[i], str[j]);
			if (str[0] == '0') {
				swap(str[i], str[j]);
				continue;
			}
			ret = max(ret, dfs(str, cnt + 1));
			swap(str[i], str[j]);
		}
	}
	return ret;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	memset(visited, -1, sizeof(visited));
	cout << dfs(n, 0) << '\n';
	return 0;
}