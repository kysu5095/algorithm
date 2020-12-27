// 정상 회담

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int n, m, res = INT_MAX;
char arr[51][51];
int visited[2501][51][51] = { { {0,}, }, };
int dy[8] = { -2, 2, -2, 2, -1, 1, -1, 1 };
int dx[8] = { 1, 1, -1, -1, 2, 2, -2, -2 };
vector<pair<int, pair<int, int>>> v;

void bfs(queue<pair<int, int>>& q, int& idx) {
	int y, x, ny, nx, len, cnt = 1;
	while (!q.empty()) {
		len = q.size();
		while (len--) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			for (int i = 0; i < 8; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				if (visited[idx][ny][nx] != -1 && visited[idx][ny][nx] < cnt) continue;
				visited[idx][ny][nx] = cnt;
				q.push(make_pair(ny, nx));
			}
		}
		cnt++;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int y, x, num;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < m; j++)
			if (arr[i][j] != '.')
				v.push_back(make_pair((arr[i][j] - '0'), make_pair(i, j)));
	}
	memset(visited, -1, sizeof(visited));
	queue<pair<int, int>> q;
	for (int i = 0; i < v.size(); i++) {
		y = v[i].second.first;
		x = v[i].second.second;
		q.push(make_pair(y, x));
		visited[i][y][x] = 0;
		bfs(q, i);
	}
	int sum, val, rest;
	bool flag;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum = 0;
			flag = true;
			for (int k = 0; k < v.size(); k++) {
				val = visited[k][i][j];
				if (val == -1) {
					flag = false;
					break;
				}
				num = v[k].first;
				rest = val % num;
				val /= num;
				if (rest > 0) val++;
				sum += val;
			}
			if (flag) res = min(res, sum);
		}
	}
	if (res == INT_MAX) res = -1;
	cout << res << '\n';
	return 0;
}