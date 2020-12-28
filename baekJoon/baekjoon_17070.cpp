// 파이프 옮기기 1
// 7:25

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int n, res;
int arr[17][17];

class Point {
public:
	int y, x;
};
Point p[4] = { {0, 1}, {1, 1}, {1, 0} };

void dfs(int y, int x, int d) {
	if (y == n - 1 && x == n - 1) {
		res++;
		return;
	}
	int ny, nx;
	for (int i = 0; i < 3; i++) {
		if (d == 0 && i == 2) continue;
		if (d == 2 && i == 0) continue;
		ny = y + p[i].y;
		nx = x + p[i].x;
		if (ny >= 0 && ny < n && nx >= 0 && nx < n && !arr[ny][nx]) {
			if (i != 1) 
				dfs(ny, nx, i);
			else {
				if (!arr[ny - 1][nx] && !arr[ny][nx - 1])
					dfs(ny, nx, i);
			}
		}
	}
}

int main() {
	res = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf(" %d", &arr[i][j]);
	dfs(0, 1, 0);
	printf("%d\n", res);
	return 0;
}

// #include <iostream>
// #include <queue>

// using namespace std;

// int n, res = 0;
// bool arr[17][17];
// int dy[3] = { 0, 1, 1 };
// int dx[3] = { 1, 0, 1 };

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	cin >> n;
// 	for (int i = 0; i < n; i++)
// 		for (int j = 0; j < n; j++)
// 			cin >> arr[i][j];
// 	int y, x, ny, nx, d, cnt;
// 	queue<pair<int, pair<int, int>>> q;
// 	q.push(make_pair(0, make_pair(0, 1)));
// 	while (!q.empty()) {
// 		y = q.front().second.first;
// 		x = q.front().second.second;
// 		d = q.front().first;
// 		cnt = 0;
// 		q.pop();
// 		if (y == n - 1 && x == n - 1) {
// 			res++;
// 			continue;
// 		}
// 		for (int i = 0; i < 3; i++) {
// 			ny = y + dy[i];
// 			nx = x + dx[i];
// 			if (ny < 0 || ny == n || nx < 0 || nx == n || arr[ny][nx]) continue;
// 			cnt++;
// 			if (d == 0 && i == 1) continue;
// 			if (d == 1 && i == 0) continue;
// 			if (i == 2 && cnt != 3) continue;
// 			q.push(make_pair(i, make_pair(ny, nx)));
// 		}
// 	}
// 	cout << res << '\n';
// 	return 0;
// }