// 3차원 농부

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int n, m, c1, c2;
int cow[500001], horse[500001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int test_case;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		cin >> n >> m >> c1 >> c2;
		for (int i = 0; i < n; i++)
			cin >> cow[i];
		for (int i = 0; i < m; i++)
			cin >> horse[i];
		sort(cow, cow + n);
		sort(horse, horse + m);
		int cidx = 0, hidx = 0, val, min_val = 200000001, cnt = 1;
		while (cidx != n && hidx != m) {
			val = abs(cow[cidx] - horse[hidx]);
			if (val == min_val) cnt++;
			else if (val < min_val) {
				min_val = val;
				cnt = 1;
			}
			if (cow[cidx] > horse[hidx]) hidx++;
			else if (cow[cidx] < horse[hidx]) cidx++;
			else cidx++, hidx++;
		}
		cout << "#" << tc << " " << abs(c1 - c2) + min_val << " " << cnt << '\n';
	}
	return 0;
}