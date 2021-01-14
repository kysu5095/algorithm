// 사탕상자

#define ll long long
#define MAX (1 << 20)
#include <iostream>

using namespace std;

int n;
ll res;
int arr[MAX], tree[MAX << 2 + 1];

void update(int node, int l, int r, int& idx, int val) {
	if (idx < l || idx > r) return;
	tree[node] += val;
	if (l == r) return;
	int next = node << 1;
	int mid = (l + r) >> 1;
	update(next, l, mid, idx, val);
	update(next + 1, mid + 1, r, idx, val);
}

ll query(int node, int l, int r, int cnt) {
	if (!res && (l == r)) {
		cout << l << '\n';
		return l;
	}
	int next = node << 1;
	int mid = (l + r) >> 1;
	if (!res && next <= (MAX << 2) && tree[next] >= cnt)
		return res = query(next, l, mid, cnt);

	cnt -= tree[next];
	if (!res && next + 1 <= (MAX << 2) && tree[next + 1] >= cnt)
		return res = query(next + 1, mid + 1, r, cnt);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	res = 0;
	cin >> n;
	while (n--) {
		cin >> a;
		if (a == 1) {
			cin >> b;
			int idx = query(1, 1, MAX, b);
			res = 0;
			update(1, 1, MAX, idx, -1);
		}
		else {
			cin >> b >> c;
			update(1, 1, MAX, b, c);
		}
	}
	return 0;
}