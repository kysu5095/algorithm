// 부분배열 고르기

#define MAX 100001
#define ll long long
#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int n;
int arr[MAX], tree[MAX << 2];
ll pSum[MAX];

int init(int node, int left, int right) {
	if (left == right) return tree[node] = left;
	int next = node << 1;
	int mid = (left + right) >> 1;
	int l = init(next, left, mid);
	int r = init(next + 1, mid + 1, right);
	if (arr[l] <= arr[r]) return tree[node] = l;
	else return tree[node] = r;
}

int query(int node, int left, int right, int& start, int& end) {
	if (left > end || right < start) return 0;
	if (left >= start && right <= end) return tree[node];
	int next = node << 1;
	int mid = (left + right) >> 1;
	int l = query(next, left, mid, start, end);
	int r = query(next + 1, mid + 1, right, start, end);
	if (arr[l] <= arr[r]) return l;
	else return r;
}

ll result(int left, int right) {
	if (left > right) return 0;
	int idx = query(1, 1, n, left, right);
	ll res = (pSum[right] - pSum[left - 1]) * arr[idx];
	res = max(res, result(left, idx - 1));
	res = max(res, result(idx + 1, right));
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	arr[0] = INT_MAX;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		pSum[i] = arr[i] + pSum[i - 1];
	}
	init(1, 1, n);
	cout << result(1, n) << '\n';
	return 0;
}