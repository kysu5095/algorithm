// 마법사 상어와 파이어스톰

#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

int n, q, l;
int res_cnt = 0, res_size = 0;
int arr[1 << 6][1 << 6], tmp[1 << 6][1 << 6];
bool visited[1 << 6][1 << 6];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

void rotate(int& y, int& x) {
	int len = 1 << l;
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
			tmp[i][j] = arr[y + i][x + j];
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
			arr[y + i][x + j] = tmp[len - 1 - j][i];
}

void melt() {
	memset(visited, false, sizeof(visited));
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			int cnt = 0;
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == n || arr[ny][nx] <= 0) continue;
				cnt++;
			}
			if (cnt < 3) visited[y][x] = true;
		}
	}
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			if (visited[y][x])
				arr[y][x]--;
}

void firestorm() {
	for (int i = 0; i < n; i += (1 << l)) 
		for (int j = 0; j < n; j += (1 << l)) 
			rotate(i, j); 
	melt();
}

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visited[y][x] = true;
	res_cnt += arr[y][x];
	int ny, nx, cnt = 1;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == n || nx < 0 || nx == n) continue;
			if (visited[ny][nx] || arr[ny][nx] <= 0) continue;
			q.push(make_pair(ny, nx));
			visited[ny][nx] = true;
			cnt++;
			res_cnt += arr[ny][nx];
		}
	}
	res_size = max(res_size, cnt);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	n = 1 << n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	for (int i = 0; i < q; i++) {
		cin >> l;
		firestorm();
	}
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			if (arr[i][j] > 0 && !visited[i][j]) 
				bfs(i, j);

	cout << res_cnt << " " << res_size << '\n';
	return 0;
}