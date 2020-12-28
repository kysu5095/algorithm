// 연구소 3
// 11:00

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <limits.h>

using namespace std;

int n, m, cnt = 0, res = INT_MAX;
int arr[51][51] = { {0,}, };
int tmp[51][51];
int virus[11] = { -1, };

class Point {
public:
	int y, x;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
vector<pair<int, int>> v;

int bfs() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp[i][j] = arr[i][j];
	queue<pair<int, int>> q;
	for (int i = 0; i < m; i++) {
		q.push(make_pair(v[virus[i]].first, v[virus[i]].second));
		tmp[v[virus[i]].first][v[virus[i]].second] = -2;
	}
	int y, x, ny, nx, len, v_cnt = cnt, t = 0;
	while (!q.empty()) {
		t++;
		len = q.size();
		while (len--) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + p[i].y;
				nx = x + p[i].x;
				if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
					if (!tmp[ny][nx] || tmp[ny][nx] == -1) {
						if (!tmp[ny][nx]) v_cnt--;
						q.push(make_pair(ny, nx));
						tmp[ny][nx] = t;
					}
				}
			}
		}
		if (!v_cnt) return t;
	}
	return INT_MAX;
}

void dfs(int idx, int cnt) {
	if (cnt == m) {
		int t = bfs();
		res = res > t ? t : res;
		return;
	}
	int len = v.size();
	for (int i = idx; i < len; i++) {
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
			if (!arr[i][j]) cnt++;
			else if (arr[i][j] == 1)
				arr[i][j] = -2;
			else if (arr[i][j] == 2) {
				arr[i][j] = -1;
				v.push_back(make_pair(i, j));
			}
		}
	}
	if (cnt)
		dfs(0, 0);
	else
		res = 0;
	if (res == INT_MAX) res = -1;
	cout << res << '\n';
	return 0;
}

// #include <iostream>
// #include <queue>
// #include <string.h>
// #include <vector>
// #include <limits.h>

// using namespace std;

// int n, m, emt = 0, res = INT_MAX;
// int arr[51][51];
// bool visited[51][51];
// int dy[4] = { 0, 0, 1, -1 };
// int dx[4] = { 1, -1, 0, 0 };
// vector<pair<int, int>> v;
// int virus[11] = { 0, };

// void bfs() {
// 	queue<pair<int, int>> q;
// 	for (int i = 0; i < v.size(); i++) {
// 		if (virus[i]) {
// 			q.push(make_pair(v[i].first, v[i].second));
// 			visited[v[i].first][v[i].second] = true;
// 		}
// 	}
// 	int y, x, ny, nx, len, cnt = emt, sec = 0;
// 	while (!q.empty()) {
// 		sec++;
// 		len = q.size();
// 		while (len--) {
// 			y = q.front().first;
// 			x = q.front().second;
// 			q.pop();
// 			for (int i = 0; i < 4; i++) {
// 				ny = y + dy[i];
// 				nx = x + dx[i];
// 				if (ny < 0 || ny == n || nx < 0 || nx == n || visited[ny][nx]) continue;
// 				if (arr[ny][nx] == 1) continue;
// 				q.push(make_pair(ny, nx));
// 				visited[ny][nx] = true;
// 				if (!arr[ny][nx]) cnt--;
// 				if (cnt == 0) {
// 					res = min(res, sec);
// 					return;
// 				}
// 			}
// 		}
// 	}
// }

// void dfs(int idx, int cnt) {
// 	if (cnt == m) {
// 		memset(visited, false, sizeof(visited));
// 		bfs();
// 		return;
// 	}
// 	for (int i = idx; i < v.size(); i++) {
// 		virus[i] = 1;
// 		dfs(i + 1, cnt + 1);
// 		virus[i] = 0;
// 	}
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	cin >> n >> m;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			cin >> arr[i][j];
// 			if (arr[i][j] == 2)
// 				v.push_back(make_pair(i, j));
// 			else if (arr[i][j] == 0)
// 				emt++;
// 		}
// 	}
// 	if (emt == 0) res = 0;
// 	else dfs(0, 0);
// 	if (res == INT_MAX) res = -1;
// 	cout << res << '\n';
// 	return 0;
// }