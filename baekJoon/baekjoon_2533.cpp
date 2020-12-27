// 사회망 서비스(SNS)

#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#define FULL 1000000

using namespace std;

int n;
int dp[FULL + 1][2];
bool visited[FULL + 1] = { false, };
vector<int> tmp[FULL + 1];
vector<int> v[FULL + 1];

void dfs(int node) {
	if (!tmp[node].size()) return;
	for (int i = 0; i < tmp[node].size(); i++) {
		if (!visited[tmp[node][i]]) {
			visited[node] = true;
			v[node].push_back(tmp[node][i]);
			dfs(tmp[node][i]);
		}
	}
}

int SNS(int node, bool flag) {
	int& ret = dp[node][flag];
	if (ret != -1) return ret;
	
	if (flag) {
		ret = 1;
		for (int i = 0; i < v[node].size(); i++)
			ret += min(SNS(v[node][i], true), SNS(v[node][i], false));
	}
	else {
		ret = 0;
		for (int i = 0; i < v[node].size(); i++)
			ret += SNS(v[node][i], true);
	}
	return ret;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int node1, node2;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> node1 >> node2;
		tmp[node1].push_back(node2);
		tmp[node2].push_back(node1);
	}
	visited[1] = true;
	dfs(1);
	memset(dp, -1, sizeof(dp));
	cout << min(SNS(1, false), SNS(1, true)) << '\n';
	return 0;
}