// 트리의 독립집합

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int n, cnt = 1;
pair<int, int> p[10001];
int parent[10001] = { 0, };
int lenth[10001][2];

void dfs(int cur, int depth) {
	if (p[cur].first == -1 && p[cur].second == -1) {
		if (lenth[depth][0] == 0) lenth[depth][0] = cnt;
		else lenth[depth][1] = cnt;
		cnt++;
		return;
	}
	if (p[cur].first != -1) dfs(p[cur].first, depth + 1);
	if (lenth[depth][0] == 0) lenth[depth][0] = cnt;
	else lenth[depth][1] = cnt;
	cnt++;
	if (p[cur].second != -1) dfs(p[cur].second, depth + 1);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int node, left, right;
	cin >> n;
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	for (int i = 0; i < n; i++) {
		cin >> node >> left >> right;
		p[node].first = left;
		p[node].second = right;
		parent[left] = node;
		parent[right] = node;
	}
	for(int i = 1; i <= n; i++)
		if (parent[i] == i) {
			node = i;
			break;
		}

	dfs(node, 1);
	int ret_node = 1, ret_val = 0;
	for (int i = 1; i <= n; i++) {
		if (ret_val < lenth[i][1] - lenth[i][0]) {
			ret_val = lenth[i][1] - lenth[i][0];
			ret_node = i;
		}
	}
	cout << ret_node << " " << ret_val + 1 << '\n';
	return 0;
}