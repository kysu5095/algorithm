// 레이저 통신
// 두번째 코드는 다시 푼 코드 시간, 메모리 더 소비함,,,

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <limits.h>

using namespace std;

int w, h;
char arr[101][101];
int visited[4][101][101] = { { {0, }, }, };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

bool is_range(int y, int x) {
	if (y >= 0 && y < h && x >= 0 && x < w && arr[y][x] != '*') return true;
	else return false;
}

int bfs(int _y, int _x) {
	int y, x, ny, nx, d, cnt, t = INT_MAX;
	queue<pair<pair<int, int>, pair<int, int>>> q;
	for (int i = 0; i < 4; i++) {
		q.push(make_pair(make_pair(_y, _x), make_pair(i, 1)));
		visited[i][_y][_x] = true;
	}
	while (!q.empty()) {
		y = q.front().first.first;
		x = q.front().first.second;
		d = q.front().second.first;
		cnt = q.front().second.second;
		q.pop();
		if (arr[y][x] == 'C' && (y != _y || x != _x)) {
			t = t > (cnt - 1) ? (cnt - 1) : t;
			continue;
		}
		ny = y + dy[d];
		nx = x + dx[d];
		if (is_range(ny, nx) && (!visited[d][ny][nx] || visited[d][ny][nx] > cnt)) {
			visited[d][ny][nx] = cnt;
			q.push(make_pair(make_pair(ny, nx), make_pair(d, cnt)));
		}
		// d >> 2, 3
		if (d <= 1) {
			for (int i = 2; i <= 3; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (is_range(ny, nx) && (!visited[i][ny][nx] || visited[i][ny][nx] > cnt + 1)) {
					visited[i][ny][nx] = cnt + 1;
					q.push(make_pair(make_pair(ny, nx), make_pair(i, cnt + 1)));
				}
			}
		}
		// d >> 0, 1
		else {
			for (int i = 0; i <= 1; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (is_range(ny, nx) && (!visited[i][ny][nx] || visited[i][ny][nx] > cnt + 1)) {
					visited[i][ny][nx] = cnt + 1;
					q.push(make_pair(make_pair(ny, nx), make_pair(i, cnt + 1)));
				}
			}
		}
	}
	return t;
}

int main() {
	int y, x;
	scanf("%d %d", &w, &h);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf(" %1c", &arr[i][j]);
			if (arr[i][j] == 'C') {
				y = i;
				x = j;
			}
		}
	}
	printf("%d\n", bfs(y, x));
	return 0;
}

// // 레이저 통신

// #include <iostream>
// #include <queue>
// #include <limits.h>
// #include <string.h>

// using namespace std;

// int w, h, sy = -1, sx = -1, fy = -1, fx = -1;
// char arr[101][101];
// int visited[4][101][101] = { { {0, }, }, };
// int dy[4] = { 0, 0, 1, -1 };
// int dx[4] = { 1, -1, 0, 0 };

// int bfs() {
// 	int y, x, ny, nx, d, c, t = INT_MAX;
// 	queue<pair<pair<int, int>, pair<int, int>>> q;
// 	for (int i = 0; i < 4; i++) {
// 		q.push(make_pair(make_pair(0, i), make_pair(sy, sx)));
// 		visited[i][sy][sx] = 0;
// 	}
// 	while (!q.empty()) {
// 		y = q.front().second.first;
// 		x = q.front().second.second;
// 		c = q.front().first.first;
// 		d = q.front().first.second;
// 		q.pop();
// 		if (y == fy && x == fx) {
// 			t = t > c ? c : t;
// 			continue;
// 		}
// 		for (int i = 0; i < 4; i++) {
// 			if (d % 2 == 0 && d + 1 == i) continue;
// 			else if (d % 2 == 1 && d - 1 == i) continue;
// 			ny = y + dy[i];
// 			nx = x + dx[i];
// 			if (ny < 0 || ny == h || nx < 0 || nx == w || arr[ny][nx] == '*') continue;
// 			if (i == d) {
// 				if (visited[i][ny][nx] == -1 || visited[i][ny][nx] > c) {
// 					q.push(make_pair(make_pair(c, i), make_pair(ny, nx)));
// 					visited[i][ny][nx] = c;
// 				}
// 			}
// 			else {
// 				if (visited[i][ny][nx] == -1 || visited[i][ny][nx] > c + 1) {
// 					q.push(make_pair(make_pair(c + 1, i), make_pair(ny, nx)));
// 					visited[i][ny][nx] = c + 1;
// 				}
// 			}
// 		}
// 	}
// 	return t;
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	cin >> w >> h;
// 	for (int i = 0; i < h; i++) {
// 		cin >> arr[i];
// 		for (int j = 0; j < w; j++) {
// 			if (arr[i][j] == 'C') {
// 				if (sy == -1) sy = i, sx = j;
// 				else fy = i, fx = j;
// 			}
// 		}
// 	}
// 	memset(visited, -1, sizeof(visited));
// 	cout << bfs() << '\n';
// 	return 0;
// }