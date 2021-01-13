// LCA 2

#define MAX 100000
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int parent[MAX + 1][18] = { {0,}, };
int dep[MAX + 1];
bool visited[MAX + 1] = { false, };
vector<int> v[MAX + 1];

void dfs(int node, int depth) {
	visited[node] = true;
	dep[node] = depth;
	for (int next : v[node]) {
		if (visited[next]) continue;
		parent[next][0] = node;
		dfs(next, depth + 1);
	}
}

void make_parent() {
	for (int j = 1; j <= 17; j++)
		for (int i = 1; i <= n; i++)
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
}

int LCA(int left, int right) {
	if (dep[left] != dep[right]) {
		if (dep[left] < dep[right]) swap(left, right);
		for (int i = 17; i >= 0; i--)
			if (dep[left] - dep[right] >= (1 << i))
				left = parent[left][i];
	}

	if (left == right) return left;
	
	if (left != right) {
		for (int i = 17; i >= 0; i--) {
			if (parent[left][i] != parent[right][i]) {
				left = parent[left][i];
				right = parent[right][i];
			}
		}
	}
	return parent[left][0];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0);
	make_parent();

	cin >> m;
	while (m--) {
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}
	return 0;
}