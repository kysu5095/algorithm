// 저택

#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <math.h>
#define ll long long

using namespace std;

int n, m, k;
vector<vector<int>> x_axis; // x축
vector<vector<int>> y_axis; // y축
class Point {
public:
	int y, x;
	ll t = LLONG_MAX; // 도착한 시간
};
vector<Point> v;

ll bfs(int first, int last) {
	queue<pair<int, bool>> q;
	// (x==1)축에 있는 모든 노드 추가하면서 방향 전환
	for (auto& p : x_axis[1]) {
		if (v[p].y == 1) continue;
		q.push(make_pair(p, false)); // false == y축(왼쪽, 오른쪽 뚤림)
		v[p].t = v[p].y;             // 도착시간(거리 + 1) >> 스위치를 바로 돌리기 때문에 +1해줌
	}
	if (first) { // 시작지점에 스위치 있음
	    // (y==1)축에 있는 모든 노드 추가하면서 방향 전환
		for (auto& p : y_axis[1]) {
			if (v[p].x == 1) continue;
			q.push(make_pair(p, true)); // true == x축(위, 아래 뚤림)
			v[p].t = v[p].x + 1;        // 도착시간(거리 + 1) >> 스위치를 바로 돌리기 때문에 +1 해줌
		}
	}

	int node, t, y, x, nt;
	bool flag;
	while (!q.empty()) {
		node = q.front().first;
		flag = q.front().second;
		q.pop();

		y = v[node].y;
		x = v[node].x;
		t = v[node].t;
		if (flag) { // x축(위, 아래 뚤림)
			for (auto& p : x_axis[x]) {
				if (v[p].y == y) continue;       // 현재 노드 칸
				nt = t + abs(v[p].y - y) + 1;    // 현재 시간 + 거리 + 1 >> 스위치를 바로 돌리기 때문에 +1해줌
				if (x == m && v[p].y == n) nt--; // 도착지점이면 스위치 누를 필요X
				if (v[p].t <= nt) continue;
				q.push(make_pair(p, false));
				v[p].t = nt;
			}
		}
		else { // y축(왼쪽, 오른쪽 뚤림)
			for (auto& p : y_axis[y]) {
				if (v[p].x == x) continue;       // 현재 노드 칸
				nt = t + abs(v[p].x - x) + 1;    // 현재 시간 + 거리 + 1 >> 스위치를 바로 돌리기 때문에 +1해줌
				if (y == n && v[p].x == m) nt--; // 도착지점이면 스위치 누를 필요X
				if (v[p].t <= nt) continue;
				q.push(make_pair(p, true));
				v[p].t = nt;
			}
		}
	}
	// 반환 조건
	if (v[last].t == LLONG_MAX) return -1;
	return v[last].t;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int y, x, first = 0, last = 0;
	cin >> m >> n >> k;
	x_axis.resize(m + 1);
	y_axis.resize(n + 1);
	v.resize(k + 2);
	for (int i = 1; i <= k; i++) {
		cin >> x >> y;
		// x, y축에 노드 번호 추가
		x_axis[x].push_back(i);
		y_axis[y].push_back(i);
		v[i] = { y, x, LLONG_MAX };
		if (x == 1 && y == 1) { // 시작지점에 스위치 있음
			first = i;
			v[i].t = 0;         // 시간 0으로 초기화
		}
		if (x == m && y == n) { // 도착지점에 스위치 있음
			last = i;
		}
	}
	if (!last) { // 도착지점에 스위치 없으면 노드 추가
		last = k + 1;
		x_axis[m].push_back(k + 1);
		y_axis[n].push_back(k + 1);
		v[k + 1] = { n, m, LLONG_MAX };
	}
	cout << bfs(first, last) << '\n';
	return 0;
}