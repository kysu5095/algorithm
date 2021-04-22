// 스타트 택시

#include <stdio.h>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int n, M, k;
int arr[21][21];
bool visited[21][21];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
map<int, pair<int, int>> m;

bool find_customer(int& y, int& x) {
	memset(visited, false, sizeof(visited));
	vector<pair<int, int>> v;
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visited[y][x] = true;
	int ny, nx, len;

	while (!q.empty()) {
		len = q.size();
		while (len--) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			if (arr[y][x] >= 2)	v.push_back(make_pair(y, x));
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == n || visited[ny][nx] || arr[ny][nx] == 1) continue;
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
			}
		}
		if (v.size()) {
			sort(v.begin(), v.end());
			y = v[0].first;
			x = v[0].second;
			return true;
		}
		if (k == 0) return false;
		k--;
	}
	return false;
}

bool find_departure(int& y, int& x) {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visited[y][x] = true;
	int key = arr[y][x];
	arr[y][x] = 0;
	int ny, nx, len, fuel = 0, fy = m[key].first, fx = m[key].second;

	while (!q.empty()) {
		len = q.size();
		while (len--) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			if (y == fy && x == fx) {
				k += fuel * 2;
				m.erase(key);
				return true;
			}
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == n || visited[ny][nx] || arr[ny][nx] == 1) continue;
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
			}
		}
		if (k == 0) return false;
		k--;
		fuel++;
	}
	return false;
}

int move(int y, int x) {
	while (m.size()) {
		if (!find_customer(y, x)) return -1;
		if (!find_departure(y, x)) return -1;
	}
	return k;
}

int main() {
	scanf("%d %d %d", &n, &M, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf(" %d", &arr[i][j]);
	int sy, sx;
	scanf(" %d %d", &sy, &sx);
	for (int i = 2; i < M + 2; i++) {
		int y, x, yy, xx;
		scanf(" %d %d %d %d", &y, &x, &yy, &xx);
		arr[y - 1][x - 1] = i;
		m[i] = make_pair(yy - 1, xx - 1);
	}
	printf("%d\n", move(sy - 1, sx - 1));
	return 0;
}