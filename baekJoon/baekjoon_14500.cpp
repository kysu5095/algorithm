// 복습_테트로미노 //
////////////////////

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int maxV = 0;
int arr[501][501];
bool visited[501][501] = { {false, } };
bool visited2[4] = { false, };

class Point {
public:
	int x, y;
};
Point p[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

vector<Point> tetro;

void dfs(int x, int y, int cnt) {
	if (cnt == 3) {
		int tmpMax = 0;
		for (int i = 0; i < 4; i++) {
			tmpMax += arr[tetro[i].y][tetro[i].x];
		}
		maxV = max(maxV, tmpMax);

		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + p[i].x;
		int ny = y + p[i].y;
		if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
			if (!visited[ny][nx]) {
				visited[ny][nx] = true;
				tetro.push_back({ nx, ny });
				dfs(nx, ny, cnt + 1);
				visited[ny][nx] = false;
				tetro.pop_back();
			}
		}
	}
}

void dfs2(int x, int y, int cnt, int idx) {
	if (cnt == 3) {
		int tmpMax = arr[y][x];
		for (int i = 0; i < 4; i++) {
			if (visited2[i]) {
				int nx = x + p[i].x;
				int ny = y + p[i].y;
				if (!(nx >= 0 && nx < m && ny >= 0 && ny < n)) return;

				tmpMax += arr[ny][nx];
			}
		}
		maxV = max(maxV, tmpMax);
	}
	for (int i = idx; i < 4; i++) {
		if (!visited2[i]) {
			visited2[i] = true;
			dfs2(x, y, cnt + 1, i);
			visited2[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tetro.push_back({ j, i });
			visited[i][j] = true;
			dfs(j, i, 0);
			tetro.pop_back();
			visited[i][j] = false;
			dfs2(j, i, 0, 0);
		}
	}

	cout << maxV << '\n';

	return 0;
}

// #include<iostream>

// using namespace std;

// int n, m, max_value = 0;
// int arr[501][501] = { {0, }, };
// bool visited[501][501] = { {false, }, };
// class Point {
// public:
// 	int y, x;
// };
// Point p[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
// Point tetro[4];

// // 사각형 제외 나머지 도형들
// void dfs(int cnt) {
// 	if (cnt == 3) {
// 		int tmp = 0;
// 		for (int i = 0; i < 4; i++) {
// 			tmp += arr[tetro[i].y][tetro[i].x];
// 		}
// 		max_value = max_value < tmp ? tmp : max_value;
// 		return;
// 	}
// 	int x = tetro[cnt].x;
// 	int y = tetro[cnt].y;
// 	for (int i = 0; i < 4; i++) {
// 		int nx = x + p[i].x;
// 		int ny = y + p[i].y;
// 		if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[ny][nx]) {
// 			visited[ny][nx] = true;
// 			tetro[cnt + 1] = { ny, nx };
// 			dfs(cnt + 1);
// 			visited[ny][nx] = false;
// 		}
// 	}
// }

// // 사각형 만들기
// void dfs2(int cnt) {
// 	int x = tetro[0].x;
// 	int y = tetro[1].y;
// 	for (int i = 0; i < 4; i++) {
// 		int tmp = arr[y][x];
// 		for (int j = 0; j < 3; j++) {
// 			int d = (j + i) % 4;
// 			int nx = x + p[d].x;
// 			int ny = y + p[d].y;
// 			if (nx >= 0 && nx < m && ny >= 0 && ny < n) 
// 				tmp += arr[ny][nx];
// 			else
// 				break;

// 			if (j == 2) 
// 				max_value = max_value < tmp ? tmp : max_value;
// 		}
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);
// 	cin >> n >> m;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			cin >> arr[i][j];
// 		}
// 	}
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			visited[i][j] = true;
// 			tetro[0] = { i, j };
// 			dfs(0);
// 			dfs2(0);
// 			visited[i][j] = false;
// 		}
// 	}

// 	cout << max_value << '\n';
// 	return 0;
// }

// #include <iostream>
// #include <algorithm>
// #include <queue>

// using namespace std;

// int n, m, res = 0;
// int arr[501][501];
// int dy[4] = { 0, 0, 1, -1 };
// int dx[4] = { 1, -1, 0, 0 };

// void dfs(int y, int x, int d, int total, int cnt) {
// 	if (cnt == 3) {
// 		res = max(res, total);
// 		return;
// 	}
// 	for (int i = 0; i < 4; i++) {
// 		if (d % 2 == 0 && d + 1 == i) continue;
// 		if (d % 2 == 1 && d - 1 == i) continue;
// 		int ny = y + dy[i];
// 		int nx = x + dx[i];
// 		if (ny < 0 || ny == n || nx < 0 || nx == m) continue;
// 		dfs(ny, nx, i, total + arr[ny][nx], cnt + 1);
// 	}
// }

// void dfs2(int& y, int& x) {
// 	int total, ny, nx;
// 	for (int i = 0; i < 4; i++) {
// 		total = arr[y][x];
// 		for (int j = 0; j < 3; j++) {
// 			ny = y + dy[(i + j) % 4];
// 			nx = x + dx[(i + j) % 4];
// 			if (ny < 0 || ny == n || nx < 0 || nx == m) break;
// 			total += arr[ny][nx];
// 			if (j == 2) res = max(res, total);
// 		}
// 	}
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	cin >> n >> m;
// 	for (int i = 0; i < n; i++)
// 		for (int j = 0; j < m; j++)
// 			cin >> arr[i][j];
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			for (int k = 0; k < 4; k++)
// 				dfs(i, j, k, arr[i][j], 0);
// 			dfs2(i, j);
// 		}
// 	}
// 	cout << res << '\n';
// 	return 0;
// }