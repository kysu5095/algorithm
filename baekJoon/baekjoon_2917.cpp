// 늑대 사냥꾼

//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, sy, sx;
char arr[501][501];
int dist[501][501];
bool visited[501][501];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
vector<pair<int, int>> v;

int bfs() {
	priority_queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(dist[sy][sx], make_pair(sy, sx)));
	int y, x, ny, nx, val;
	while (!q.empty()) {
		y = q.top().second.first;
		x = q.top().second.second;
		val = q.top().first;
		q.pop();
		if (visited[y][x]) continue;
		visited[y][x] = true;
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == n || nx < 0 || nx == m || visited[ny][nx]) continue;
			if (arr[ny][nx] == '+') continue;
			if (arr[ny][nx] == 'J') return val;
			q.push(make_pair(min(val, dist[ny][nx]), make_pair(ny, nx)));
		}
	}
	return false;
}

void get_dis() {
	queue<pair<int, int>> q;
	for (auto idx : v) 
		q.push(make_pair(idx.first, idx.second));

	int y, x, ny, nx, len;
	while (!q.empty()) {
		len = q.size();
		while (len--) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == m || arr[ny][nx] == '+') continue;
				if (dist[ny][nx]) continue;
				q.push(make_pair(ny, nx));
				dist[ny][nx] = dist[y][x] + 1;
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("vuk.in.6", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'V') {
				sy = i;
				sx = j;
			}
			else if (arr[i][j] == '+') 
				v.push_back(make_pair(i, j));
		}
	}
	get_dis();
	int res = bfs();
	cout << res << '\n';
	//fclose(stdin);
	return 0;
}