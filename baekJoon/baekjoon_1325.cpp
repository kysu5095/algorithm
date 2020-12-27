// 효율적인 해킹

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int n, m, maxV = 0;
int arr[10001] = { 0, };
bool visited[10001] = { false, };
vector<int> v[10001];

void dfs(int &node, int cnt) {
	visited[node] = true;
	int len = v[node].size();
	for (int i = 0; i < len; i++) {
		if (!visited[v[node][i]]) {
			arr[v[node][i]]++;
			maxV = maxV < arr[v[node][i]] ? arr[v[node][i]] : maxV;
			dfs(v[node][i], cnt + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int node1, node2;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> node1 >> node2;
		v[node1].push_back(node2);
	}
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		dfs(i, 1);
	}
	for (int i = 1; i <= n; i++)
		if (arr[i] == maxV)
			cout << i << " ";
	cout << '\n';
	return 0;
}