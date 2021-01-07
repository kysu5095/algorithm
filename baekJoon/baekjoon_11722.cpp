// 가장 긴 감소하는 부분 수열

#include <iostream>
#include <algorithm>

using namespace std;

int n, idx;
int arr[1001], lis[1001];

int get_index(int start, int last, int& val) {
	while (start < last) {
		int mid = (start + last) >> 1;
		if (lis[mid] > val) start = mid + 1;
		else last = mid;
	}
	return last;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	idx = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	lis[idx] = arr[idx];
	for (int i = 1; i < n; i++) {
		if (lis[idx] > arr[i]) {
			lis[++idx] = arr[i];
		}
		else {
			int val = get_index(0, idx, arr[i]);
			lis[val] = arr[i];
		}
	}
	cout << idx + 1 << '\n';
	return 0;
}