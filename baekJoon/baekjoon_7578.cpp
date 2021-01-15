// 공장

#define ll long long
#define MAX 500000
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n;
ll tree[MAX << 2 + 1];
vector<pair<int, int>> v;
map<int, int> m;

void update(int node, int l, int r, int& idx) {
	if (idx < l || idx > r) return;
	tree[node]++;
	if (l == r) return;
	int next = node << 1;
	int mid = (l + r) >> 1;
	update(next, l, mid, idx);
	update(next + 1, mid + 1, r, idx);
}

ll query(int node, int l, int r, int start) {
	if (l > n || r < start) return 0;
	if (l >= start && r <= n) return tree[node];
	int next = node << 1;
	int mid = (l + r) >> 1;
	return query(next, l, mid, start) +
		   query(next + 1, mid + 1, r, start);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int a;
	ll res = 0;
	cin >> n;
	v.resize(n);
	for (int i = 1; i <= n; i++) {
		cin >> a;
		m[a] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> a;
		v[i].first = i + 1;
		v[i].second = m[a];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		res += query(1, 1, n, v[i].second + 1);
		update(1, 1, n, v[i].second);
	}
	cout << res << '\n';
	return 0;
}