// 집배원 한상덕

#include <iostream>
#include <queue>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

int n, sy, sx, k = 0;
char map[51][51];
int arr[51][51];
int height[2501] = { 0, };
bool visited[51][51];
int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

bool isRight(int& left, int& right) {
	if (arr[sy][sx] < left || arr[sy][sx] > right) return false;

	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push(make_pair(sy, sx));
	visited[sy][sx] = true;
	int y, x, ny, nx, cnt = 0;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == n || nx < 0 || nx == n || visited[ny][nx]) continue;
			if (arr[ny][nx] < left || arr[ny][nx] > right) continue;
			if (map[ny][nx] == 'K') cnt++;
			if (cnt == k) return true;
			q.push(make_pair(ny, nx));
			visited[ny][nx] = true;
		}
	}
	return false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int idx = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'K') k++;
			else if (map[i][j] == 'P') {
				sy = i;
				sx = j;
			}
		}
	}
	int min_v = 1000001, max_v = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			height[idx++] = arr[i][j];
		}
	}
	sort(height, height + idx);
	idx = unique(height, height + idx) - height;
	int left = 0;
	int right = 0;
	int res = height[idx - 1] - height[0];
	while (left <= right && right <= idx) {
		if (isRight(height[left], height[right])) res = min(res, (height[right] - height[left++]));
		else right++;
	}
	cout << res << '\n';
	return 0;
}