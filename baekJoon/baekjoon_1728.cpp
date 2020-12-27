// 구슬 굴리기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[502][502];
vector<pair<int, int>> v;

bool check(int& init_val, int& gap) {
	for (int i = 2; i < n + 1; i++) {
		for (int j = 0; j < n; j++) {
			if (init_val + (i * gap) == arr[i][j]) break;
			if (j == n - 1) return false;
		}
	}
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int gap;
	cin >> n;
	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			gap = arr[1][j] - arr[0][i];
			if (check(arr[0][i], gap)) {
				v.push_back(make_pair(arr[0][i], gap));
				break;
			}
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second << '\n';
	return 0;
}