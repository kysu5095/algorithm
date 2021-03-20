#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
char arr[51][51];
int map[51][51];

bool right(int& y, int& x, int& m) {
	for (int i = y; i < y + m; i++) {
		for (int j = x; j < x + m; j++) {
			if (i == n || j == n) return false;
			if (arr[i][j] == '0') return false;
		}
	}
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int max_val = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == '0') continue;
			int start = 1;
			int end = n;
			while (start <= end) {
				int mid = (start + end) >> 1;
				if (right(i, j, mid)) {
					map[i][j] = mid;
					max_val = max(max_val, mid);
					start = mid + 1;
				}
				else end = mid - 1;
			}
		}
	}
	int total = 0;
	vector<int> v(max_val+1, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			while (map[i][j]) {
				total++;
				v[map[i][j]--]++;
			}
		}
	}
	cout << "total: " << total << '\n';
	for (int i = 1; i < v.size(); i++) {
		cout << "size[" << i << "]: " << v[i] << '\n';
	}
	return 0;
}