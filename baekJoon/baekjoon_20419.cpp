// 화살표 미로 (Easy)

#include <stdio.h>
#include <queue>

using namespace std;

int r, c, k;
char arr[51][51];
bool visited[51][51][2][2];
int dy[4] = { 0, 1, 0, -1 }; // R,D,L,U
int dx[4] = { 1, 0, -1, 0 };

struct Point {
	int y, x, L, R;
};

bool bfs() {
	queue<Point> q;
	q.push({ 0, 0, k, k });
	visited[0][0][k][k] = true;
	int y, x, ny, nx, L, R, d;
	while (!q.empty()) {
		y = q.front().y;
		x = q.front().x;
		L = q.front().L;
		R = q.front().R;
		q.pop();
		if (y == r - 1 && x == c - 1) return true;

		if (arr[y][x] == 'R') d = 0;
		else if (arr[y][x] == 'D') d = 1;
		else if (arr[y][x] == 'L') d = 2;
		else d = 3;

		ny = y + dy[d];
		nx = x + dx[d];
		if (!(ny < 0 || ny == r || nx < 0 || nx == c || visited[ny][nx][L][R])) {
			q.push({ ny, nx, L, R });
			visited[ny][nx][L][R] = true;
		}

		if (L) {
			ny = y + dy[(d + 3) % 4];
			nx = x + dx[(d + 3) % 4];
			if (!(ny < 0 || ny == r || nx < 0 || nx == c || visited[ny][nx][L - 1][R])) {
				q.push({ ny, nx, L - 1, R });
				visited[ny][nx][L - 1][R] = true;
			}
		}

		if (R) {
			ny = y + dy[(d + 1) % 4];
			nx = x + dx[(d + 1) % 4];
			if (!(ny < 0 || ny == r || nx < 0 || nx == c || visited[ny][nx][L][R - 1])) {
				q.push({ ny, nx, L, R - 1 });
				visited[ny][nx][L][R - 1] = true;
			}
		}
	}
	return false;
}

int main() {
	scanf("%d %d %d", &r, &c, &k);
	for (int i = 0; i < r; i++) scanf("%s", arr[i]);
	if (bfs())printf("Yes\n");
	else printf("No\n");
	return 0;
}