// 마약수사대

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int graph[26];
bool drug[26], visited[26];
vector<int> v[26];

int bfs() {
	int cnt = 0;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (!graph[i] && !drug[i]) {
			q.push(i);
			visited[i] = true;
		}
	}
	int idx;
	while (!q.empty()) {
		idx = q.front();
		q.pop();
		for (int i = 0; i < v[idx].size(); i++) {
			if (drug[v[idx][i]]) continue;
			if (visited[v[idx][i]]) continue;
			q.push(v[idx][i]);
			visited[v[idx][i]] = true;
			cnt++;
		}
	}
	return cnt;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	char A, B;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> A >> B;
		v[(A - 'A')].push_back((B - 'A'));
		graph[(B - 'A')]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> A;
		drug[(A - 'A')] = true;
	}
	cout << bfs() << '\n';
	return 0;
}