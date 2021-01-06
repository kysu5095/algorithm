// 최소 스패닝 트리

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[10002];

class Point {
public:
	int a, b, c;
	bool operator < (const Point& p) const {
		return c < p.c;
	}
};
vector<Point> v;

int find_parent(int x) {
	if (x == arr[x]) return x;
	return arr[x] = find_parent(arr[x]);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int a, b, c, pa, pb;
	long long res = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v.push_back({ a, b, c });
	}
	for (int i = 1; i <= n; i++) arr[i] = i;
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		a = v[i].a;
		b = v[i].b;
		c = v[i].c;
		pa = find_parent(a);
		pb = find_parent(b);
		if (pa == pb) continue;
		if (pa < pb) arr[pb] = pa;
		else arr[pa] = pb;
		res += c;
	}
	cout << res << '\n';
	return 0;
}