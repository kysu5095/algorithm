// MooTube(Silver)

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int n, q;
bool visited[5001];
vector<pair<int, int>> v[5001];

int bfs(int start, int usado) {
	memset(visited, false, sizeof(visited));
	queue<int> q;
	q.push(start);
	visited[start] = true;
	int len, cnt = 0;
	while (!q.empty()) {
		start = q.front();
		q.pop();
		len = v[start].size();
		for (int i = 0; i < len; i++) {
			int nextNode = v[start][i].first;
			int nextUsado = v[start][i].second;
			if (!visited[nextNode] && usado <= nextUsado) {
				visited[nextNode] = true;
				q.push(nextNode);
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int start, last, usado;
	cin >> n >> q;
	for (int i = 0; i < n - 1; i++) {
		cin >> start >> last >> usado;
		v[start].push_back(make_pair(last, usado));
		v[last].push_back(make_pair(start, usado));
	}
	for (int i = 0; i < q; i++) {
		cin >> usado >> start;
		cout << bfs(start, usado) << '\n';
	}
	return 0;
}