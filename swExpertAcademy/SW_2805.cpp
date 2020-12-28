// 농작물 수확하기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <string.h>

int arr[51][51];
bool jud[51][51];

class Point {
public:
	int y, x, d;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int bfs(int n) {
	std::queue<Point> q;
	int y = n / 2;
	int x = n / 2;
	int d = 0;
	q.push({ y, x, d });
	jud[y][x] = true;
	int sum = arr[y][x];
	while (!q.empty() && q.front().d < (n / 2)) {
		y = q.front().y;
		x = q.front().x;
		d = q.front().d;
		for (int i = 0; i < 4; i++) {
			int ny = y + p[i].y;
			int nx = x + p[i].x;
			if (ny >= 0 && ny < n && nx >= 0 && nx < n && !jud[ny][nx]) {
				q.push({ ny, nx, d + 1 });
				jud[ny][nx] = true;
				sum += arr[ny][nx];
			}
		}
		q.pop();
	}
	return sum;
}

int main() {
	//freopen("input.txt", "r", stdin);
	int test_case, n;
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		memset(jud, false, sizeof(jud));
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%1d", &arr[i][j]);
		int sum = bfs(n);
		printf("#%d %d\n", tc, sum);
	}
	return 0;
}