// 최솟값과 최댓값

#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int n, m;
long long arr[100001];
long long min_tree[400004];
long long max_tree[400004];

long long min_init(int node, int l, int r) {
	if (l == r) return min_tree[node] = arr[l];
	else return min_tree[node] = min(min_init(node << 1, l, (l + r) >> 1), min_init((node << 1) + 1, ((l + r) >> 1) + 1, r));
}

long long min_query(int node, int l, int r, int& a, int& b) {
	if (a > r || b < l) return LLONG_MAX;
	if (a <= l && b >= r) return min_tree[node];
	return min(min_query(node << 1, l, (l + r) >> 1, a, b), min_query((node << 1) + 1, ((l + r) >> 1) + 1, r, a, b));
}

long long max_init(int node, int l, int r) {
	if (l == r) return max_tree[node] = arr[l];
	return max_tree[node] = max(max_init(node << 1, l, (l + r) >> 1), max_init((node << 1) + 1, ((l + r) >> 1) + 1, r));
}

long long max_query(int node, int l, int r, int& a, int& b) {
	if (a > r || b < l) return 0;
	if (a <= l && b >= r) return max_tree[node];
	return max(max_query(node << 1, l, (l + r) >> 1, a, b), max_query((node << 1) + 1, ((l + r) >> 1) + 1, r, a, b));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	min_init(1, 1, n);
	max_init(1, 1, n);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << min_query(1, 1, n, a, b) << " ";
		cout << max_query(1, 1, n, a, b) << '\n';
	}
	return 0;
}