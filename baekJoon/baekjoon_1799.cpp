// 비숍

#include <iostream>
#include <algorithm>

using namespace std;

int n, res1 = 0, res2 = 0;
int arr[11][11];

bool promising(int &y, int &x) {
	for (int idx = 1; idx < n; idx++) {
		if (y - idx < 0) break;
		if (x - idx >= 0 && arr[y - idx][x - idx] == 2) return false;
		if (x + idx < n  && arr[y - idx][x + idx] == 2) return false;
	}
	return true;
}

void backtracking_odd(int y, int x, int cnt) {
	if (y == n) {
		res1 = max(res1, cnt);
		return;
	}
	if (x >= n) {
		if(y % 2 == 1) backtracking_odd(y + 1, 0, cnt);
		else backtracking_odd(y + 1, 1, cnt);
		return;
	}
	if (arr[y][x] == 0) {
		backtracking_odd(y, x + 2, cnt);
		return;
	}
	if (promising(y, x)) {
		arr[y][x] = 2;
		backtracking_odd(y, x + 2, cnt + 1);
		arr[y][x] = 1;
	}
	backtracking_odd(y, x + 2, cnt);
}

void backtracking_even(int y, int x, int cnt) {
	if (y == n) {
		res2 = max(res2, cnt);
		return;
	}
	if (x >= n) {
		if(y % 2 == 1) backtracking_even(y + 1, 1, cnt);
		else backtracking_even(y + 1, 0, cnt);
		return;
	}
	if (arr[y][x] == 0) {
		backtracking_even(y, x + 2, cnt);
		return;
	}
	if (promising(y, x)) {
		arr[y][x] = 2;
		backtracking_even(y, x + 2, cnt + 1);
		arr[y][x] = 1;
	}
	backtracking_even(y, x + 2, cnt);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	backtracking_odd(0, 0, 0);
	backtracking_even(0, 1, 0);
	cout << res1 + res2 << '\n';
	return 0;
}