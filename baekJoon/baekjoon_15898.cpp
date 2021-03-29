// 피아의 아틀리에 ~신비한 대회의 연금술사~

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int n, res = 0;
bool visited[11];
int sequence_1[3];
int sequence_2[3];
int sequence_3[3];

struct MATERIAL {
	int val = 0;
	char ch = 'W';
};
MATERIAL arr[5][5];
MATERIAL material[10][4][4];
MATERIAL rotate_arr[4][4];

void init() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			arr[i][j].ch = 'W';
			arr[i][j].val = 0;
		}
	}
}

void rotate(int& idx, int& angle) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			switch (angle)
			{
			case 0: rotate_arr[i][j] = material[idx][i][j]; break;
			case 1: rotate_arr[i][j] = material[idx][3 - j][i]; break;
			case 2: rotate_arr[i][j] = material[idx][3 - i][3 - j]; break;
			case 3: rotate_arr[i][j] = material[idx][j][3 - i]; break;
			}
		}
	}
}
// 회전
void dfs_3(int cnt) {
	if (cnt == 3) {
		int index, y, x, angle;
		for (int idx = 0; idx < 3; idx++) {
			index = sequence_1[idx];
			switch (sequence_2[idx])
			{
			case 0: y = 0; x = 0; break;
			case 1: y = 0; x = 1; break;
			case 2: y = 1; x = 0; break;
			case 3: y = 1; x = 1; break;
			}
			switch (sequence_3[idx])
			{
			case 0: angle = 0; break;
			case 1: angle = 1; break;
			case 2: angle = 2; break;
			case 3: angle = 3; break;
			}
			rotate(index, angle);
			for (int _y = y, __y = 0; _y < y + 4; _y++, __y++) {
				for (int _x = x, __x = 0; _x < x + 4; _x++, __x++) {
					char ch = rotate_arr[__y][__x].ch;
					int val = rotate_arr[__y][__x].val;
					if (ch != 'W') arr[_y][_x].ch = ch;
					arr[_y][_x].val += val;
					if (arr[_y][_x].val < 0) arr[_y][_x].val = 0;
					else if (arr[_y][_x].val > 9) arr[_y][_x].val = 9;
				}
			}
		}

		int R = 0, B = 0, G = 0, Y = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				switch (arr[i][j].ch)
				{
				case 'W': break;
				case 'R': R += arr[i][j].val; break;
				case 'B': B += arr[i][j].val; break;
				case 'G': G += arr[i][j].val; break;
				case 'Y': Y += arr[i][j].val; break;
				}
			}
		}
		int total = (7 * R) + (5 * B) + (3 * G) + (2 * Y);
		res = max(res, total);
		init();
		return;
	}
	for (int i = 0; i < 4; i++) {
		sequence_3[cnt] = i;
		dfs_3(cnt + 1);
	}
}
// 좌표
void dfs_2(int cnt) {
	if (cnt == 3) {
		dfs_3(0);
		return;
	}
	for (int i = 0; i < 4; i++) {
		sequence_2[cnt] = i;
		dfs_2(cnt + 1);
	}
}
// 순서
void dfs_1(int cnt) {
	if (cnt == 3) {
		dfs_2(0);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			sequence_1[cnt] = i;
			dfs_1(cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int idx = 0; idx < n; idx++) {
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				scanf("%d", &material[idx][i][j].val);
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				scanf(" %c", &material[idx][i][j].ch);
	}
	dfs_1(0);
	printf("%d\n", res);
	return 0;
}