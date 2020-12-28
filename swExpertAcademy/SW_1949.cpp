// 복습 -등산로 조성
// 11:33

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int test_case, n, k, res;
int arr[9][9];
bool visited[9][9];

class Point {
public:
	int y, x;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
vector<Point> v;

void dfs(int _y, int _x, bool used, int cnt) {
	int y, x;
	for (int i = 0; i < 4; i++) {
		y = _y + p[i].y;
		x = _x + p[i].x;
		if (x >= 0 && x < n && y >= 0 && y < n && !visited[y][x]) {
			if (arr[_y][_x] - arr[y][x] > 0) {
				visited[y][x] = true;
				dfs(y, x, used, cnt + 1);
				visited[y][x] = false;
			}
			else {
				if (!used && (arr[y][x] - arr[_y][_x] < k)) {
					int tmp = arr[y][x];
					arr[y][x] = arr[_y][_x] - 1;
					visited[y][x] = true;
					dfs(y, x, true, cnt + 1);
					arr[y][x] = tmp;
					visited[y][x] = false;
				}
			}
		}
	}
	res = res < cnt ? cnt : res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("sample_input.txt", "r", stdin);
	int max_v;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		cin >> n >> k;
		res = 1;
		max_v = 0;
		v.clear();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				max_v = max_v < arr[i][j] ? arr[i][j] : max_v;
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (arr[i][j] == max_v)
					v.push_back({ i, j });
		int len = v.size();
		for (int i = 0; i < len; i++) {
			visited[v[i].y][v[i].x] = true;
			dfs(v[i].y, v[i].x, false, 1);
			visited[v[i].y][v[i].x] = false;
		}

		cout << "#" << tc << " " << res << '\n';
	}
	return 0;
}

// #define _CRT_SECURE_NO_WARNINGS
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <string.h>

// using namespace std;

// int n, k, res;
// int arr[9][9];
// bool visited[9][9];
// int dy[4] = { 0, 0, 1, -1 };
// int dx[4] = { 1, -1, 0, 0 };
// vector<pair<int, int>> v;

// void dfs(int y, int x, bool flag, int cnt) {
// 	res = max(res, cnt);
// 	int ny, nx;
// 	for (int i = 0; i < 4; i++) {
// 		ny = y + dy[i];
// 		nx = x + dx[i];
// 		if (ny < 0 || ny == n || nx < 0 || nx == n || visited[ny][nx]) continue;
// 		if (arr[y][x] > arr[ny][nx]) {
// 			visited[ny][nx] = true;
// 			dfs(ny, nx, flag, cnt + 1);
// 			visited[ny][nx] = false;
// 		}
// 		else {
// 			if (!flag) continue;
// 			if (k <= arr[ny][nx] - arr[y][x]) continue;
// 			int pre = arr[ny][nx];
// 			arr[ny][nx] = arr[y][x] - 1;
// 			flag = false;
// 			dfs(ny, nx, flag, cnt + 1);
// 			arr[ny][nx] = pre;
// 			flag = true;
// 		}
// 	}
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	//freopen("sample_input.txt", "r", stdin);
// 	int test_case, highest;
// 	cin >> test_case;
// 	for (int tc = 1; tc <= test_case; tc++) {
// 		cin >> n >> k;
// 		highest = 0;
// 		res = 0;
// 		v.clear();
// 		memset(visited, false, sizeof(visited));
// 		for (int i = 0; i < n; i++) {
// 			for (int j = 0; j < n; j++) {
// 				cin >> arr[i][j];
// 				highest = max(highest, arr[i][j]);
// 			}
// 		}
// 		for (int i = 0; i < n; i++)
// 			for (int j = 0; j < n; j++)
// 				if (arr[i][j] == highest)
// 					v.push_back(make_pair(i, j));
// 		for (int i = 0; i < v.size(); i++) {
// 			visited[v[i].first][v[i].second] = true;
// 			dfs(v[i].first, v[i].second, true, 1);
// 			visited[v[i].first][v[i].second] = false;
// 		}
// 		cout << "#" << tc << " " << res << '\n';
// 	}
// 	return 0;
// }