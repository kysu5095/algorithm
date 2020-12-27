// 임계경로
// 2:40

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int arr[10001] = { 0, };
int arr2[10001] = { 0, };

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int start, last, t;
	cin >> n >> m;
	vector<vector<pair<int, int>>> v1(n + 1);
	vector<vector<pair<int, int>>> v2(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> start >> last >> t;
		v1[start].push_back(make_pair(last, t));
		v2[last].push_back(make_pair(start, t));
		arr[last]++;
	}
	cin >> start >> last;

	int val, len, res = 0;
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		val = q.front();
		q.pop();
		len = v1[val].size();
		for (int i = 0; i < len; i++) {
			arr[v1[val][i].first]--;
			arr2[v1[val][i].first] = max(arr2[v1[val][i].first], arr2[val] + v1[val][i].second);
			if (!arr[v1[val][i].first])
				q.push(v1[val][i].first);
		}
	}
	cout << arr2[last] << '\n';

	q.push(last);
	while (!q.empty()) {
		val = q.front();
		q.pop();
		len = v2[val].size();
		for (int i = 0; i < len; i++) {
			if (arr2[val] - v2[val][i].second == arr2[v2[val][i].first]) {
				res++;
				q.push(v2[val][i].first);
			}
		}
	}
	cout << res << '\n';
	return 0;
}