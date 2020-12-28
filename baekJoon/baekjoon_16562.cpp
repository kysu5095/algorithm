// 친구비

#include <iostream>
#include <string.h>

using namespace std;

int n, m, k;
int parent[10001];
int arr[10001];

int find(int x) {
	if (parent[x] == -1) return x;
	return parent[x] = find(parent[x]);
}

void union_parent(int y, int x) {
	y = find(y);
	x = find(x);
	if (y == x) return;
	if (arr[y] > arr[x]) parent[y] = x;
	else parent[x] = y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> n >> m >> k;
	memset(parent, -1, sizeof(parent));
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		union_parent(a, b);
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
		if (parent[i] == -1)
			res += arr[i];
	if (res > k) cout << "Oh no\n";
	else cout << res << '\n';
	return 0;
}