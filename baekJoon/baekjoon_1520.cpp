// 내리막길

#include <iostream>
#include <string.h>

using namespace std;

int m, n, res = 0;
int arr[501][501];
int visited[501][501];

class Point {
public:
	int y, x;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int dfs(int y, int x) {
	if (y == m - 1 && x == n - 1) return 1;
	if (visited[y][x] >= 0) return visited[y][x];
	visited[y][x] = 0;
	int ny, nx;
	for (int i = 0; i < 4; i++) {
		ny = y + p[i].y;
		nx = x + p[i].x;
		if (ny >= 0 && ny < m && nx >= 0 && nx < n && arr[y][x] > arr[ny][nx]) {
			visited[y][x] += dfs(ny, nx);
		}
	}
	return visited[y][x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	memset(visited, -1, sizeof(visited));
	dfs(0, 0);
	cout << visited[0][0] << '\n';
	return 0;
}