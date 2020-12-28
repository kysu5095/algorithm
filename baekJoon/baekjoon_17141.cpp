// 연구소2
// 2:25

#include <iostream>
#include <limits.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int n, m, cnt = 0, res = INT_MAX;
int arr[51][51];
int virus[11];
bool visited[51][51] = { {false,}, };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
vector<pair<int, int>> v;

int bfs() {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	for (int i = 0; i < m; i++) {
		q.push(make_pair(v[virus[i]].first, v[virus[i]].second));
		visited[v[virus[i]].first][v[virus[i]].second] = true;
	}
	int y, x, ny, nx, len, v_cnt = cnt - m, t = 0;
	while (!q.empty()) {
		if (!v_cnt) return t;
		t++;
		len = q.size();
		while (len--) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny >= 0 && ny < n && nx >= 0 && nx < n && arr[ny][nx] != 1 && !visited[ny][nx]) {
					q.push(make_pair(ny, nx));
					visited[ny][nx] = true;
					v_cnt--;
				}
			}
		}
	}
	return INT_MAX;
}

void dfs(int idx, int cnt) {
	if (cnt == m) {
		int val = bfs();
		res = res > val ? val : res;
		return;
	}
	for (int i = idx; i < v.size(); i++) {
		virus[cnt] = i;
		dfs(i + 1, cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				v.push_back(make_pair(i, j));
			if (arr[i][j] != 1)
				cnt++;
		}
	}
	dfs(0, 0);
	if (res == INT_MAX) res = -1;
	cout << res << '\n';
	return 0;
}