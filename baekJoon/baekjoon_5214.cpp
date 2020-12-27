// 환승
// 4:10

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int n, k, m;
bool visited[101005] = { false, };
set<int> s[101005];

int bfs() {
	queue<int> q;
	q.push(1);
	visited[1] = true;
	int station, len, t = 1;
	set<int>::iterator iter, iter2;
	while (!q.empty()) {
		len = q.size();
		while (len--) {
			station = q.front();
			q.pop();
			if (station == n) 
				return t;
			iter = s[station].begin();
			while (iter != s[station].end()) {
				if (!visited[*iter]) {
					visited[*iter] = true;
					iter2 = s[*iter].begin();
					while (iter2 != s[*iter].end()) {
						if (!visited[*iter2]) {
							visited[*iter2] = true;
							q.push(*iter2);
						}
						iter2++;
					}
				}
				iter++;
			}
		}
		t++;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int input;
	cin >> n >> k >> m;
	for (int i = 100001; i < 100001 + m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> input;
			s[i].insert(input);
			s[input].insert(i);
		}
	}
	cout << bfs() << '\n';
	return 0;
}