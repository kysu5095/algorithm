// 트리의 지름

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int n, first_node, res;
bool visited[10001] = { false, };
vector<pair<int, int>> v[10001];

void dfs(int node, int cost) {
	if (cost > res) {
		res = cost;
		first_node = node;
	}
	int len = v[node].size();
	for (int i = 0; i < len; i++) {
		if (!visited[v[node][i].first]) {
			visited[v[node][i].first] = true;
			dfs(v[node][i].first, cost + v[node][i].second);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int node1, node2, cost;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> node1 >> node2 >> cost;
		v[node1].push_back(make_pair(node2, cost));
		v[node2].push_back(make_pair(node1, cost));
	}
	dfs(1, 0);
	res = 0;
	memset(visited, false, sizeof(visited));
	dfs(first_node, 0);
	cout << res << '\n';
	return 0;
}