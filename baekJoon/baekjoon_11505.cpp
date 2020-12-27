// 구간 곱 구하기

#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int n, m, k;
vector<long long> v;
vector<long long> tree;

long long init(int node, int l, int r) {
	if (l == r) return tree[node] = v[l] % MOD;
	else return tree[node] = (init(node << 1, l, (l + r) >> 1) * init((node << 1) + 1, ((l + r) >> 1) + 1, r)) % MOD;
}

long long update(int node, int l, int r, int& idx, int& val) {
	if (idx < l || idx > r) return tree[node];
	if (l == r) return tree[node] = val;
	return tree[node] = (update(node << 1, l, (l + r) >> 1, idx, val) * update((node << 1) + 1, ((l + r) >> 1) + 1, r, idx, val)) % MOD;
}

long long query(int node, int l, int r, int& a, int& b) {
	if (b < l || r < a) return 1;
	if (a <= l && r <= b) return tree[node];
	return (query(node << 1, l, (l + r) >> 1, a, b) * query((node << 1) + 1, ((l + r) >> 1) + 1, r, a, b)) % MOD;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	cin >> n >> m >> k;
	v = vector<long long>(n + 1);
	tree = vector<long long>(n * 4);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	init(1, 1, n);
	for (int i = 1; i <= m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) update(1, 1, n, b, c);
		else cout << query(1, 1, n, b, c) << '\n';
	}
	return 0;
}