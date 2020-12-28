// 트리와 쿼리

#include <iostream>
#include <vector>

using namespace std;

int n, r, q;
vector<int> v[100001];
int tree[100001] = { 0, };

void dfs(int& cur, int& parent) {
	tree[cur] = 1;
	int len = v[cur].size();
	for (int i = 0; i < len; i++) {
		if (v[cur][i] != parent) {
			dfs(v[cur][i], cur);
			tree[cur] += tree[v[cur][i]];
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> r >> q;
	int node1, node2;
	for (int i = 0; i < n - 1; i++) {
		cin >> node1 >> node2;
		v[node1].push_back(node2);
		v[node2].push_back(node1);
	}
	int tmp = -1;
	dfs(r, tmp);
	for (int i = 0; i < q; i++) {
		cin >> node1;
		cout << tree[node1] << '\n';
	}
	return 0;
}