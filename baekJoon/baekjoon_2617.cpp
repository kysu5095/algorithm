// 구슬 찾기
// 3:40

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int n, m;
bool lvisited[100], rvisited[100], res[100] = { false, };
vector<int> lv[100], rv[100];

int ldfs(int node) {
	int val = 1;
	for (int i = 0; i < lv[node].size(); i++) {
		if (!lvisited[lv[node][i]]) {
			lvisited[lv[node][i]] = true;
			val += ldfs(lv[node][i]);
		}
	}
	return val;
}

int rdfs(int node) {
	int val = 1;
	for (int i = 0; i < rv[node].size(); i++) {
		if (!rvisited[rv[node][i]]) {
			rvisited[rv[node][i]] = true;
			val += rdfs(rv[node][i]);
		}
	}
	return val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int node1, node2, val;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> node1 >> node2;
		lv[node2].push_back(node1);
		rv[node1].push_back(node2);
	}
	val = (n + 1) / 2;
	for (int i = 1; i <= n; i++) {
		memset(lvisited, false, sizeof(lvisited));
		memset(rvisited, false, sizeof(rvisited));
		lvisited[i] = true;
		rvisited[i] = true;
		if (ldfs(i) > val)
			res[i] = true;
		if (rdfs(i) > val)
			res[i] = true;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (res[i])
			cnt++;
	cout << cnt << '\n';
	return 0;
}