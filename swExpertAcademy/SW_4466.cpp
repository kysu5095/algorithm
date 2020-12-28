// 최대 성적표 만들기

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case, n ,k;
	int arr[100];
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		int sum = 0;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr + n);
		for (int i = 0; i < k; i++)
			sum += arr[n - 1 - i];
		cout << "#" << tc << " " << sum << '\n';
	}
	return 0;
}