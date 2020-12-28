// 피아의 아틀리에 ~신비한 대회의 연금술사~

#include <iostream>
#include <algorithm>

using namespace std;

int n, res = 0;
class Arr {
public:
	int num = 0;
	char color = 'W';
};
Arr arr[5][5];
Arr material[10][4][4];
Arr tmp[4][4];
int sequence1[10];
int sequence2[10];
int sequence3[10];
bool visited[10] = { false, };

void initialize() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			arr[i][j].num = 0;
			arr[i][j].color = 'W';
		}
	}
}

void right_0(int& num) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			tmp[i][j].num = material[num][i][j].num;
			tmp[i][j].color = material[num][i][j].color;
		}
	}
}

void right_90(int& num) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			tmp[i][j].num = material[num][3 - j][i].num;
			tmp[i][j].color = material[num][3 - j][i].color;
		}
	}
}

void right_180(int& num) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			tmp[i][j].num = material[num][3 - i][3 - j].num;
			tmp[i][j].color = material[num][3 - i][3 - j].color;
		}
	}
}

void right_270(int& num) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			tmp[i][j].num = material[num][j][3 - i].num;
			tmp[i][j].color = material[num][j][3 - i].color;
		}
	}
}

// 재료 회전 순서 구하기 (0도, 90도 180도 270도)
void dfs3(int cnt) {
	if (cnt == 3) {
		int num, coor, ro, y, x;
		int red = 0, blue = 0, green = 0, yellow = 0, total = 0;
		for (int i = 0; i < 3; i++) {
			num  = sequence1[i];
			coor = sequence2[i];
			ro   = sequence3[i];
			y    = 0;
			x    = 0;

			if (coor == 1) x++;
			else if (coor == 2) y++;
			else if (coor == 3) x++, y++;

			if (ro == 0) right_0(num);
			else if (ro == 1) right_90(num);
			else if (ro == 2)right_180(num);
			else right_270(num);

			for (int a = y, c = 0; a < y + 4; a++, c++) {
				for (int b = x, d = 0; b < x + 4; b++, d++) {
					if (tmp[c][d].color != 'W') arr[a][b].color = tmp[c][d].color;
					arr[a][b].num += tmp[c][d].num;
					if (arr[a][b].num < 0) arr[a][b].num = 0;
					else if (arr[a][b].num > 9) arr[a][b].num = 9;
				}
			}
		}

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (arr[i][j].color == 'R') red += arr[i][j].num;
				else if (arr[i][j].color == 'B') blue += arr[i][j].num;
				else if (arr[i][j].color == 'G') green += arr[i][j].num;
				else if (arr[i][j].color == 'Y') yellow += arr[i][j].num;
			}
		}
		total = (7 * red) + (5 * blue) + (3 * green) + (2 * yellow);
		res = max(res, total);
		initialize();
		return;
	}
	for (int i = 0; i < 4; i++) {
		sequence3[cnt] = i;
		dfs3(cnt + 1);
	}
}

// 재료 넣을 처음 좌표 구하기 (0, 0) || (0, 1) || (1, 0) || (1, 1)
void dfs2(int cnt) {
	if (cnt == 3) {
		dfs3(0);
		return;
	}
	for (int i = 0; i < 4; i++) {
		sequence2[cnt] = i;
		dfs2(cnt + 1);
	}
}

// 재료 넣을 순서 정하기
void dfs1(int cnt) {
	if (cnt == 3) {
		dfs2(0);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			sequence1[cnt] = i;
			dfs1(cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				cin >> material[i][j][k].num;
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				cin >> material[i][j][k].color;
	}
    
	dfs1(0);
	cout << res << '\n';
	return 0;
}