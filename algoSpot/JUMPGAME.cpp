// 외발 뛰기

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int test_case, n;
int arr[101][101];
bool visited[101][101];
int dy[2] = { 0, 1 };
int dx[2] = { 1, 0 };

bool bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	visited[0][0] = true;
	int y, x, ny, nx, val;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		val = arr[y][x];
		q.pop();
		for (int i = 0; i < 2; i++) {
			ny = y + (dy[i] * val);
			nx = x + (dx[i] * val);
			if (ny >= n || nx >= n || visited[ny][nx]) continue;
			if (ny == n - 1 && nx == n - 1) return true;
			q.push(make_pair(ny, nx));
			visited[ny][nx] = true;
		}
	}
	return false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> test_case;
	while (test_case--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];
		memset(visited, false, sizeof(visited));
		if (bfs()) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}