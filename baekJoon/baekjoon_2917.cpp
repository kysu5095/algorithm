// 늑대 사냥꾼

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

int n, m, sy, sx, res;
char arr[501][501];
bool visited[501][501];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
vector<pair<int, int>> v;

bool promising(int& y, int& x, int& dis) {
	for (auto idx : v) 
		if (abs(y - idx.first) + abs(x - idx.second) < dis)
			return false;

	return true;
}

bool bfs(int& dis) {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push(make_pair(sy, sx));
	visited[sy][sx] = true;
	int y, x, ny, nx;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == n || nx < 0 || nx == m || visited[ny][nx]) continue;
			if (arr[ny][nx] == 'J') return true;
			if (!promising(ny, nx, dis)) continue;
			q.push(make_pair(ny, nx));
			visited[ny][nx] = true;
		}
	}
	return false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int left = INT_MAX;
	int right = 0;
	int mid;
	freopen("vuk.in.3", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'V') {
				sy = i;
				sx = j;
			}
			else if (arr[i][j] == '+') 
				v.push_back(make_pair(i, j));
		}
	}
	for (auto idx : v) {
		left = min(left, abs(sy - idx.first) + abs(sx - idx.second));
		right = max(right, abs(sy - idx.first) + abs(sx - idx.second));
	}
	while (left <= right) {
		mid = (left + right) >> 1;
		if (bfs(mid)) {
			left = mid + 1;
			res = mid;
		}
		else right = mid - 1;
	}
	cout << res << '\n';
	fclose(stdin);
	return 0;
}