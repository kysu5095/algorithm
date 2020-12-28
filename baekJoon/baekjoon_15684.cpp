// 사다리 조작 //
////////////////

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, h, plusLine = 0;
int arr[31][11][2] = { { {0, }, }, };
class Point {
public:
	int x, y;
};
queue<Point> q;

bool find() {
	for (int i = 0; i < n; i++) {
		int x = i, y = 0;
		while (true) {
			if (y == h) {
				if (x == i) break;
				else return false;
			}
			if (arr[y][x][0] == 1)
				x++;
			else if (arr[y][x][1] == 1)
				x--;

			y++;
		}
	}

	return true;
}

bool isPut(int x, int y) {
	if (arr[y][x][0] == 1 || arr[y][x][1] == 1) return false;
	if (arr[y][x + 1][0] == 1) return false;
	return true;
}

bool dfs(int cnt, int x, int y) {
	if (cnt == plusLine) {
		if (find()) return true;
		else return false;
	}
	for (int i = y; i < h; i++) {
		for (int j = 0; j < n - 1; j++) {
			if(j<x&&i==y)continue;
			if (isPut(j, i)) {
				arr[i][j][0] = 1;
				arr[i][j + 1][1] = 1;
				if (dfs(cnt + 1, j , i)) return true;
				arr[i][j][0] = 0;
				arr[i][j + 1][1] = 0;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		arr[x - 1][y - 1][0] = 1;
		arr[x - 1][y][1] = 1;
	}
	for (int i = 0; i < 4; i++) {
		if (dfs(0, 0, 0)) break;
		plusLine++;
	}
	if (plusLine == 4) cout << -1 << '\n';
	else cout << plusLine << '\n';
	return 0;
}

// #include <iostream>

// using namespace std;

// int n, m, h, result = 987654321;
// int arr[31][11] = { {0, }, };

// bool move() {
// 	for (int width = 0; width < n; width++) {
// 		int j = width;
// 		int i = 0;
// 		while (i != h) {
// 			if (arr[i][j] == 0) {
// 				i++;
// 				continue;
// 			}
// 			j += arr[i][j];
// 			i++;
// 		}
// 		if (j != width)
// 			return false;
// 	}
// 	return true;
// }

// void dfs(int y, int x, int cnt) {
// 	if (cnt == 4 || cnt >= result)
// 		return;
// 	if (move()) {
// 		result = result > cnt ? cnt : result;
// 		return;
// 	}

// 	for (int i = y; i < h; i++) {
// 		for (int j = 0; j < n - 1; j++) {
// 			if (arr[i][j] == 0 && arr[i][j + 1] == 0) {
// 				arr[i][j] = 1;
// 				arr[i][j + 1] = -1;
// 				dfs(i, j + 2, cnt + 1);
// 				arr[i][j] = 0;
// 				arr[i][j + 1] = 0;
// 			}
// 		}
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);

// 	int a, b;
// 	cin >> n >> m >> h;
// 	for (int i = 0; i < m; i++) {
// 		cin >> a >> b;
// 		arr[a - 1][b - 1] = 1;
// 		arr[a - 1][b] = -1;
// 	}
// 	dfs(0, 1, 0);

// 	if (result == 987654321)
// 		cout << -1 << '\n';
// 	else
// 		cout << result << '\n';

// 	return 0;
// }

// #include <iostream>

// using namespace std;

// int n, m, h, lain = 1, res = -1;
// int arr[31][11][2] = { { {0,},}, };
// int dy[3] = { 1, 0, 0 };
// int dx[3] = { 0, 1, -1 };

// bool game() {
// 	int y, x, d, ny, nx;
// 	for (int i = 1; i <= n; i++) {
// 		y = 1;
// 		x = i;
// 		d = 0;
// 		while (true) {
// 			if (arr[y][x][0] == 0) y++;
// 			else {
// 				if (d == 0) {
// 					d = arr[y][x][1];
// 					x += dx[d];
// 				}
// 				else {
// 					d = 0;
// 					y++;
// 				}
// 			}
// 			if (y == h + 1) {
// 				if (x == i) break;
// 				else return false;
// 			}
// 		}
// 	}
// 	return true;
// }

// void dfs(int y, int x, int cnt) {
// 	if (res != -1) return;
// 	if (cnt == lain) {
// 		if (game()) res = lain;
// 		return;
// 	}
// 	if (y > h) return;
// 	if (x >= n) {
// 		dfs(y + 1, 1, cnt);
// 		return;
// 	}
// 	if (arr[y][x][0]) {
// 		if (arr[y][x][1] == 1) dfs(y, x + 2, cnt);
// 		else dfs(y, x + 1, cnt);
// 		return;
// 	}
// 	else {
// 		if (arr[y][x + 1][0]) dfs(y, x + 3, cnt);
// 		else {
// 			arr[y][x][0] = 1;
// 			arr[y][x][1] = 1;
// 			arr[y][x + 1][0] = 1;
// 			arr[y][x + 1][1] = 2;
// 			dfs(y, x + 2, cnt + 1);
// 			arr[y][x][0] = 0;
// 			arr[y][x][1] = 0;
// 			arr[y][x + 1][0] = 0;
// 			arr[y][x + 1][1] = 0;
// 			dfs(y, x + 1, cnt);
// 		}
// 	}
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	int y, x;
// 	cin >> n >> m >> h;
// 	while (m--) {
// 		cin >> y >> x;
// 		arr[y][x][0] = 1;
// 		arr[y][x][1] = 1;
// 		arr[y][x + 1][0] = 1;
// 		arr[y][x + 1][1] = 2;
// 	}
// 	if (game()) res = 0;
// 	while (res == -1) {
// 		dfs(0, 0, 0);
// 		if (lain++ == 3) break;
// 	}
// 	cout << res << '\n';
// 	return 0;
// }