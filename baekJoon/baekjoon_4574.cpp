// 스도미노쿠

#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int n, tc = 1;
bool end_game;
int sdoku[9][9];
bool small_sdoku[10][10], width_sdoku[10][10], height_sdoku[10][10], used[10][10];

int get_small_sdoku(int& row, int& col) {
	if (row <= 2 && col <= 2)						   return 0;
	if (row <= 2 && col >  2  && col <= 5)			   return 1;
	if (row <= 2 && col >  5  && col <= 8)			   return 2;
	if (row >  2 && row <= 5  && col <= 2)			   return 3;
	if (row >  2 && row <= 5  && col >  2 && col <= 5) return 4;
	if (row >  2 && row <= 5  && col >  5 && col <= 8) return 5;
	if (row >  5 && col <= 2)						   return 6;
	if (row >  5 && col >  2  && col <= 5)			   return 7;
	if (row >  5 && col >  5  && col <= 8)			   return 8;
}

bool is_right(int& idx, int& row, int& col, int& val) {
	if (small_sdoku[idx][val]) return true;
	if (width_sdoku[row][val]) return true;
	if (height_sdoku[col][val]) return true;
	return false;
}

void set_val(int& row, int& col, bool flag, int& idx1, int& idx2, int val1, int val2, bool flag_val) {
	small_sdoku[idx1][val1] = flag_val;
	width_sdoku[row][val1] = flag_val;
	height_sdoku[col][val1] = flag_val;
	small_sdoku[idx2][val2] = flag_val;
	if (flag) {
		width_sdoku[row][val2] = flag_val;
		height_sdoku[col + 1][val2] = flag_val;
	}
	else {
		width_sdoku[row + 1][val2] = flag_val;
		height_sdoku[col][val2] = flag_val;
	}
	if (flag_val) {
		sdoku[row][col] = val1;
		if (flag) sdoku[row][col + 1] = val2;
		else sdoku[row + 1][col] = val2;
		used[val1][val2] = true;
		used[val2][val1] = true;
	}
	else {
		sdoku[row][col] = 0;
		if (flag) sdoku[row][col + 1] = 0;
		else sdoku[row + 1][col] = 0;
		used[val1][val2] = false;
		used[val2][val1] = false;
	}
}

bool is_used(int& val1, int& val2) {
	if (used[val1][val2] || used[val2][val1]) return true;
	return false;
}

void dfs(int row, int col) {
	if (end_game) return;
	if (row == 9) {
		cout << "Puzzle " << tc++ << '\n';
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << sdoku[i][j];
			cout << '\n';
		}
		end_game = true;
		return;
	}
	if (col >= 9) {	dfs(row + 1, 0); return; }
	if (sdoku[row][col]) { dfs(row, col + 1); return; }

	int idx1 = get_small_sdoku(row, col);
	int ny, nx, idx2;
	for (int i = 1; i <= 8; i++) {
		ny = row;
		nx = col + 1;
		if (nx < 9 && !sdoku[ny][nx]) {
			idx2 = get_small_sdoku(ny, nx);
			for (int j = i + 1; j <= 9; j++) {
				if (is_used(i, j)) continue;
				if (!is_right(idx1, row, col, i) && !is_right(idx2, ny, nx, j)) {
					set_val(row, col, true, idx1, idx2, i, j, true);
					dfs(row, col + 2);
					set_val(row, col, true, idx1, idx2, i, j, false);
				}
				if (!is_right(idx1, row, col, j) && !is_right(idx2, ny, nx, i)) {
					set_val(row, col, true, idx1, idx2, j, i, true);
					dfs(row, col + 2);
					set_val(row, col, true, idx1, idx2, j, i, false);
				}
			}
		}

		ny = row + 1;
		nx = col;
		if (ny < 9 && !sdoku[ny][nx]) {
			idx2 = get_small_sdoku(ny, nx);
			for (int j = i + 1; j <= 9; j++) {
				if (is_used(i, j)) continue;
				if (!is_right(idx1, row, col, i) && !is_right(idx2, ny, nx, j)) {
					set_val(row, col, false, idx1, idx2, i, j, true);
					dfs(row, col + 1);
					set_val(row, col, false, idx1, idx2, i, j, false);
				}
				if (!is_right(idx1, row, col, j) && !is_right(idx2, ny, nx, i)) {
					set_val(row, col, false, idx1, idx2, j, i, true);
					dfs(row, col + 1);
					set_val(row, col, false, idx1, idx2, j, i, false);
				}
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int input1, input2, row1, col1, row2, col2, idx;
	string input[2];
	while (true) {
		cin >> n;
		if (!n) break;
		end_game = false;
		memset(sdoku, 0, sizeof(sdoku));
		memset(small_sdoku, false, sizeof(small_sdoku));
		memset(width_sdoku, false, sizeof(width_sdoku));
		memset(height_sdoku, false, sizeof(height_sdoku));
		memset(used, false, sizeof(used));
		for (int i = 0; i < n; i++) {
			cin >> input1 >> input[0] >> input2 >> input[1];
			row1 = input[0][0] - 'A', col1 = (input[0][1] - '0') - 1;
			row2 = input[1][0] - 'A', col2 = (input[1][1] - '0') - 1;
			sdoku[row1][col1] = input1;
			sdoku[row2][col2] = input2;
			idx = get_small_sdoku(row1, col1);
			small_sdoku[idx][input1]   = true;
			idx = get_small_sdoku(row2, col2);
			small_sdoku[idx][input2]   = true;
			width_sdoku[row1][input1]  = true;
			height_sdoku[col1][input1] = true;
			width_sdoku[row2][input2]  = true;
			height_sdoku[col2][input2] = true;
			used[input1][input2] = true;
			used[input2][input1] = true;
		}
		for (int i = 1; i <= 9; i++) {
			cin >> input[0];
			row1 = input[0][0] - 'A';
			col1 = (input[0][1] - '0') - 1;
			sdoku[row1][col1] = i;
			idx = get_small_sdoku(row1, col1);
			small_sdoku[idx][i]   = true;
			width_sdoku[row1][i]  = true;
			height_sdoku[col1][i] = true;
		}
		dfs(0, 0);
	}
	return 0;
}