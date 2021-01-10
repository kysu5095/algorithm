// 수들의 합

#define ll long long
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<ll> v, tree;

/*
node  : 현재 index
left  : 왼쪽 index,              right : 오른쪽 index
start : 목표로하는 범위의 최소값,  last : 목표로하는 범위의 최대값
*/
ll query(int node, int left, int right, int& start, int& last) {
	if (left > last || right < start) return 0;
	if (left >= start && right <= last) return tree[node];
	int next = node << 1;
	int mid  = (left + right) >> 1;
	return query(next, left, mid, start, last) +
		   query(next + 1, mid + 1, last, start, last);
}

/*
node : 현재 index
left : 왼쪽 index,          right : 오른쪽 index
idx  : 바꾸려는 값의 index,  val : 변화하는 값의 차이
*/
void update(int node, int left, int right, int& idx, ll& val) {
	if (idx < left || idx > right) return;
	tree[node] += val;
	if (left == right) return;
	int next = node << 1;
	int mid = (left + right) >> 1;
	update(next, left, mid, idx, val);
	update(next + 1, mid + 1, right, idx, val);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int oper, a, b;
	cin >> n >> m;
	v.resize(n + 1);
	tree.resize((n + 1) * 4);
	for (int i = 0; i < m; i++) {
		cin >> oper >> a >> b;
		if (oper) {
			ll diff = (ll)b - v[a];
			v[a] = (ll)b;
			update(1, 1, n, a, diff);
		}
		else {
			if (a > b) swap(a, b);
			cout << query(1, 1, n, a, b) << '\n';
		}
	}
	return 0;
}