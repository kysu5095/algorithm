// 이모티콘
// 3:20

#include <iostream>
#include <queue>

using namespace std;

int s;
bool visited[2001][2001] = { {false, }, };

int bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	visited[1][0] = true;
	int emoticon, clip, len, t = 0;
	while (!q.empty()) {
		len = q.size();
		while (len--) {
			emoticon = q.front().first;
			clip = q.front().second;
			q.pop();
			if (emoticon == s) return t;

			if (!visited[emoticon][emoticon]) {
				visited[emoticon][emoticon] = true;
				q.push(make_pair(emoticon, emoticon));
			}
			if (clip && emoticon <= 1000 && !visited[emoticon + clip][clip]) {
				visited[emoticon + clip][clip] = true;
				q.push(make_pair(emoticon + clip, clip));
			}
			if ((emoticon - 1) && !visited[emoticon - 1][clip]) {
				visited[emoticon - 1][clip] = true;
				q.push(make_pair(emoticon - 1, clip));
			}
		}
		t++;
	}
	return -1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	cout << bfs() << '\n';
	return 0;
}