// 수족관 1

#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#define MAX 40002
#define pp pair<pair<int,int>,pair<int,int>> 

using namespace std;

int n, k, limit, total = 0;
int arr[MAX][2];

bool comp(pp p1, pp p2) {
	if (p1.first.second < p2.second.second) return true;
	else if (p1.first.second > p2.second.second) return false;
	else return p1.first.first < p2.first.first;
}

void fill_arr(int &y1, int &x1, int &y2, int &x2) {
	for (int i = x1; i < x2; i++)
		arr[i][0] = y1;
}

void aquarium(vector<pp> &v) {
	int y1, x1, y2, x2, half, height;
	int len = v.size();
	for (int i = 0; i < len; i++) {
		x1 = v[i].first.first,  y1 = v[i].first.second;
		x2 = v[i].second.first, y2 = v[i].second.second;

		half = (x1 + x2) >> 1;
		/* left */
		height = arr[half][0];
		for (int x = half; x >= 0; x--) {
			height = min(height, arr[x][0]);
			arr[x][1] = max(arr[x][1], height);
		}
		/* right */
		height = arr[half][0];
		for (int x = half + 1; x < limit; x++) {
			height = min(height, arr[x][0]);
			arr[x][1] = max(arr[x][1], height);
		}
	}
	for (int x = 0; x < limit; x++)
		total += arr[x][0] - arr[x][1];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	memset(arr, 0, sizeof(arr));
	int y, x, by = -1, bx = -1;
	cin >> n;
	while (n--) {
		cin >> x >> y;
		if (y == by) fill_arr(by, bx, y, x);
		bx = x, by = y;
		limit = x;
	}

	cin >> k;
	vector<pp> v;
	v.reserve(k);
	while (k--) {
		cin >> x >> y >> bx >> by;
		v.push_back(make_pair(make_pair(x, y), make_pair(bx, by)));
	}
	sort(v.begin(), v.end(), comp);
	aquarium(v);
	cout << total << '\n';
	return 0;
}