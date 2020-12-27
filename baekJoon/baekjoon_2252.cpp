// 줄 세우기

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, a, b;
	int arr[32001] = { 0, };
	cin >> n >> m;
	vector<vector<int>> v(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		arr[b]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (!arr[i])
			q.push(i);
	int val;
	while (!q.empty()) {
		val = q.front();
		q.pop();
		cout << val << " ";

		for (int i = 0; i < v[val].size(); i++) {
			arr[v[val][i]]--;
			if (!arr[v[val][i]])
				q.push(v[val][i]);
		}
	}
	cout << '\n';
	return 0;
}