// 뱀

#include <stdio.h>
#include <deque>

using namespace std;

int n, k, l;
bool arr[101][101], visited[101][101];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
char command[10001];

int move() {
	deque<pair<int, int>> dq;
	dq.push_back(make_pair(1, 1));
	visited[1][1] = true;
	int y, x, d = 0, t = 0;
	while (true) {
		t++;
		y = dq.back().first;
		x = dq.back().second;
		y += dy[d];
		x += dx[d];
		if (!y || y > n || !x || x > n || visited[y][x]) return t;
		dq.push_back(make_pair(y, x));
		visited[y][x] = true;
		if (!arr[y][x]) {
			visited[dq.front().first][dq.front().second] = false;
			dq.pop_front();
		}
		else arr[y][x] = false;
		if (t > 10000) continue;
		if (command[t] == 'L') d = (d + 3) % 4;
		else if (command[t] == 'D') d = (d + 1) % 4;
	}
}

int main() {
	scanf("%d", &n);
	scanf(" %d", &k);
	while (k--) {
		int y, x;
		scanf(" %d %d", &y, &x);
		arr[y][x] = true;
	}
	scanf(" %d", &l);
	while (l--) {
		int t;
		char ch;
		scanf(" %d %c", &t, &ch);
		command[t] = ch;
	}
	printf("%d\n", move());
	return 0;
}