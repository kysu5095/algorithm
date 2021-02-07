// 자리 전쟁

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#define POW(A, B, C, D) pow(A-C, 2) + pow(B-D, 2)

using namespace std;

int r, c;
char arr[101][101];
int cnt_arr[101][101][2] = { { {false, }, }, };
bool visited[10001] = { false, };
vector<pair<int, int>> chair, person;
map<int, int> m;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> arr[i];
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'X') person.push_back(make_pair(i, j));
			else if (arr[i][j] == 'L') chair.push_back(make_pair(i, j));
		}
	}
	vector<pair<int, pair<int, int>>> d;
	for (int i = 0; i < (int)person.size(); i++) {
		for (int j = 0; j < (int)chair.size(); j++) {
			int distance = POW(person[i].first, person[i].second, chair[j].first, chair[j].second);
			d.push_back(make_pair(distance, make_pair(i, j)));
			m[distance]++;
		}
	}
	sort(d.begin(), d.end());

	int res = 0;
	int idx = 0;
	set<pair<int, int>> s;
	set<pair<int, int>>::iterator s_iter;
	map<int, int>::iterator m_iter;
	for (m_iter = m.begin(); m_iter != m.end(); m_iter++) {
		s.clear();
		int len = m_iter->second;
		while (len--) {
			int num = d[idx].second.first;
			if (visited[num]) {
				idx++;
				continue;
			}
			int y = chair[d[idx].second.second].first;
			int x = chair[d[idx].second.second].second;
			s.insert(make_pair(y, x));
			if (cnt_arr[y][x][0]) {
				idx++;
				continue;
			}
			visited[num] = true;
			if (cnt_arr[y][x][1]++ == 1) res++;
			idx++;
		}
		for (s_iter = s.begin(); s_iter != s.end(); s_iter++) {
			int y = s_iter->first;
			int x = s_iter->second;
			cnt_arr[y][x][0]++;
		}
	}
	cout << res << '\n';
	return 0;
}