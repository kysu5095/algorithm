// 미로 탈출하기

#include <iostream>
#include <queue>

using namespace std;

int n, m, res = 0;
char arr[502][502];
int isRight[502][502] = { {-1,}, };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int get_direction(int& y, int& x) {
	if (arr[y][x] == 'U')      return 3;
	else if (arr[y][x] == 'R') return 0;
	else if (arr[y][x] == 'D') return 2;
	else if (arr[y][x] == 'L') return 1;
}

int dfs(int y, int x) {
	if (y < 0 || y == n || x < 0 || x == m) return 1;
	if (isRight[y][x] != -1) return isRight[y][x];
	isRight[y][x] = 0;
	int idx = get_direction(y, x);
	int ny = y + dy[idx];
	int nx = x + dx[idx];
	return isRight[y][x] = dfs(ny, nx);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < m; j++)
			isRight[i][j] = -1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			res += dfs(i, j);
		}
	}
	cout << res << '\n';
	return 0;
}