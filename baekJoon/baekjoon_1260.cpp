// DFS와 BFS

#include <iostream>
#include <string.h>
#include <set>
#include <queue>

using namespace std;

int n, m, v;
set<int> s[1001];
bool visited[1001] = { false, };

void dfs(int cnt) {
	cout << cnt << " ";
	visited[cnt] = true;
	set<int>::iterator iter = s[cnt].begin();
	for (iter; iter != s[cnt].end(); iter++) {
		if (!visited[*iter]) {
			dfs(*iter);
		}
	}
}

void bfs(int _cnt) {
	queue<int> q;
	q.push(_cnt);
	visited[_cnt] = true;
	int cnt;
	while (!q.empty()) {
		cnt = q.front();
		q.pop();
		cout << cnt << " ";
		set<int>::iterator iter = s[cnt].begin();
		for (iter; iter != s[cnt].end(); iter++) {
			if (!visited[*iter]) {
				visited[*iter] = true;
				q.push(*iter);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int first, second;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		cin >> first >> second;
		s[first].insert(second);
		s[second].insert(first);
	}
	memset(visited, false, sizeof(visited));
	dfs(v);
	cout << '\n';
	memset(visited, false, sizeof(visited));
	bfs(v);
	cout << '\n';
	return 0;
}