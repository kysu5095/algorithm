// 타일 장식물

#include <iostream>

using namespace std;

int n;
long long arr[81] = { 0, };

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	arr[1] = 1;
	arr[2] = 1;
	for (int i = 3; i <= n; i++)
		arr[i] = arr[i - 1] + arr[i - 2];
	cout << (arr[n] * 2) + ((arr[n] + arr[n - 1]) * 2) << '\n';
	return 0;
}