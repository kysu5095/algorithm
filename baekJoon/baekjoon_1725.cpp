// 히스토그램

#define ll long long
#define MAX 100001
#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int n;
int arr[MAX], tree[MAX << 2];

ll init(int node, int left, int right) {
	if (left == right) return tree[node] = left;
	int next = node << 1;
	int mid = (left + right) >> 1;
	int lval = init(next, left, mid);
	int rval = init(next + 1, mid + 1, right);
	if (arr[lval] <= arr[rval]) return tree[node] = lval;
	else return tree[node] = rval;
}

ll query(int node, int left, int right, int& start, int& last) {
	if (left > last || right < start) return 0;
	if (left >= start && right <= last) return tree[node];
	int next = node << 1;
	int mid = (left + right) >> 1;
	int lval = query(next, left, mid, start, last);
	int rval = query(next + 1, mid + 1, right, start, last);
	if (arr[lval] <= arr[rval]) return lval;
	else return rval;
}

ll find(int left, int right) {
	if (left > right) return 0;
	int idx = query(1, 1, n, left, right);
	ll res = (right - left + 1) * arr[idx];
	res = max(res, find(left, idx - 1));
	res = max(res, find(idx + 1, right));
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	arr[0] = INT_MAX;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	init(1, 1, n);
	cout << find(1, n) << '\n';
	return 0;
}