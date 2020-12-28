// 숨바꼭질 4
// 3:15

#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int arr[100001];
bool visited[100001] = { false, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i <= 100000; i++)
		arr[i] = INT_MAX;
	cin >> n >> k;
	vector<int> v;
	v.reserve(100000);
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));
	arr[n] = n;
	visited[n] = true;

	int idx, t;
	while (!q.empty()) {
		idx = q.front().first;
		t = q.front().second;
		q.pop();
		if (idx == k) {
			while (idx != n) {
				v.push_back(idx);
				idx = arr[idx];
			}
			break;
		}
		if (idx - 1 >= 0 && !visited[idx - 1]) {
			q.push(make_pair(idx - 1, t + 1));
			visited[idx - 1] = true;
			arr[idx - 1] = idx;
		}
		if (idx + 1 <= 100000 && !visited[idx + 1]) {
			q.push(make_pair(idx + 1, t + 1));
			visited[idx + 1] = true;
			arr[idx + 1] = idx;
		}
		if (idx << 1 > 0 && idx << 1 <= 100000 && !visited[idx << 1]) {
			q.push(make_pair(idx << 1, t + 1));
			visited[idx << 1] = true;
			arr[idx << 1] = idx;
		}
	}
	v.push_back(n);
	cout << t << '\n';
	for (int i = v.size() - 1; i >= 0; i--)
		cout << v[i] << " ";
	cout << '\n';
	return 0;
}