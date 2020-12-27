// 빵집

#include <iostream>

using namespace std;

int r, c;
char arr[10001][501];
bool visited[10001][501] = { {false,}, };
int dy[3] = { -1, 0, 1 };
int dx[3] = { 1, 1, 1 };

int dfs(int y, int x) {
	if (x == c - 1) return 1;
	int ny, nx;
	for (int i = 0; i < 3; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || ny == r || visited[ny][nx]) continue;
		if (arr[ny][nx] == 'x') continue;
		visited[ny][nx] = true;
		if (dfs(ny, nx)) return 1;
	}
	return 0;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int res = 0;
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		cin >> arr[i];
	for (int i = 0; i < r; i++)
		res += dfs(i, 0);
	cout << res << '\n';
	return 0;
}