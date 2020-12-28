// 탈주범 검거
// 10:00

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int test_case, n, m, r, c, l, res;
int arr[51][51];
bool visited[51][51];

int pipe[8][4] = { {0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 1, 1}, {1, 1, 0, 0},
				   {1, 0, 0, 1}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 1, 0, 1} };

class Point {
public:
	int y, x, cnt;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void bfs() {
	queue<Point> q;
	q.push({ r, c, 1});
	visited[r][c] = true;
	int y, x, ny, nx, nd, cnt;
	while (!q.empty()) {
		y = q.front().y;
		x = q.front().x;
		cnt = q.front().cnt;
		q.pop();
		if (cnt == l) break;
		for (int i = 0; i < 4; i++) {
			ny = y + p[i].y;
			nx = x + p[i].x;
			if (ny >= 0 && ny < n && nx >= 0 && nx < m && pipe[arr[y][x]][i] && arr[ny][nx] && !visited[ny][nx]) {
				if (i & 1) nd = i - 1;
				else nd = i + 1;
				if (pipe[arr[ny][nx]][nd]) {
					q.push({ ny, nx, cnt + 1 });
					visited[ny][nx] = true;
					res++;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("sample_input.txt", "r", stdin);
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		res = 1;
		memset(visited, false, sizeof(visited));
		cin >> n >> m >> r >> c >> l;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> arr[i][j];
		bfs();
		cout << "#" << tc << " " << res << '\n';
	}
	return 0;
}

// #define _CRT_SECURE_NO_WARNINGS
// #include <iostream>
// #include <queue>
// #include <string.h>

// using namespace std;

// int n, m, r, c, l;
// int arr[51][51];
// bool visited[51][51];
// int dy[4] = { 1, -1, 0, 0 };
// int dx[4] = { 0, 0, 1, -1 };
// bool block[8][4] = { {0, 0, 0, 0}, {1, 1, 1, 1}, {1, 1, 0, 0}, {0, 0, 1, 1},
// 					{0, 1, 1, 0}, {1, 0, 1, 0}, {1, 0, 0, 1}, {0, 1, 0, 1} };

// int bfs() {
// 	queue<pair<int, int>> q;
// 	q.push(make_pair(r, c));
// 	visited[r][c] = true;
// 	int y, x, ny, nx, d, blk_num, len, cnt = 1, sec = l - 1;
// 	while (sec--) {
// 		len = q.size();
// 		while (len--) {
// 			y = q.front().first;
// 			x = q.front().second;
// 			q.pop();
// 			blk_num = arr[y][x];
// 			for (int i = 0; i < 4; i++) {
// 				if (!block[blk_num][i]) continue;
// 				ny = y + dy[i];
// 				nx = x + dx[i];
// 				if (ny < 0 || ny == n || nx < 0 || nx == m || visited[ny][nx] || !arr[ny][nx]) continue;
// 				if (i % 2 == 0) d = i + 1;
// 				else d = i - 1;
// 				if (!block[arr[ny][nx]][d]) continue;
// 				q.push(make_pair(ny, nx));
// 				visited[ny][nx] = true;
// 				cnt++;
// 			}
// 		}
// 	}
// 	return cnt;
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	//freopen("sample_input.txt", "r", stdin);
// 	int test_case;
// 	cin >> test_case;
// 	for (int tc = 1; tc <= test_case; tc++) {
// 		memset(visited, false, sizeof(visited));
// 		cin >> n >> m >> r >> c >> l;
// 		for (int i = 0; i < n; i++)
// 			for (int j = 0; j < m; j++)
// 				cin >> arr[i][j];
// 		cout << "#" << tc << " " << bfs() << '\n';
// 	}
// 	return 0;
// }