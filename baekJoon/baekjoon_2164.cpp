// 카드2
// 1:35

#include <iostream>
#include <queue>

using namespace std;

int n;
queue<int> q;

int game() {
	while (q.size() != 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}
	return q.front();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		q.push(i);
	cout << game() << '\n';
	return 0;
}