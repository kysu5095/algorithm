// 문제집

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int arr[32001] = { 0, };

void solve(vector<vector<int>> &v) {
	int val, len;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; i++) 
		if (!arr[i]) 
			pq.push(i);
	while (!pq.empty()) {
		val = pq.top();
		pq.pop();
		cout << val << " ";
		len = v[val].size();
		for (int i = 0; i < len; i++) {
			arr[v[val][i]]--;
			if (!arr[v[val][i]])
				pq.push(v[val][i]);
		}
	}
	cout << '\n';
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> n >> m;
	vector<vector<int>> v(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		arr[b]++;
	}
	solve(v);
	return 0;
}