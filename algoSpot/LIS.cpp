// Longest Increasing Sequence

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int test_case, n;
int arr[501];
int lis[501];

int binary(int start, int last, int& val) {
	int mid;
	while (start < last) {
		mid = (start + last) >> 1;
		if (lis[mid] < val) start = mid + 1;
		else last = mid;
	}
	return last;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int idx;
	cin >> test_case;
	while (test_case--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		idx = 0;
		memset(lis, 0, sizeof(lis));
		lis[0] = arr[0];
		for (int i = 1; i < n; i++) {
			if (lis[idx] < arr[i]) {
				lis[++idx] = arr[i];
			}
			else {
				int idx2 = binary(0, idx, arr[i]);
				lis[idx2] = arr[i];
			}
		}
		cout << idx + 1 << '\n';
	}
	return 0;
}