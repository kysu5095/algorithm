// 배열에서 이동

#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int n, low_val = 201, max_val = -1;
int arr[101][101];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

bool bfs(int limit) {
	for (int l = low_val; l <= max_val - limit; l++) {
		if (arr[0][0] < l || arr[0][0] > l + limit) continue;
		queue<pair<int, int>> q;
		q.push(make_pair(0, 0));
		bool visited[101][101] = { { false,}, };
		visited[0][0] = true;
		int y, x, ny, nx;
		while (!q.empty()) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			if (y == n - 1 && x == n - 1) return true;

			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == n) continue;
				if (visited[ny][nx]) continue;
				if (arr[ny][nx] < l || arr[ny][nx] > l + limit) continue;
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
			}
		}
	}
	return false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			low_val = min(low_val, arr[i][j]);
			max_val = max(max_val, arr[i][j]);
		}
	int low = 0;
	int high = max_val - low_val;
	int res;
	while (low <= high) {
		int mid = (low + high) >> 1;
		if (bfs(mid)) {
			res = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	cout << res << '\n';
	return 0;
}