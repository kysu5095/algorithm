// 랜선 자르기

#include <iostream>
#include <algorithm>

using namespace std;

int k, n;
int arr[10001];

bool desc(int &a, int &b) {
	return a > b;
}

bool get_lan(int mid) {
	int cnt = 0;
	for (int i = 0; i < k; i++)
		cnt += (arr[i] / mid);
	if (cnt >= n) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> k >> n;
	for (int i = 0; i < k; i++)
		cin >> arr[i];
	sort(arr, arr + k, desc);
	long long start = 1;
	long long last = arr[0];
	long long mid, res = 0;
	while (start <= last) {
		mid = (start + last) / 2;
		if (get_lan(mid)) {
			if (res < mid)
				res = mid;
			start = mid + 1;
		}
		else
			last = mid - 1;
	}
	cout << res << '\n';
	return 0;
}