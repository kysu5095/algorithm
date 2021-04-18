// 낚시왕

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int r, c, M, ret = 0;
int arr[101][101], tmp[101][101];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
struct Point {
	bool die;
	int y, x, s, d, z;
};
vector<Point> v;

void catch_shark(int j) {
	for (int i = 0; i < r; i++) {
		if (arr[i][j]) {
			v[arr[i][j] - 1].die = true;
			ret += v[arr[i][j] - 1].z;
			arr[i][j] = 0;
			break;
		}
	}
}

void move_shark() {
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i < M; i++) {
		if (v[i].die) continue;
		int& y = v[i].y;
		int& x = v[i].x;
		int& d = v[i].d;
		int s = v[i].s;
		arr[y][x] = 0;

		for (int ss = 0; ss < s; ss++) {
			y += dy[d];
			x += dx[d];
			if (y < 0 || y == r || x < 0 || x == c) {
				if (d % 2 == 0) d++;
				else d--;
				y += dy[d] * 2;
				x += dx[d] * 2;
			}
		}
		if (tmp[y][x]) v[i].die = true;
		else tmp[y][x] = i + 1;
	}

	for (int i = 0; i < M; i++) {
		if (v[i].die) continue;
		int y = v[i].y;
		int x = v[i].x;
		arr[y][x] = i + 1;
	}
}

int main() {
	scanf("%d %d %d", &r, &c, &M);
	for (int i = 0; i < M; i++) {
		int y, x, s, d, z;
		scanf(" %d %d %d %d %d", &y, &x, &s, &d, &z);
		if (d <= 2) v.push_back({ false, y - 1, x - 1, s % (2 * (r - 1)), d - 1, z });
		else v.push_back({ false, y - 1,x - 1,s % (2 * (c - 1)), d - 1, z });
	}
	sort(v.begin(), v.end(), [](Point& a, Point& b) {
		return a.z > b.z;
	});
	for (int i = 0; i < M; i++) arr[v[i].y][v[i].x] = i + 1;

	for (int j = 0; j < c; j++) {
		catch_shark(j);
		move_shark();
	}
	printf("%d\n", ret);
	return 0;
}