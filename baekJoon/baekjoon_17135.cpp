// 캐슬 디펜스

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <limits.h>
#define distance(y1,x1,y2,x2) abs(y1-y2)+abs(x1-x2)

using namespace std;

int n, m, D, shot = 0;
int position[3];
vector<pair<bool, pair<int, int>>> origin;

class ARCHER {
public:
	int idx, d = INT_MAX, x = INT_MAX;
};

int game() {
	int kill = 0;
	int len = origin.size();
	vector<pair<bool, pair<int, int>>> v = origin;
	while (len) {
		ARCHER archer[3];
		for (int i = 0; i < v.size(); i++) {
			if (!v[i].first) continue;
			int y = v[i].second.first;
			int x = v[i].second.second;
			for (int j = 0; j < 3; j++) {
				int d = distance(y, x, n, position[j]);
				if (d <= D) {
					if (d < archer[j].d || (d == archer[j].d && x < archer[j].x)) {
						archer[j].idx = i;
						archer[j].d = d;
						archer[j].x = x;
					}
				}
			}
		}

		for (int i = 0; i < 3; i++) {
			if (archer[i].d == INT_MAX) continue;
			if (!v[archer[i].idx].first) continue;
			v[archer[i].idx].first = false;
			len--;
			kill++;
		}

		for (int i = 0; i < v.size(); i++) {
			if (!v[i].first) continue;
			v[i].second.first++;
			if (v[i].second.first == n) {
				v[i].first = false;
				len--;
			}
		}
	}
	return kill;
}

void dfs(int idx, int cnt) {
	if (cnt == 3) {
		shot = max(shot, game());
		return;
	}
	for (int i = idx; i < m; i++) {
		position[cnt] = i;
		dfs(i + 1, cnt + 1);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int val;
	cin >> n >> m >> D;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> val;
			if (val) origin.push_back(make_pair(true, make_pair(i, j)));
		}
	}
	dfs(0, 0);
	cout << shot << '\n';
	return 0;
}