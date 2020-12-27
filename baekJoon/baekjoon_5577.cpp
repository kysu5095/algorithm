// RBY팡!

#include <iostream>
#include <algorithm>

using namespace std;

int n, res;
int arr[10001];
int tmp[10001];

void copy_arr() {
	for (int i = 0; i < n; i++)
		arr[i] = tmp[i];
}

void color_change(int& idx, int color) {
	arr[idx] = color;
	int up = idx - 1;
	int down = idx + 1;
	int ucnt = 0, dcnt = 1, total = n;
	while (true) {
		while (true) {
			if (up < 0) break;
			if (arr[up] != -1 && arr[up] != color) break;
			if (arr[up] == color) ucnt++;
			up--;
		}
		up++;
		while (true) {
			if (down == n) break;
			if (arr[down] != -1 && arr[down] != color) break;
			if (arr[down] == color) dcnt++;
			down++;
		}
		down--;
		if (up == down) break;
		if (dcnt + ucnt < 4) break;
		for (int i = up; i <= down; i++)
			arr[i] = -1;
		total -= (dcnt + ucnt);
		if (!total) break;
		up--;
		down++;
		if (up >= 0) color = arr[up];
		else color = arr[down];
		ucnt = 0;
		dcnt = 0;
	}
	res = min(res, total);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int color;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		tmp[i] = arr[i];
	}
	res = n;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 3; j++)
			if (arr[i] != j) {
				color_change(i, j);
				copy_arr();
			}
	}
	cout << res << '\n';
	return 0;
}