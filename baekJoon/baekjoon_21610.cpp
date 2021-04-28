// 마법사 상어와 비바라기

#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

int n, m;
int arr[51][51], tmp[51][51];
bool visited[51][51];
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
struct CLOUD {
	int y, x;
};
vector<CLOUD> cloud;

void move_cloud(int d, int s) {
	memset(visited, false, sizeof(visited));
	for (int idx = 0; idx < cloud.size(); idx++) {
		int& y = cloud[idx].y;
		int& x = cloud[idx].x;
		y = ((y + n) + (dy[d] * (s % n))) % n;
		x = ((x + n) + (dx[d] * (s % n))) % n;
		arr[y][x]++;
		visited[y][x] = true;
	}
}

void rain() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp[i][j] = arr[i][j];
	for (int idx = 0; idx < cloud.size(); idx++) {
		int y = cloud[idx].y;
		int x = cloud[idx].x;
		for (int i = 1; i < 8; i += 2) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny == n || nx < 0 || nx == n || !tmp[ny][nx]) continue;
			arr[y][x]++;
		}
	}
	cloud.clear();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] < 2 || visited[i][j]) continue;
			arr[i][j] -= 2;
			cloud.push_back({ i, j });
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf(" %d", &arr[i][j]);
	cloud.push_back({ n - 2, 0 });
	cloud.push_back({ n - 2, 1 });
	cloud.push_back({ n - 1, 0 });
	cloud.push_back({ n - 1, 1 });
	while (m--) {
		int d, s;
		scanf(" %d %d", &d, &s);
		move_cloud(d - 1, s);
		rain();
	}
	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ret += arr[i][j];
	printf("%d\n", ret);
	return 0;
}