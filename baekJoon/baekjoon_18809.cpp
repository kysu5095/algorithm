// Gaaaaaaaaaarden 

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int n, m, G, R, ret = 0;
int arr[51][51], visited[51][51];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
vector<int> Gv, Rv;
vector<pair<int, int>> v;

int bfs() {
	int cnt = 0;
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> Gq, Rq;
	for (auto& it : Gv) {
		Gq.push(make_pair(v[it].first, v[it].second));
		visited[v[it].first][v[it].second] = 1;
	}

	for (auto& it : Rv) {
		Rq.push(make_pair(v[it].first, v[it].second));
		visited[v[it].first][v[it].second] = 1;
	}

	int y, x, ny, nx, len, t = 1;
	while (!Gq.empty() && !Rq.empty()) {
		t++;
		len = Gq.size();
		while (len--) {
			y = Gq.front().first;
			x = Gq.front().second;
			Gq.pop();
			if (visited[y][x] == -1) continue;

			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == m || visited[ny][nx] || !arr[ny][nx]) continue;
				Gq.push(make_pair(ny, nx));
				visited[ny][nx] = t;
			}
		}

		len = Rq.size();
		while (len--) {
			y = Rq.front().first;
			x = Rq.front().second;
			Rq.pop();

			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == m || !arr[ny][nx]) continue;
				if (visited[ny][nx] == t) {
					visited[ny][nx] = -1;
					cnt++;
				}
				else if (!visited[ny][nx]) {
					Rq.push(make_pair(ny, nx));
					visited[ny][nx] = -1;
				}
			}
		}
	}

	return cnt;
}

void dfs(int idx, int g, int r) {
	if (g + r == 0) {
		int val = bfs();
		ret = ret < val ? val : ret;
		return;
	}
	if (idx == v.size()) return;

	if (g) {
		Gv.push_back(idx);
		dfs(idx + 1, g - 1, r);
		Gv.pop_back();
	}

	if (r) {
		Rv.push_back(idx);
		dfs(idx + 1, g, r - 1);
		Rv.pop_back();
	}

	dfs(idx + 1, g, r);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> G >> R;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) v.push_back(make_pair(i, j));
		}
	}
	dfs(0, G, R);
	cout << ret << '\n';
	return 0;
}