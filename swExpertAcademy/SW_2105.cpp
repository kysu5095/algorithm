// 디저트 카페
// 9:15

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

int test_case, n, res;
int arr[21][21];
bool visited[101];

class Point {
public:
	int y, x;
};
Point p[4] = { {1, -1}, {1, 1}, {-1, 1}, {-1, -1} };

void dfs(int _y, int _x, int _sy, int _sx, int _d, int _cnt) {
	int ny, nx;
	ny = _y + p[_d].y;
	nx = _x + p[_d].x;
	if (ny == _sy && nx == _sx) {
		res = res < _cnt ? _cnt : res;
		return;
	}
	if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[arr[ny][nx]]) {
		visited[arr[ny][nx]] = true;
		dfs(ny, nx, _sy, _sx, _d, _cnt + 1);
		visited[arr[ny][nx]] = false;
	}
	if (_d != 3) {
		ny = _y + p[_d + 1].y;
		nx = _x + p[_d + 1].x;
		if (ny == _sy && nx == _sx) {
			res = res < _cnt ? _cnt : res;
			return;
		}
		if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[arr[ny][nx]]) {
			visited[arr[ny][nx]] = true;
			dfs(ny, nx, _sy, _sx, _d + 1, _cnt + 1);
			visited[arr[ny][nx]] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("sample_input.txt", "r", stdin);
	cin >> test_case;
	int ny, nx;
	for (int tc = 1; tc <= test_case; tc++) {
		res = 0;
		memset(visited, false, sizeof(visited));
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];

		for (int i = 0; i < n - 2; i++) {
			for (int j = 1; j < n - 1; j++) {
				ny = i + p[0].y;
				nx = j + p[0].x;
				if (arr[i][j] != arr[ny][nx]) {
					visited[arr[i][j]] = true;
					visited[arr[ny][nx]] = true;
					dfs(ny, nx, i, j, 0, 2);
					visited[arr[i][j]] = false;
					visited[arr[ny][nx]] = false;
				}
			}
		}
		if (!res)
			cout << "#" << tc << " -1\n";
		else
			cout << "#" << tc << " " << res << '\n';
	}
	return 0;
}

// #define _CRT_SECURE_NO_WARNINGS
// #include <iostream>
// #include <string.h>
// #include <algorithm>

// using namespace std;

// int n, sy, sx, res;
// int arr[21][21];
// bool visited[101];
// int dy[4] = { 1, 1, -1, -1 };
// int dx[4] = { -1, 1, 1, -1 };

// void dfs(int y, int x, int d, int cnt) {
// 	int ny = y + dy[d];
// 	int nx = x + dx[d];
// 	if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
// 		if (ny == sy && nx == sx) {
// 			res = max(res, cnt);
// 			return;
// 		}
// 		if (!visited[arr[ny][nx]]) {
// 			visited[arr[ny][nx]] = true;
// 			dfs(ny, nx, d, cnt + 1);
// 			visited[arr[ny][nx]] = false;
// 		}
// 	}
// 	if (d == 3) return;
// 	ny = y + dy[d + 1];
// 	nx = x + dx[d + 1];
// 	if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
// 		if (ny == sy && nx == sx) {
// 			res = max(res, cnt);
// 			return;
// 		}
// 		if (!visited[arr[ny][nx]]) {
// 			visited[arr[ny][nx]] = true;
// 			dfs(ny, nx, d + 1, cnt + 1);
// 			visited[arr[ny][nx]] = false;
// 		}
// 	}
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	//freopen("sample_input.txt", "r", stdin);
// 	int test_case, ny, nx;
// 	cin >> test_case;
// 	for (int tc = 1; tc <= test_case; tc++) {
// 		res = -1;
// 		memset(visited, false, sizeof(visited));
// 		cin >> n;
// 		for (int i = 0; i < n; i++)
// 			for (int j = 0; j < n; j++)
// 				cin >> arr[i][j];
// 		for (int i = 0; i < n - 2; i++) {
// 			for (int j = 1; j < n - 1; j++) {
// 				visited[arr[i][j]] = true;
// 				ny = i + dy[0];
// 				nx = j + dx[0];
// 				if (arr[ny][nx] != arr[i][j]) {
// 					sy = i; sx = j;
// 					visited[arr[ny][nx]] = true;
// 					dfs(ny, nx, 0, 2);
// 					visited[arr[ny][nx]] = false;
// 				}
// 				visited[arr[i][j]] = false;
// 			}
// 		}
// 		cout << "#" << tc << " " << res << '\n';
// 	}
// 	return 0;
// }