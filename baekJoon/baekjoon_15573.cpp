// 채굴

#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

int n, m, k;
int arr[1001][1001];
bool visited[1001][1001] = { {false,}, };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int promising(int& mid) {
	int cnt = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		if (arr[i][0] <= mid) {
			q.push(make_pair(i, 0));
			visited[i][0] = true;
			cnt++;
		}
		if (arr[i][m - 1] <= mid) {
			q.push(make_pair(i, m - 1));
			visited[i][m - 1] = true;
			cnt++;
		}
	}
	for (int i = 1; i < m - 1; i++) {
		if (arr[0][i] <= mid) {
			q.push(make_pair(0, i));
			visited[0][i] = true;
			cnt++;
		}
	}
	int y, x, ny, nx;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == n || nx < 0 || nx == m) continue;
			if (visited[ny][nx] || arr[ny][nx] > mid) continue;
			q.push(make_pair(ny, nx));
			visited[ny][nx] = true;
			cnt++;
		}
	}
	return cnt;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int start = 1000000, last = 0, mid;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			start = min(start, arr[i][j]);
			last = max(last, arr[i][j]);
		}
	while (start < last) {
		memset(visited, false, sizeof(visited));
		mid = (start + last) >> 1;
		if (promising(mid) < k) start = mid + 1;
		else last = mid;
	}
	cout << start << '\n';
	return 0;
}