// RGB거리
// 3:25

#include <iostream>
#include <algorithm>

using namespace std;

int n, res;
int arr[1001][3];

void RGB() {
	int R, G, B;
	for (int i = 1; i < n; i++) {
		arr[i][0] = arr[i][0] + min(arr[i - 1][1], arr[i - 1][2]);
		arr[i][1] = arr[i][1] + min(arr[i - 1][0], arr[i - 1][2]);
		arr[i][2] = arr[i][2] + min(arr[i - 1][0], arr[i - 1][1]);
	}
	res = min(arr[n - 1][0], min(arr[n - 1][1], arr[n - 1][2]));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];
	RGB();
	cout << res << '\n';
	return 0;
}