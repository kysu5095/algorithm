// 빌보의 생일

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <map>
#define ll long long
#define MAX 100000

using namespace std;

int n;
int tree[MAX << 2 + 1];
vector<pair<int, int>> v;
map<string, int> m;

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
	return query(next, l, mid, start) + query(next + 1, mid + 1, r, start);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	while (true) {
		cin >> n;
		if (n == 0) break;
		m.clear();
		v.clear();
		v.resize(n);
		memset(tree, 0, sizeof(tree));
		string tmp;
		for (int i = 1; i <= n; i++) {
			cin >> tmp;
			m[tmp] = i;
		}
		for (int i = 1; i <= n; i++) {
			cin >> tmp;
			v[i - 1] = make_pair(i, m[tmp]);
		}
		sort(v.begin(), v.end());
		ll res = 0;
		for (int i = 0; i < n; i++) {
			res += query(1, 1, n, v[i].second + 1);
			update(1, 1, n, v[i].second);
		}
		cout << res << '\n';
	}
	return 0;
}