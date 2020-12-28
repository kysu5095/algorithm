// 숨바꼭질3

#include <iostream>
#include <limits.h>
#include <queue>

using namespace std;

int n, k;
int arr[100001];

int bfs() {
	int v, t, len, max_v = INT_MAX;
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));
	arr[n] = 0;
	while (!q.empty()) {
		v = q.front().first;
		t = q.front().second;
		q.pop();
		if (v == k) max_v = max_v > t ? t : max_v;
		if (v - 1 >= 0 && arr[v - 1] > t + 1) {
			arr[v - 1] = t + 1;
			q.push(make_pair(v - 1, t + 1));
		}
		if (v + 1 <= 100000 && arr[v + 1] > t + 1) {
			arr[v + 1] = t + 1;
			q.push(make_pair(v + 1, t + 1));
		}
		if (v << 1 <= 100000 && arr[v << 1] > t) {
			arr[v << 1] = t;
			q.push(make_pair(v << 1, t));
		}
	}
	return max_v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i <= 100000; i++)
		arr[i] = INT_MAX;
	cin >> n >> k;
	cout << bfs() << '\n';
	return 0;
}