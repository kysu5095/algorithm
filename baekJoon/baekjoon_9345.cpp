// 디지털 비디오 디스크(DVDs)

#include <iostream>
#define ll long long

using namespace std;

int T, n, k;
int arr[100001];
ll tree[400004];

ll init(int node, int l, int r) {
	if (l == r) return tree[node] = arr[l];
	return tree[node] = init(node << 1, l, (l + r) >> 1) + init((node << 1) + 1, ((l + r) >> 1) + 1, r);
}

ll update(int node, int l, int r, int& idx, int val) {
	if (idx < l || idx > r) return tree[node];
	if (l == r) return tree[node] = val;
	return tree[node] = update(node << 1, l, (l + r) >> 1, idx, val) + update((node << 1) + 1, ((l + r) >> 1) + 1, r, idx, val);
}

ll query(int node, int l, int r, int& a, int& b) {
	if (l > b || r < a) return 0;
	if (l >= a && r <= b) return tree[node];
	return query(node << 1, l, (l + r) >> 1, a, b) + query((node << 1) + 1, ((l + r) >> 1) + 1, r, a, b);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int Q, a, b;
	ll s1, s2;
	cin >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			arr[i] = i - 1;
		init(1, 1, n);
		while (k--) {
			cin >> Q;
			if (Q == 0) {
				cin >> a >> b;
				a++, b++;
				if (a < b) {
					update(1, 1, n, a, b - a);
					update(1, 1, n, b, a - b);
				}
				else {
					update(1, 1, n, a, a - b);
					update(1, 1, n, b, b - a);
				}
			}
			else {
				cin >> a >> b;
				a++, b++;
				s1 = (b * (b + 1)) >> 1;
				s2 = (a * (a - 1)) >> 1;
				s1 -= s2;
				s2 = query(1, 1, n, a, b);
				cout << "S1 : " << s1 << "  S2 : " << s2 << '\n';
				if (s1 == s2) cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}
	return 0;
}