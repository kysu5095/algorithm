// 상어 초등학교

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;

int n, ret = 0;
int arr[21][21];
int love[401][4];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

struct Point {
	int y, x, empty_cnt, love_cnt;
	bool operator < (const Point& p) const {
		if (this->love_cnt > p.love_cnt) return true;
		else if (this->love_cnt == p.love_cnt) {
			if (this->empty_cnt > p.empty_cnt) return true;
			else if (this->empty_cnt == p.empty_cnt) {
				return make_pair(this->y, this->x) < make_pair(p.y, p.x);
			}
			else return false;
		}
		else return false;
	}
};

void find_seat(int num) {
	vector<Point> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j]) continue;
			int empty_cnt = 0, love_cnt = 0;
			for (int k = 0; k < 4; k++) {
				int y = i + dy[k];
				int x = j + dx[k];
				if (y < 0 || y == n || x < 0 || x == n) continue;
				if (arr[y][x]) {
					bool is_find = false;
					for (int l = 0; l < 4; l++)
						if (love[num][l] == arr[y][x]) is_find = true;
					if (is_find) love_cnt++;
				}
				else empty_cnt++;
			}
			v.push_back({ i, j, empty_cnt, love_cnt });
		}
	}
	sort(v.begin(), v.end());
	arr[v[0].y][v[0].x] = num;
}

void get_point() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num = arr[i][j];
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int y = i + dy[k];
				int x = j + dx[k];
				if (y < 0 || y == n || x < 0 || x == n) continue;
				for (int l = 0; l < 4; l++)
					if (love[num][l] == arr[y][x]) cnt++;
			}
			if (cnt == 0) continue;
			ret += pow(10, cnt - 1);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n * n; i++) {
		int num;
		scanf(" %d", &num);
		for (int j = 0; j < 4; j++)
			scanf(" %d", &love[num][j]);
		find_seat(num);
	}
	get_point();
	printf("%d\n", ret);
	return 0;
}