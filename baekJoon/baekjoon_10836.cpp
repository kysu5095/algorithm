// 여왕벌
// 11:50

#include <iostream>
#include <algorithm>

using namespace std;

int m, n;
int arr[701][701] = { {0,}, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;
	int a, b, c, y, x;
	for (int i = 0; i < n; i++) {
		y = m - 1;
		x = 0;
		cin >> a >> b >> c;
		while (a) {
			a--;
			if (y) y--;
			else x++;
		}
		while (b) {
			arr[y][x]++;
			b--;
			if (y) y--;
			else x++;
		}
		while (c) {
			arr[y][x] += 2;
			c--;
			if (y) y--;
			else x++;
		}
	}
	for (int i = 1; i < m; i++)
		for (int j = 1; j < m; j++)
			arr[i][j] = max(arr[i][j - 1], max(arr[i - 1][j - 1], arr[i - 1][j]));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] + 1 << " ";
		}
		cout << '\n';
	}
	return 0;
}