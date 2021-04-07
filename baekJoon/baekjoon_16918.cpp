// 봄버맨

#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int r, c, n;
char arr[201][201];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
queue<pair<int, int>> q;

void make_map() {
	memset(arr, 'O', sizeof(arr));
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		arr[y][x] = '.';
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny == r || nx < 0 || nx == c) continue;
			arr[ny][nx] = '.';
		}
	}
}

int main() {
	scanf("%d %d %d", &r, &c, &n);
	for (int i = 0; i < r; i++) {
		scanf("%s", arr[i]);
		for (int j = 0; j < c; j++) if (arr[i][j] == 'O') q.push(make_pair(i, j));
	}
	if (n % 2 == 0) memset(arr, 'O', sizeof(arr));
	else if ((double)(n + 1) / 4 == ((n + 1) / 4)) make_map();
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) printf("%c", arr[i][j]);
		printf("\n");
	}
	return 0;
}