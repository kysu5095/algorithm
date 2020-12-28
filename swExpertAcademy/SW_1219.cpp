// D4 : 길찾기

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int test_case, l;
bool visited[101];

int bfs(vector<int> v[101]) {
	queue<int> q;
	q.push(0);
	visited[0] = true;
	int node, len;
	while (!q.empty()) {
		node = q.front();
		q.pop();
		if (node == 99) return 1;

		len = v[node].size();
		for (int i = 0; i < len; i++) {
			if (!visited[v[node][i]]) {
				visited[v[node][i]] = true;
				q.push(v[node][i]);
			}
		}
	}
	return 0;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	int TC = 10;
	while (TC--) {
		vector<int> v[101];
		memset(visited, false, sizeof(visited));
		cin >> test_case >> l;
		for (int i = 0; i < l; i++) {
			int node1, node2;
			cin >> node1 >> node2;
			v[node1].push_back(node2);
		}
		cout << "#" << test_case << " " << bfs(v) << '\n';
	}
}