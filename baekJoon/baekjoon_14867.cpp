// 물통
// 2:50

#include <iostream>
#include <queue>
#include <set>

using namespace std;

int a, b, c, d;
set<int> s[100001];

int bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	s[0].insert(0);
	int y, x, ny, nx, len, t = 0;
	set<int>::iterator iter;
	while (!q.empty()) {
		len = q.size();
		while (len--) {
			x = q.front().first;
			y = q.front().second;
			q.pop();
			if (x == c && y == d) return t;
			iter = s[a].find(y);
			if (iter == s[a].end()) {
				s[a].insert(y);
				q.push(make_pair(a, y));
			}
			iter = s[x].find(b);
			if (iter == s[x].end()) {
				s[x].insert(b);
				q.push(make_pair(x, b));
			}
			iter = s[0].find(y);
			if (iter == s[0].end()) {
				s[0].insert(y);
				q.push(make_pair(0, y));;
			}
			iter = s[x].find(0);
			if (iter == s[x].end()) {
				s[x].insert(0);
				q.push(make_pair(x, 0));
			}
			if (x + y <= b) {
				iter = s[0].find(x + y);
				if (iter == s[0].end()) {
					s[0].insert(x + y);
					q.push(make_pair(0, x + y));
				}
			}
			else {
				iter = s[x - (b - y)].find(b);
				if (iter == s[x - (b - y)].end()) {
					s[x - (b - y)].insert(b);
					q.push(make_pair(x - (b - y), b));
				}
			}
			if (x + y <= a) {
				iter = s[x + y].find(0);
				if (iter == s[x + y].end()) {
					s[x + y].insert(0);
					q.push(make_pair(x + y, 0));
				}
			}
			else {
				iter = s[a].find(y - (a - x));
				if (iter == s[a].end()) {
					s[a].insert(y - (a - x));
					q.push(make_pair(a, y - (a - x)));
				}
			}
		}
		t++;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b >> c >> d;
	cout << bfs() << '\n';
	return 0;
}