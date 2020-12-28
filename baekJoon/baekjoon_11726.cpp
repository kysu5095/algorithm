// 2xn 타일링

#include <iostream>

using namespace std;

int n;
int arr[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	arr[0] = arr[1] = 1;
	for (int i = 2; i <= n; i++) 
		arr[i] = (arr[i - 2] + arr[i - 1]) % 10007;
	cout << arr[n] << '\n';
	return 0;
}