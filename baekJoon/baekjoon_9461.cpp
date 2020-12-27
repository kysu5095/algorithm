// 파도반 수열

#include <iostream>
#include <algorithm>

using namespace std;

int t, n;
long long arr[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		arr[1] = arr[2] = arr[3] = 1;
		for (int i = 4; i <= n; i++)
			arr[i] = arr[i - 2] + arr[i - 3];
		cout << arr[n] << '\n';
	}
	return 0;
}