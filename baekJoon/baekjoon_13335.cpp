// 트럭
// 5:15

#include <iostream>
#include <queue>

using namespace std;

int n, w, l;
int arr[1001] = { 0, };
queue<int> q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> w >> l;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	int total = 0, t = 0;
	for (int i = 1; i <= n; i++) {
		while (true) {
			if (q.size() == w) {
				total -= q.front();
				q.pop();
			}
			if (total + arr[i] <= l) break;
			t++;
			q.push(0);
		}
		q.push(arr[i]);
		total += arr[i];
		t++;
	}
	cout << t + w << '\n';
	return 0;
}