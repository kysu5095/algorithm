// 성수의 프로그래밍 강좌 시청

#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int arr[201];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int test_case;
	double res;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		res = 0;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr + n);
		for (int i = k; i >= 1; i--)
			res = (res + arr[n - i]) / 2;
		cout << "#" << tc << " " << res << '\n';
	}
	return 0;
}