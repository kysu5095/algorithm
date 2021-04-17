// 아기 상어

#include <stdio.h>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int n;
int arr[21][21];
bool visited[21][21];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int bfs(int& y, int& x, int& sz, int& cnt) {
	memset(visited, false, sizeof(visited));
	vector<pair<int, int>> v;
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visited[y][x] = true;
	int ny, nx, len, t = 0;
	while (!q.empty()) {
		t++;
		len = q.size();
		while (len--) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == n || visited[ny][nx] || arr[ny][nx] > sz) continue;
				if (arr[ny][nx] && arr[ny][nx] < sz) v.push_back(make_pair(ny, nx));
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
			}
		}
		if (v.empty()) continue;

		sort(v.begin(), v.end());
		y = v[0].first;
		x = v[0].second;
		arr[y][x] = 0;
		cnt++;
		if (sz == cnt) {
			sz++;
			cnt = 0;
		}
		return t;
	}
	return 0;
}

int move(int y, int x) {
	int sz = 2;
	int cnt = 0;
	int t = 0;
	while (true) {
		int nt = bfs(y, x, sz, cnt);
		if (nt == 0) break;
		t += nt;
	}
	return t;
}

int main() {
	int y, x, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %d", &arr[i][j]);
			if (arr[i][j] == 9) {
				y = i;
				x = j;
				arr[i][j] = 0;
			}
			else if (arr[i][j] >= 1 && arr[i][j] <= 6) cnt++;
		}
	}
	printf("%d\n", move(y, x));
	return 0;
}