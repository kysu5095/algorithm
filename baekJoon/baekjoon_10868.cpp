//최솟값

#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int n, m;
long long arr[100001];
long long tree[400004];

long long init(int node, int l, int r) {
	if (l == r) return tree[node] = arr[l];
	return tree[node] = min(init(node << 1, l, (l + r) >> 1), init((node << 1) + 1, ((l + r) >> 1) + 1, r));
}

long long query(int node, int l, int r, int& a, int& b) {
	if (a > r || b < l) return LLONG_MAX;
	if (a <= l && b >= r) return tree[node];
	return min(query(node << 1, l, (l + r) >> 1, a, b), query((node << 1) + 1, ((l + r) >> 1) + 1, r, a, b));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	init(1, 1, n);
	while (m--) {
		cin >> a >> b;
		cout << query(1, 1, n, a, b) << '\n';
	}
	return 0;
}