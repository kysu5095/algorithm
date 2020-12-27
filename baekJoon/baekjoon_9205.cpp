// 맥주 마시면서 걸어가기
// 2:00

#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>

using namespace std;

int n;
bool flag = false;
bool visited[101] = { false, };
vector<pair<int, int>> v;

void dfs(int &y, int &x, int &dy, int &dx) {
	if (flag) return;
	if (y == dy && x == dx) {
		flag = true;
		return;
	}
	int distance;
	int len = v.size();
	for (int i = 0; i < len; i++) {
		distance = abs(y - v[i].first) + abs(x - v[i].second);
		if (distance <= 1000 && !visited[i]) {
			visited[i] = true;
			dfs(v[i].first, v[i].second, dy, dx);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case;
	int sy, sx, dy, dx, i1, i2;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		flag = false;
		memset(visited, false, sizeof(visited));
		v.clear();
		cin >> n;
		for (int i = 0; i < n + 2; i++) {
			cin >> i1 >> i2;
			if (!i)
				sy = i1, sx = i2;
			else if (i == n + 1)
				dy = i1, dx = i2;
			else
				v.push_back(make_pair(i1, i2));
		}
		v.push_back(make_pair(dy, dx));
		dfs(sy, sx, dy, dx);
		if (flag) cout << "happy\n";
		else cout << "sad\n";
	}
	return 0;
}