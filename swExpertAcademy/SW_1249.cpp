// D4 : 보급로

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <string.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int test_case, n;
int arr[101][101];
int cost[101][101];
bool visited[101][101];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int bfs() {
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push(make_pair(0, make_pair(0, 0)));
	visited[0][0] = true;
	int y, x, ny, nx, c, min_val = INT_MAX;
	while (!pq.empty()) {
		y = pq.top().second.first;
		x = pq.top().second.second;
		c = -pq.top().first;
		pq.pop();
		if (cost[y][x] < c) continue;
		if (y == n - 1 && x == n - 1) continue;
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == n || nx < 0 || nx == n)continue;
			if (c + arr[ny][nx] < cost[ny][nx]) {
				cost[ny][nx] = c + arr[ny][nx];
				visited[ny][nx] = true;
				pq.push(make_pair(-cost[ny][nx], make_pair(ny, nx)));
				if (ny == n - 1 && nx == n - 1)
					min_val = min(min_val, cost[ny][nx]);
			}
		}
	}
	return min_val;
}

void init() {
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cost[i][j] = INT_MAX;
	cost[0][0] = 0;
}

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		scanf(" %d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf(" %1d", &arr[i][j]);
		init();
		printf("#%d %d\n", tc, bfs());
	}
	return 0;
}