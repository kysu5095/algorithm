// 여행가자

#include <iostream>

using namespace std;

int n, m;
int parent[201];
int map[1001];
bool arr[201][201];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void union_parent(int y, int x) {
	y = find(y);
	x = find(x);
	if (y == x) return;
	if (y < x) parent[x] = y;
	else parent[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j])
				union_parent(i, j);
		}
	for (int i = 0; i < m; i++)
		cin >> map[i];
	bool flag = true;
	int p = find(map[0]);
	for(int i = 1; i < m; i++)
		if (find(map[i]) != p) {
			flag = false;
			break;
		}

	if (flag) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}