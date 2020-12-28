// Contact

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

int arr[101];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	int n, start, from, to, len, sec;
	for (int tc = 1; tc <= 10; tc++) {
		cin >> n >> start;
		set<int> s[101];
		for (int i = 0; i < (n >> 1); i++) {
			cin >> from >> to;
			s[from].insert(to);
		}
		memset(arr, 0, sizeof(arr));
		queue<int> q;
		q.push(start);
		sec = 0;
		arr[start] = sec;
		int cur, next;
		set<int>::iterator iter;
		while (!q.empty()) {
			sec++;
			len = q.size();
			while (len--) {
				cur = q.front();
				q.pop();
				for (iter = s[cur].begin(); iter != s[cur].end(); iter++) {
					next = *iter;
					if (arr[next] == 0) {
						q.push(next);
						arr[next] = sec;
					}
				}
			}
		}
		for (int i = 100; i > 0; i--) {
			if (arr[i] == sec - 1) {
				cout << "#" << tc << " " << i << '\n';
				break;
			}
		}
	}
	return 0;
}