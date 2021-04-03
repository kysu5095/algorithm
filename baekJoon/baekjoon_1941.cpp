// 소문난 칠공주

#include <stdio.h>
#include <string.h>
#include <queue>
#include <set>

using namespace std;

int res = 0;
char arr[5][5];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
bool visited[25];
set<int> s;

bool bfs() {
	queue<pair<int, int>> q;
	set<int>::iterator iter = s.begin();
	q.push(make_pair(*iter / 5, *iter % 5));
	memset(visited, false, sizeof(visited));
	visited[*iter] = true;
	int y, x, ny, nx, cnt = 1;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == 5 || nx < 0 || nx == 5 || visited[ny * 5 + nx]) continue;
			if (s.find(ny * 5 + nx) == s.end()) continue;
			q.push(make_pair(ny, nx));
			visited[ny * 5 + nx] = true;
			cnt++;
		}
	}
	if (cnt == 7) return true;
	else return false;
}

void dfs(int idx, int S, int Y) {
	if (S + Y == 7) {
		if (bfs()) res++;
		return;
	}
	for (int i = idx; i < 25; i++) {
		char ch = arr[i / 5][i % 5];
		if (ch == 'S') {
			s.insert(i);
			dfs(i + 1, S + 1, Y);
			s.erase(i);
		}
		else if (ch == 'Y' && Y < 3) {
			s.insert(i);
			dfs(i + 1, S, Y + 1);
			s.erase(i);
		}
	}
}

int main() {
	for (int i = 0; i < 5; i++) scanf("%s", arr[i]);
	dfs(0, 0, 0);
	printf("%d\n", res);
	return 0;
}