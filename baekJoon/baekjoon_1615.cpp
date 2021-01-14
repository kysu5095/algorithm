// 교차개수세기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int, int>> v;
int arr[2001];

void update(int idx, int val) {
	while (idx <= n) {
		arr[idx] += val;
		idx += (idx & -idx);
	}
}

int query(int idx) {
	int ret = 0;
	while (idx) {
		ret += arr[idx];
		idx -= (idx & -idx);
	}
	return ret;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());

	int res = 0;
	for (int i = 0; i < m; i++) {
		res += (query(n) - query(v[i].second));
		update(v[i].second, 1);
	}
	cout << res << '\n';
	return 0;
}