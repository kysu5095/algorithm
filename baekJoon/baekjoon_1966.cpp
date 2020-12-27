// 프린터 큐
// 5:30

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		queue<int> q;
		priority_queue<int> pq;
		int n, m, val, t = 1;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			q.push(i);
			pq.push(arr[i]);
		}
		while (true) {
			val = q.front();
			if (arr[val] < pq.top()) {
				q.push(val);
				q.pop();
			}
			else if (val == m)
				break;
			else {
				q.pop();
				pq.pop();
				t++;
			}
		}
		cout << t << '\n';
	}
	return 0;
}