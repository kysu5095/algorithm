// 이친수

#include <iostream>

using namespace std;

int n;
long long arr[100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	arr[1] = 1;
	arr[2] = 1;
	for (int i = 3; i <= n; i++)
		arr[i] = arr[i - 2] + arr[i - 1];
	cout << arr[n] << '\n';
	return 0;
}