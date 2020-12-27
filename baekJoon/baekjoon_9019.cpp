// DSLR
// 1:00

#include <iostream>
#include <queue>
#include <string>
#include <string.h>

using namespace std;

int test_case, b;
bool visited[10000];

class Point {
public:
	int num;
	string s;
};

string bfs(int _num) {
	queue<Point> q;
	q.push({ _num, "" });
	visited[_num] = true;
	int num;
	while (!q.empty()) {
		num = q.front().num;
		string s = q.front().s;
		if (num == b) return s;

		// D
		num <<= 1;
		if (num >= 10000) num %= 10000;
		if (!visited[num]) {
			visited[num] = true;
			q.push({ num, s + "D" });
		}
		// S
		num = q.front().num;
		num -= 1;
		if (num < 0) num = 9999;
		if (!visited[num]) {
			visited[num] = true;
			q.push({ num, s + "S" });
		}
		// L
		num = ((q.front().num % 1000) * 10) + (q.front().num / 1000);
		if (!visited[num]) {
			visited[num] = true;
			q.push({ num, s + "L" });
		}
		// R
		num = (q.front().num / 10) + ((q.front().num % 10) * 1000);
		if (!visited[num]) {
			visited[num] = true;
			q.push({ num, s + "R" });
		}
		q.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		memset(visited, false, sizeof(visited));
		cin >> a >> b;
		cout << bfs(a) << '\n';
	}
	return 0;
}