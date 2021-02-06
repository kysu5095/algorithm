// 붕어빵 타이쿤

#include <iostream>
#include <string.h>
#include <limits.h>

using namespace std;

int n, m, res = INT_MAX;
int arr[16][16], copy_arr[16][16], cnt_arr[16][16], result[16][16];
int dy[5] = { 0, 0, 0, 1, -1 };
int dx[5] = { 0, 1, -1, 0, 0 };

void BUTTON(int& y, int& x) {
	int ny, nx;
	for (int i = 0; i < 5; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || ny == n | nx < 0 || nx == m) continue;
		copy_arr[ny][nx] ^= 1;
	}
}

int TYCOON(int flag) {
	int ret = 0;
	int binary = 1 << (m - 1);
	memcpy(copy_arr, arr, sizeof(arr));
	memset(cnt_arr, 0, sizeof(cnt_arr));
	for (int i = 0; i < m; i++) {
		if (flag & (binary >> i)) {
			ret++;
			cnt_arr[0][i]++;
			int row = 0;
			BUTTON(row, i);
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copy_arr[i - 1][j]) {
				ret++;
				cnt_arr[i][j]++;
				BUTTON(i, j);
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (copy_arr[i][j])
				return INT_MAX;
	return ret;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	for (int i = 0; i < (1 << m); i++) {
		int ret = TYCOON(i);
		if (ret < res) {
			res = ret;
			memcpy(result, cnt_arr, sizeof(cnt_arr));
		}
	}
	if (res == INT_MAX) cout << "IMPOSSIBLE\n";
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << result[i][j] << " ";
			}
			cout << '\n';
		}
	}
	return 0;
}