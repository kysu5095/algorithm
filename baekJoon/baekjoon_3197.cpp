// 백조의 호수
// 아래 이분탐색으로 푼거 있읍

#include <iostream>
#include <queue>

using namespace std;

int r, c;
char arr[1501][1501];
bool visited[1501][1501] = { {false,}, };

class Point {
public:
	int y, x;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
queue<pair<int, int>> water;

int bfs(int _y, int _x) {
	queue<pair<int, int>> q;
	visited[_y][_x] = true;
	q.push(make_pair(_y, _x));
	int y, x, ny, nx, len, t = 0;
	while (true) {
		queue<pair<int, int>> tmp;
		while (!q.empty()) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + p[i].y;
				nx = x + p[i].x;
				if (ny >= 0 && ny < r && nx >= 0 && nx < c && !visited[ny][nx]) {
					if (arr[ny][nx] == 'L' && (ny != _y || nx != _x))
						return t;

					visited[ny][nx] = true;
					if (arr[ny][nx] == '.') q.push(make_pair(ny, nx));
					if (arr[ny][nx] == 'X') {
						arr[ny][nx] = '.';
						tmp.push(make_pair(ny, nx));
					}
				}
			}
		}
		q = tmp;
		
		len = water.size();
		while (len--) {
			y = water.front().first;
			x = water.front().second;
			water.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + p[i].y;
				nx = x + p[i].x;
				if (ny >= 0 && ny < r && nx >= 0 && nx < c && arr[ny][nx] == 'X') {
					arr[ny][nx] = '.';
					water.push(make_pair(ny, nx));
				}
			}
		}
		t++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int sy, sx;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> arr[i];
		for (int j = 0; j < c; j++) {
			if (arr[i][j] != 'X') {
				if (arr[i][j] == 'L') sy = i, sx = j;
				water.push(make_pair(i, j));
			}
		}
	}
	cout << bfs(sy, sx) << '\n';
	return 0;
}

// // 백조의 호수

// #include <iostream>
// #include <queue>
// #include <string.h>

// using namespace std;

// int r, c, start = 0, last, mid;
// int map[1501][1501] = { {0,}, };
// char arr[1501][1501];
// bool visited[1501][1501] = { {false,}, };
// int dy[4] = { 0, 0, 1, -1 };
// int dx[4] = { 1, -1, 0, 0 };
// queue<pair<int, int>> water;

// void spread() {
// 	int y, x, ny, nx, len, cnt = 1;
// 	while (!water.empty()) {
// 		last = cnt;
// 		len = water.size();
// 		while (len--) {
// 			y = water.front().first;
// 			x = water.front().second;
// 			water.pop();
// 			for (int i = 0; i < 4; i++) {
// 				ny = y + dy[i];
// 				nx = x + dx[i];
// 				if (ny < 0 || ny == r || nx < 0 || nx == c)continue;
// 				if (arr[ny][nx] == '.' || arr[ny][nx] == 'L')continue;
// 				water.push(make_pair(ny, nx));
// 				arr[ny][nx] = '.';
// 				map[ny][nx] = cnt;
// 			}
// 		}
// 		cnt++;
// 	}
// }

// bool bfs(int& sy, int& sx, int& t) {
// 	memset(visited, false, sizeof(visited));
// 	queue<pair<int, int>> q;
// 	q.push(make_pair(sy, sx));
// 	visited[sy][sx] = true;
// 	int y, x, ny, nx;
// 	while (!q.empty()) {
// 		y = q.front().first;
// 		x = q.front().second;
// 		q.pop();
// 		for (int i = 0; i < 4; i++) {
// 			ny = y + dy[i];
// 			nx = x + dx[i];
// 			if (ny < 0 || ny == r || nx < 0 || nx == c || visited[ny][nx]) continue;
// 			if (map[ny][nx] > t) continue;
// 			if (arr[ny][nx] == 'L' && (ny != sy || nx != sx)) return true;
// 			visited[ny][nx] = true;
// 			q.push(make_pair(ny, nx));
// 		}
// 	}
// 	return false;
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	int sy, sx, res;
// 	cin >> r >> c;
// 	for (int i = 0; i < r; i++) {
// 		cin >> arr[i];
// 		for (int j = 0; j < c; j++) {
// 			if (arr[i][j] == 'L') {
// 				sy = i;
// 				sx = j;
// 				water.push(make_pair(i, j));
// 			}
// 			if (arr[i][j] == '.')
// 				water.push(make_pair(i, j));
// 		}
// 	}
// 	spread();
// 	while (start <= last) {
// 		mid = (start + last) >> 1;
// 		if (bfs(sy, sx, mid)) {
// 			res = mid;
// 			last = mid - 1;
// 		}
// 		else start = mid + 1;
// 	}
// 	cout << res << '\n';
// 	return 0;
// }