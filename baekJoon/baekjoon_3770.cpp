// 대한민국

#define MAX 400000
#define ll long long
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int T, n, m, k;
int tree[MAX << 2 + 1];
vector<pair<int, int>> v;

void update(int node, int l, int r, int& idx) {
	if (idx < l || idx > r) return;
	tree[node] += 1;
	if (l == r) return;
	int next = node << 1;
	int mid = (l + r) >> 1;
	update(next, l, mid, idx);
	update(next + 1, mid + 1, r, idx);
}

ll query(int node, int l, int r, int start, int& end) {
	if (l > end || r < start) return 0;
	if (l >= start && r <= end) return tree[node];
	int next = node << 1;
	int mid = (l + r) >> 1;
	return query(next, l, mid, start, end) + query(next + 1, mid + 1, r, start, end);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	ll res;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n >> m >> k;
		if (n < m) swap(n, m);
		res = 0;
		v.clear();
		v.resize(k);
		for (int i = 0; i < k; i++) 
			cin >> v[i].first >> v[i].second;
		sort(v.begin(), v.end());
		for (int i = 0; i < k; i++) {
			res += query(1, 1, n, v[i].second + 1, n);
			update(1, 1, n, v[i].second);
		}
		cout << "Test case " << tc << ": " << res << '\n';
		memset(tree, 0, sizeof(tree));
	}
	return 0;
}