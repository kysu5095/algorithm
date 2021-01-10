// 히스토그램

#define ll long long
#define MAX 100001
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[MAX], tree[MAX << 2];

ll init(int node, int left, int right) {
	if (left == right) return tree[node] = arr[left];
	int next = node << 1;
	int mid = (left + right) >> 1;
	return tree[node] = min(init(next, left, mid), init(next + 1, mid + 1, right));
}

ll query(int node, int left, int right, int start, int& last) {
	if (left > last || right < start) return 0;
	if (left == right) return tree[node];
	int next = node << 1;
	int mid = (left + right) >> 1;
	return max((mid - left + 1) * query(next, left, mid, start, last), (right - mid) * query(next + 1, mid + 1, right, start, last));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	init(1, 1, n);
	cout << query(1, 1, n, 1, n) << '\n';
	return 0;
}