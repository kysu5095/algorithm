// 스티커 붙이기

#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k, r, c;
bool arr[41][41] = { {false,}, };
bool sticker[11][11], tmp[11][11];

void rotate() {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			tmp[i][j] = sticker[i][j];
	for (int i = 0; i < c; i++)
		for (int j = 0; j < r; j++)
			sticker[i][j] = tmp[r - j - 1][i];
	swap(r, c);
}

bool is_right(int& y, int& x) {
	for (int i = 0; i < r; i++) 
		for (int j = 0; j < c; j++) 
			if (arr[i + y][j + x] && sticker[i][j]) return false;

	return true;
}

void fill_arr(int& y, int& x) {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (sticker[i][j])
				arr[i + y][j + x] = true;
}

void game() {
	for (int k = 0; k < 4; k++) {
		for (int i = 0; i <= n - r; i++) {
			for (int j = 0; j <= m - c; j++) {
				if (is_right(i, j)) {
					fill_arr(i, j);
					return;
				}
			}
		}
		rotate();
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	while (k--) {
		cin >> r >> c;
		for (int i = 0; i < r; i++) 
			for (int j = 0; j < c; j++) 
				cin >> sticker[i][j];
		game();
	}
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j])
				res++;
	cout << res << '\n';
	return 0;
}