// Gaaaaaaaaaarden

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

int n, m, g, r, ret = 0;
int arr[51][51];
int map[51][51];
int flower[10];
bool visited[51][51];
vector<pair<int, int>> land;
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0 ,0 };

int bfs() {
	int y, x, ny, nx, len, cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			map[i][j] = arr[i][j];
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> green;
	queue<pair<int, int>> red;
	len = land.size();
	for (int i = 0; i < len; i++) {
		if (flower[i] == 0) continue;
		y = land[i].first;
		x = land[i].second;
		if (flower[i] == 1) {
			visited[y][x] = true;
			green.push(make_pair(y, x));
		}
		else {
			visited[y][x] = true;
			red.push(make_pair(y, x));
		}
	}
	int t = 3;
	while (!green.empty() && !red.empty()) {
		len = green.size();
		while (len--) {
			y = green.front().first;
			x = green.front().second;
			green.pop();
			if (map[y][x] == 0) continue;
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == m) continue;
				if (visited[ny][nx] || map[ny][nx] == 0) continue;
				map[ny][nx] = t;
				visited[ny][nx] = true;
				green.push(make_pair(ny, nx));
			}
		}
		len = red.size();
		while (len--) {
			y = red.front().first;
			x = red.front().second;
			red.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == m) continue;
				if (map[ny][nx] == t) {
					map[ny][nx] = 0;
					cnt++;
					continue;
				}
				if (visited[ny][nx] || map[ny][nx] == 0) continue;
				visited[ny][nx] = true;
				red.push(make_pair(ny, nx));
			}
		}
		t++;
	}
	return cnt;
}

void cal(int _g, int _r, int no, int idx) {
	if (!_g && !_r) {
		ret = max(ret, bfs());
		return;
	}
	int val = flower[idx];
	if (no) {
		flower[idx] = 0;
		cal(_g, _r, no - 1, idx + 1);
		flower[idx] = val;
	}
	if (_g) {
		flower[idx] = 1;
		cal(_g - 1, _r, no, idx + 1);
		flower[idx] = val;
	}
	if (_r) {
		flower[idx] = 2;
		cal(_g, _r - 1, no, idx + 1);
		flower[idx] = val;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> g >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				land.push_back(make_pair(i, j));
		}
	}
	cal(g, r, land.size() - (g + r), 0);
	cout << ret << '\n';
	return 0;
}

// #include <iostream>
// #include <queue>
// #include <string.h>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int n, m, G, R, res = 0;
// int arr[51][51];
// bool visited[51][51];
// int dy[4] = { 0, 0, 1, -1 };
// int dx[4] = { 1, -1, 0, 0 };
// vector<pair<int, int>> v;

// void copy_arr(int tmp[][51], bool flag) {
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			if (flag) tmp[i][j] = arr[i][j];
// 			else arr[i][j] = tmp[i][j];
// 		}
// 	}
// }

// int bfs() {
// 	int y, x, ny, nx, len, cnt = 0, sec = 4;
// 	memset(visited, false, sizeof(visited));
// 	queue<pair<int, int>> red, green;
// 	for (int i = 0; i < v.size(); i++) {
// 		y = v[i].first;
// 		x = v[i].second;
// 		if (arr[y][x] == 2) green.push(make_pair(y, x));
// 		else if (arr[y][x] == 3) red.push(make_pair(y, x));
// 		else continue;
// 		visited[y][x] = true;
// 	}
// 	while (!green.empty() && !red.empty()) {
// 		len = green.size();
// 		while (len--) {
// 			y = green.front().first;
// 			x = green.front().second;
// 			green.pop();
// 			if (arr[y][x] == 0) continue;
// 			for (int i = 0; i < 4; i++) {
// 				ny = y + dy[i];
// 				nx = x + dx[i];
// 				if (ny < 0 || ny == n || nx < 0 || nx == m || visited[ny][nx]) continue;
// 				if (arr[ny][nx] == 1) {
// 					green.push(make_pair(ny, nx));
// 					arr[ny][nx] = sec;
// 					visited[ny][nx] = true;
// 				}
// 			}
// 		}
// 		len = red.size();
// 		while (len--) {
// 			y = red.front().first;
// 			x = red.front().second;
// 			red.pop();
// 			for (int i = 0; i < 4; i++) {
// 				ny = y + dy[i];
// 				nx = x + dx[i];
// 				if (ny < 0 || ny == n || nx < 0 || nx == m) continue;
// 				if (arr[ny][nx] == sec) {
// 					cnt++;
// 					arr[ny][nx] = 0;
// 					continue;
// 				}
// 				if (visited[ny][nx]) continue;
// 				if (arr[ny][nx] == 1) {
// 					red.push(make_pair(ny, nx));
// 					visited[ny][nx] = true;
// 				}
// 			}
// 		}
// 		sec++;
// 	}
// 	return cnt;
// }

// void dfs(int g, int r, int no, int cnt) {
// 	if (!g && !r && !no) {
// 		int tmp[51][51];
// 		copy_arr(tmp, true);
// 		int val = bfs();
// 		copy_arr(tmp, false);
// 		res = max(res, val);
// 		return;
// 	}
// 	int y = v[cnt].first;
// 	int x = v[cnt].second;
// 	if (g) {
// 		arr[y][x] = 2;
// 		dfs(g - 1, r, no, cnt + 1);
// 	}
// 	if (r) {
// 		arr[y][x] = 3;
// 		dfs(g, r - 1, no, cnt + 1);
// 	}
// 	if (no) {
// 		arr[y][x] = 1;
// 		dfs(g, r, no - 1, cnt + 1);
// 	}
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	cin >> n >> m >> G >> R;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			cin >> arr[i][j];
// 			if (arr[i][j] == 2)
// 				v.push_back(make_pair(i, j));
// 		}
// 	}
// 	dfs(G, R, v.size() - (G + R), 0);
// 	cout << res << '\n';
// 	return 0;
// }