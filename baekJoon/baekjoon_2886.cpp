// 자리 전쟁

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#define POW(A, B, C, D) pow(A-C, 2) + pow(B-D, 2)

using namespace std;

int r, c;
char arr[101][101];
bool map[101][101] = { {false,}, };
bool visited[10001] = { false, };
vector<pair<int, int>> chair, person;

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
		}
	}
	sort(d.begin(), d.end());
	int cnt = 0;
	int dis = 0;
	bool find = false;
	int pre_y, pre_x;
	for (pair<int, pair<int, int>> p : d) {
		if (visited[p.second.first]) continue;
		int y = chair[p.second.second].first;
		int x = chair[p.second.second].second;
		if (map[y][x]) continue;
		if (dis != p.first) {
			if (dis) map[pre_y][pre_x] = true;
			
			dis = p.first;
			find = false;
			pre_y = y;
			pre_x = x;
		}
		else {
			if (!find) cnt++;
			find = true;
		}
		visited[p.second.first] = true;
	}
	cout << cnt << '\n';
	return 0;
}