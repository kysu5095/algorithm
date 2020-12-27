// 구간 합 구하기 2

#include <iostream>
#define ll long long

using namespace std;

int n, m, k;
int arr[1000001];
class Tree {
public:
	ll val = 0, lazy = 0;
};
Tree tree[4000004];

ll init(int node, int l, int r) {
	if (l == r) return tree[node].val = arr[l];
	return tree[node].val = init(node << 1, l, (l + r) >> 1) + init((node << 1) + 1, ((l + r) >> 1) + 1, r);
}

void update(int node, int l, int r, int& i, int& j, ll& val) {
	if (tree[node].lazy != 0) {
		tree[node].val += (r - l + 1) * tree[node].lazy;
		if (l != r) {
			tree[node << 1].lazy += tree[node].lazy;
			tree[(node << 1) + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}
	if (i > r || j < l) return;
	if (i <= l && j >= r) {
		tree[node].val += (r - l + 1) * val;
		if (l != r) {
			tree[node << 1].lazy += val;
			tree[(node << 1) + 1].lazy += val;
		}
		return;
	}
	update(node << 1, l, (l + r) >> 1, i, j, val);
	update((node << 1) + 1, ((l + r) >> 1) + 1, r, i, j, val);
	tree[node].val = tree[node << 1].val + tree[(node << 1) + 1].val;
}

ll query(int node, int l, int r, int& i, int& j) {
	if (tree[node].lazy != 0) {
		tree[node].val += (r - l + 1) * tree[node].lazy;
		if (l != r) {
			tree[node << 1].lazy += tree[node].lazy;
			tree[(node << 1) + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}
	if (l > j || r < i) return 0;
	if (i <= l && j >= r) return tree[node].val;
	return query(node << 1, l, (l + r) >> 1, i, j) + query((node << 1) + 1, ((l + r) >> 1) + 1, r, i, j);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	ll d;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	init(1, 1, n);
	for (int i = 0; i < m + k; i++) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			update(1, 1, n, b, c, d);
		}
		else {
			cin >> b >> c;
			cout << query(1, 1, n, b, c) << '\n';
		}
	}
	return 0;
}