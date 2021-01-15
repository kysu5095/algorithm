// 중앙값 측정

#define MAX 65536
#define ll long long
#include <iostream>

using namespace std;

int n, k, cnt;
ll res = 0;
int arr[250001], tree[MAX << 2];

void update(int node, int l, int r, int& idx, int val) {
	if (idx < l || idx > r) return;
	tree[node] += val;
	if (l == r) return;
	int next = node << 1;
	int mid = (l + r) >> 1;
	update(next, l, mid, idx, val);
	update(next + 1, mid + 1, r, idx, val);
}

ll query(int node, int l, int r, int val) {
	if (l == r) return l;
	int next = node << 1;
	int mid = (l + r) >> 1;
	if (val <= tree[next]) return query(next, l, mid, val);
	else return query(next + 1, mid + 1, r, val - tree[next]);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int input;
	cin >> n >> k;
	cnt = (k + 1) / 2;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		update(1, 0, MAX, arr[i], 1);
		if (i >= k) {
			if (i != k) update(1, 0, MAX, arr[i - k], -1);
			res += query(1, 0, MAX, cnt);
		}
	}
	cout << res << '\n';
	return 0;
}