// 수열과 쿼리 21

#include <iostream>
#define ll long long

using namespace std;

int n, m;
int arr[100001];
class Tree {
public:
	ll val, lazy;
};
Tree tree[400004];

ll init(int node, int l, int r) {
	if (l == r) return tree[node].val = arr[l];
	return tree[node].val = init(node << 1, l, (l + r) >> 1) + init((node << 1) + 1, ((l + r) >> 1) + 1, r);
}

void update(int node, int l, int r, int& a, int& b, ll& val) {
	if (tree[node].lazy != 0) {
		tree[node].val += (r - l + 1) * tree[node].lazy;
		if (l != r) {
			tree[node << 1].lazy += tree[node].lazy;
			tree[(node << 1) + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}
	if (l > b || r < a) return;
	if (l >= a && r <= b) {
		tree[node].val += (r - l + 1) * val;
		if (l != r) {
			tree[node << 1].lazy += val;
			tree[(node << 1) + 1].lazy += val;
		}
		return;
	}
	update(node << 1, l, (l + r) >> 1, a, b, val);
	update((node << 1) + 1, ((l + r) >> 1) + 1, r, a, b, val);
	tree[node].val = tree[node << 1].val + tree[(node << 1) + 1].val;
}

ll query(int node, int l, int r, int& idx) {
	if (tree[node].lazy != 0) {
		tree[node].val += (r - l + 1) * tree[node].lazy;
		if (l != r) {
			tree[node << 1].lazy += tree[node].lazy;
			tree[(node << 1) + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}
	if (idx < l || idx > r) return 0;
	if (l == r) return tree[node].val;
	return query(node << 1, l, (l + r) >> 1, idx) + query((node << 1) + 1, ((l + r) >> 1) + 1, r, idx);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	ll d;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	init(1, 1, n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			update(1, 1, n, b, c, d);
		}
		else {
			cin >> b;
			cout << query(1, 1, n, b) << '\n';
		}
	}
	return 0;
}