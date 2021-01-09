// 커피숍2

#define ll long long
#include <iostream>

using namespace std;

int n, q;
int arr[1 << 17];
ll tree[1 << 19];

ll init(int node, int start, int last) {
	if (start == last) return tree[node] = arr[start];
	int mid = (start + last) >> 1;
	return tree[node] = init(node << 1, start, mid) + init((node << 1) + 1, mid + 1, last);
}

ll query(int node, int start, int last, int& left, int& right) {
	if (start > right || last < left) return 0;
	if (start >= left && last <= right) return tree[node];
	int mid = (start + last) >> 1;
	return query(node << 1, start, mid, left, right) +
		   query((node << 1) + 1, mid + 1, last, left, right);
}

void update(int node, int start, int last, int&idx ,ll& val) {
	if (idx < start || idx > last) return;
	tree[node] += val;
	if (start == last) return;
	int mid = (start + last) >> 1;
	update(node << 1, start, mid, idx, val);
	update((node << 1) + 1, mid + 1, last, idx, val);
}


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	ll d;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	init(1, 1, n);
	while (q--) {
		cin >> a >> b >> c >> d;
		if (a > b) swap(a, b);
		cout << query(1, 1, n, a, b) << '\n';
		ll diff = d - arr[c];
		arr[c] = (int)d;
		update(1, 1, n, c, diff);
	}
	return 0;
}