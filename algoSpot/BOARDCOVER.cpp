// 게임판 덮기

#include <iostream>

using namespace std;

int test_case, h, w;
char arr[21][21];
int dy[4][2] = { {1, 1}, {0, 1}, {1, 1}, {0, 1} };
int dx[4][2] = { {-1, 0}, {1, 1}, {0, 1}, {1, 0} };

int dfs(int y, int x, int cnt) {
	int ret = 0;
	if (!cnt) return 1;
	if (y == h) return 0;
	if (x == w) return dfs(y + 1, 0, cnt);
	if (arr[y][x] != '.') return dfs(y, x + 1, cnt);
	int y1, y2, x1, x2;
	for (int i = 0; i < 4; i++) {
		y1 = y + dy[i][0], x1 = x + dx[i][0];
		y2 = y + dy[i][1], x2 = x + dx[i][1];
		if (y1 == h || y2 == h || x1 < 0 || x1 == w || x2 < 0 || x2 == w) continue;
		if (arr[y1][x1] == '.' && arr[y2][x2] == '.') {
			arr[y][x] = '#', arr[y1][x1] = '#', arr[y2][x2] = '#';
			ret += dfs(y, x + 1, cnt - 3);
			arr[y][x] = '.', arr[y1][x1] = '.', arr[y2][x2] = '.';
		}
	}
	return ret;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int cnt;
	cin >> test_case;
	while (test_case--) {
		cnt = 0;
		cin >> h >> w;
		for (int i = 0; i < h; i++) {
			cin >> arr[i];
			for (int j = 0; j < w; j++)
				if (arr[i][j] == '.') cnt++;
		}
		cout << dfs(0, 0, cnt) << '\n';
	}
	return 0;
}