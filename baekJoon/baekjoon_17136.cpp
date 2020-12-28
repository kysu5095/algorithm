// 색종이 붙이기
// 12:45

#include <iostream>
#include <limits.h>

using namespace std;

int p_cnt = 0, res = INT_MAX;
int arr[10][10];
int p_arr[10][10] = { {0,}, };
int paper[6] = { 0, 5, 5, 5, 5, 5 };

void print() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

bool is_put(int y, int x, int k) {
	for (int i = y; i <= y + k; i++) {
		for (int j = x; j <= x + k; j++) {
			if (!arr[i][j]) return false;
		}
	}
	return true;
}

void check_paper() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i][j]) {
				for (int k = 4; k >= 0; k--) {
					if (i + k < 10 && j + k < 10 && is_put(i, j, k)) {
						arr[i][j] = k + 1;
						p_arr[i][j] = k + 1;
						break;
					}
				}
			}
		}
	}
}

void dfs(int y, int x, int cnt, int del) {
	if (cnt == res) return;
	if (del == p_cnt) {
		res = cnt;
		return;
	}
	int i = y;
	int j = x;
	for (i; i < 10; i++) {
		for (j; j < 10; j++) {
			if (arr[i][j]) {
				for (int k = arr[i][j]; k >= 1; k--) {
					if (paper[k] && is_put(i, j, k - 1)) {
						paper[k]--;
						for (int r = i; r < i + k; r++)
							for (int c = j; c < j + k; c++)
								arr[r][c] = 0;
						dfs(i, j + k - 1, cnt + 1, del + (k * k));
						paper[k]++;
						for (int r = i; r < i + k; r++)
							for (int c = j; c < j + k; c++)
								arr[r][c] = p_arr[r][c];
					}
				}
				return;
			}
		}
		j = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) p_cnt++;
		}
	}
	check_paper();
	dfs(0, 0, 0, 0);
	
	if (res == INT_MAX) cout << "-1\n";
	else cout << res << '\n';
	return 0;
}

// #include <iostream>
// #include <algorithm>
// #include <limits.h>

// using namespace std;

// int total = 0, ret = INT_MAX;
// int arr[10][10];
// bool map[10][10];
// int color[6] = { 0, 5, 5, 5, 5, 5 };

// int what_kind_block(int& y, int& x) {
// 	bool flag;
// 	int cnt = 5;
// 	do {
// 		flag = true;
// 		for (int i = y; i < y + cnt && flag; i++) {
// 			if (i == 10) {
// 				flag = false;
// 				break;
// 			}
// 			for (int j = x; j < x + cnt && flag; j++) {
// 				if (j == 10 || !map[i][j]) {
// 					flag = false;
// 					break;
// 				}
// 			}
// 		}
// 		if (flag) return cnt;
// 	} while (cnt--);
// }

// void fill_empty_array(int& y, int& x, int& cnt, bool flag, int tmp[][5]) {
// 	for (int i = y, n = 0; i < y + cnt; i++, n++) {
// 		for (int j = x, m = 0; j < x + cnt; j++, m++) {
// 			if (flag) { tmp[n][m] = arr[i][j]; arr[i][j] = 0; }
// 			else arr[i][j] = tmp[n][m];
// 		}
// 	}
// }

// bool is_right(int& y, int& x, int& cnt) {
// 	for (int i = y; i < y + cnt; i++)
// 		for (int j = x; j < x + cnt; j++)
// 			if (!arr[i][j]) return false;
	
// 	return true;
// }

// void dfs(int y, int x, int res, int res_cnt) {
// 	if (res == total) {
// 		ret = min(ret, 25 - res_cnt);
// 		return;
// 	}
// 	if (25 - res_cnt > ret) return;
// 	if (y == 10) return;
// 	if (x >= 10)    { dfs(y + 1, 0, res, res_cnt); return; }
// 	if (!arr[y][x]) { dfs(y, x + 1, res, res_cnt); return; }
// 	int val = arr[y][x];
// 	int tmp[5][5];
// 	for (int i = val; i >= 1; i--) {
// 		if (!color[i]) continue;
// 		if (!is_right(y, x, i)) continue;
// 		color[i]--;
// 		fill_empty_array(y, x, i, true, tmp);
// 		dfs(y, x + i, (res + (i * i)), res_cnt - 1);
// 		color[i]++;
// 		fill_empty_array(y, x, i, false, tmp);
// 	}
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	for (int i = 0; i < 10; i++)
// 		for (int j = 0; j < 10; j++)
// 			cin >> map[i][j];
// 	for (int i = 0; i < 10; i++) {
// 		for (int j = 0; j < 10; j++) {
// 			if (!map[i][j]) continue;
// 			arr[i][j] = what_kind_block(i, j);
// 			total++;
// 		}
// 	}
// 	dfs(0, 0, 0, 25);
// 	if (ret == INT_MAX) ret = -1;
// 	cout << ret << '\n';
// 	return 0;
// }