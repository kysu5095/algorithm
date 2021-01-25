// 보석 도둑

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, k, m, v;
pair<int, int> arr[300001];
int weight[300001];
priority_queue<int> pq;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	for (int i = 0; i < k; i++)
		cin >> weight[i];
	sort(arr, arr + n);
	sort(weight, weight + k);
	long long res = 0;
	int idx = 0;
	for (int i = 0; i < k; i++) {
		while (idx < n && arr[idx].first <= weight[i])
			pq.push(arr[idx++].second);
		if (!pq.empty()) {
			res += pq.top();
			pq.pop();
		}
	}
	cout << res << '\n';
	return 0;
}