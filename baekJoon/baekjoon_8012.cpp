// 한동이는 영업사원!

#define MAX 30001
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int parent[MAX][16], depth[MAX];
bool visited[MAX] = { false, };
vector<int> v[MAX];

void dfs(int node, int dep) {
	visited[node] = true;
	depth[node] = dep;
	for (int next : v[node]) {
		if (visited[next]) continue;
		parent[next][0] = node;
		dfs(next, dep + 1);
	}
}

void make_parent() {
	for (int j = 1; j <= 15; j++) {
		for (int i = 1; i <= n; i++) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}
}

int LCA(int x, int y) {
	if (depth[x] != depth[y]) {
		if (depth[x] < depth[y]) swap(x, y);
		for (int i = 15; i >= 0; i--) {
			if (depth[x] - depth[y] >= (1 << i)) {
				x = parent[x][i];
			}
		}
	}
	if (x == y) return x;

	for (int i = 15; i >= 0; i--) {
		if (parent[x][i] != parent[y][i]) {
			x = parent[x][i];
			y = parent[y][i];
		}
	}
	return parent[x][0];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int a, b, res = 0;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0);
	make_parent();
	cin >> m >> a;
	m--;
	while (m--) {
		cin >> b;
		res += (depth[a] + depth[b] - (depth[LCA(a, b)] << 1));
		a = b;
	}
	cout << res << '\n';
	return 0;
}