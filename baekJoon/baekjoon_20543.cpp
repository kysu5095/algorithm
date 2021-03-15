// 폭탄 던지는 태영이

#include <iostream>
#define ll long long

using namespace std;

int n, m;
ll arr[2001][2001], res[2001][2001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j], arr[i][j] *= -1;
	int r = m >> 1;
	for (int i = r; i < n - r; i++) {
		for (int j = r; j < n - r; j++) {
			res[i][j] = arr[i - r][j - r];
			if (i - r - 1 >= 0) res[i][j] -= arr[i - r - 1][j - r];
			if (j - r - 1 >= 0) res[i][j] -= arr[i - r][j - r - 1];
			if (i - r - 1 >= 0 && j - r - 1 >= 0) res[i][j] += arr[i - r - 1][j - r - 1];
			if (i - m >= 0)res[i][j] += res[i - m][j];
			if (j - m >= 0)res[i][j] += res[i][j - m];
			if (i - m >= 0 && j - m >= 0)res[i][j] -= res[i - m][j - m];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << res[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}