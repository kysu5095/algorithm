// 반도체 설계

#include <iostream>

using namespace std;

int n, res;
int arr[40001];
int lis[40001];

int bound(int start, int last, int& target) {
	int mid;
	while (start < last) {
		mid = (start + last) >> 1;
		if (lis[mid] < target) start = mid + 1;
		else last = mid;
	}
	return last;
}

void LIS() {
	lis[0] = arr[0];
	int i = 1, j = 0;
	while (i < n) {
		if (arr[i] > lis[j]) lis[++j] = arr[i];
		else {
			int idx = bound(0, j, arr[i]);
			lis[idx] = arr[i];
		}
		i++;
	}
	cout << j + 1 << '\n';
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	LIS();
	return 0;
}