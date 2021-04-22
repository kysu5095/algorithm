// 상남자

#include <stdio.h>
#include <queue>

using namespace std;

int n, m, cnt = 1;
char arr[1001][1001];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
struct Point {
	int y, x, L, R;
};

void check_left(int y, int x, int L, int R, queue<Point>& q) {
	x += dx[1];
	if (x < 0 || arr[y][x] == '1') return;
	L--;
	q.push({ y, x, L, R });
	arr[y][x] = '1';
	cnt++;
}

void check_right(int y, int x, int L, int R, queue<Point>& q) {
	x += dx[0];
	if (x == m || arr[y][x] == '1') return;
	R--;
	q.push({ y, x, L, R });
	arr[y][x] = '1';
	cnt++;
}

void bfs(int y, int x, int L, int R) {
	int ny, nx, nL, nR, len;
	queue<Point> q;
	q.push({ y, x, L, R });
	arr[y][x] = '1';
	while (!q.empty()) {
		len = q.size();
		while (len--) {
			y = q.front().y;
			x = q.front().x;
			L = q.front().L;
			R = q.front().R;
			q.pop();

			if (L) check_left(y, x, L, R, q);
			if (R) check_right(y, x, L, R, q);

			ny = y;
			while (true) {
				ny += dy[3];
				if (ny < 0 || arr[ny][x] == '1') break;
				q.push({ ny, x, L, R });
				arr[ny][x] = '1';
				cnt++;

				if (L) check_left(ny, x, L, R, q);
				if (R) check_right(ny, x, L, R, q);
			}
			ny = y;
			while (true) {
				ny += dy[2];
				if (ny == n || arr[ny][x] == '1') break;
				q.push({ ny, x, L, R });
				arr[ny][x] = '1';
				cnt++;

				if (L) check_left(ny, x, L, R, q);
				if (R) check_right(ny, x, L, R, q);
			}
		}
	}
}

int main() {
	int y, x, L, R;
	scanf("%d %d", &n, &m);
	scanf(" %d %d", &L, &R);
	for (int i = 0; i < n; i++) {
		scanf("%s", arr[i]);
		for (int j = 0; j < m; j++)
			if (arr[i][j] == '2') y = i, x = j;
	}
	bfs(y, x, L, R);
	printf("%d\n", cnt);
	return 0;
}