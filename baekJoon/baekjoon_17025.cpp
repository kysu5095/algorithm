// Icy Perimeter

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

int n, cnt = 1;
int res_total = 0, res_perimeter = 10000;
int arr[1005][1005];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
queue<pair<int, int>> q;

void bfs(int y, int x) {
	q.push(make_pair(y, x));
	arr[y][x] = cnt;
	int ny, nx, total = 1, perimeter = 0;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (arr[ny][nx] == 0) {
				arr[ny][nx] = cnt;
				q.push(make_pair(ny, nx));
				total++;
			}
			else if (arr[ny][nx] == -1) 
				perimeter++;
		}
	}
	if (total > res_total || (total == res_total && perimeter < res_perimeter)) {
		res_total = total;
		res_perimeter = perimeter;
	}
}

int main() {
	memset(arr, -1, sizeof(arr));
	char input;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %1c", &input);
			if (input == '#')
				arr[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 0) {
				bfs(i, j);
				cnt++;
			}
		}
	}
	printf("%d %d\n", res_total, res_perimeter);
	return 0;
}