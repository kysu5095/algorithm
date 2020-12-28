// 자기 방으로 돌아가기

#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

int n, res;
int start[201], finish[201], visited[201];

void go_back() {
	int idx, nidx, d;
	for (int i = 0; i < n; i++) {
		queue<int> q;
		q.push(start[i]);
		visited[start[i]] += 1;
		if (start[i] > finish[i]) d = -1;
		else if (start[i] < finish[i]) d = 1;
		else d = 0;

		while (!q.empty()) {
			idx = q.front();
			q.pop();
			nidx = idx + d;
			if(d != 0) visited[nidx]++;
			if (nidx == finish[i]) break;
			q.push(nidx);
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int test_case, s, d;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		res = 0;
		memset(visited, 0, sizeof(visited));
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s >> d;
			if (s % 2 == 0) start[i] = (s - 2) >> 1;
			else start[i] = (s - 1) >> 1;
			if (d % 2 == 0) finish[i] = (d - 2) >> 1;
			else finish[i] = (d - 1) >> 1;
		}
		go_back();
		for (int i = 0; i < 201; i++)
			res = max(res, visited[i]);
		cout << "#" << tc << " " << res << '\n';
	}

	return 0;
}