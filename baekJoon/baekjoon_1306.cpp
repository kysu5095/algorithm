// 달려라 홍준

#define MAX 1000001
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[MAX], tree[MAX << 2];

int init(int node, int l, int r) {
	if (l == r) return tree[node] = arr[l];
	int next = node << 1;
	int mid = (l + r) >> 1;
	return tree[node] = max(init(next, l, mid), init(next + 1, mid + 1, r));
}

int query(int node, int l, int r, int start, int end) {
	if (l > end || r < start) return 0;
	if (l >= start && r <= end) return tree[node];
	int next = node << 1;
	int mid = (l + r) >> 1;
	return max(query(next, l, mid, start, end), query(next + 1, mid + 1, r, start, end));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	init(1, 1, n);
	for (int i = m; i <= n - m + 1; i++)
		cout << query(1, 1, n, i - m + 1, i + m - 1) << " ";
	cout << '\n';
	return 0;
}