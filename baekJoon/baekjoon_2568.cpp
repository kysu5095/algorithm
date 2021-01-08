// 전깃줄 - 2

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int n;
int lis[100001], cache[100001];
bool visited[100001] = { false, };

class Point {
public:
	int A, B;
	bool operator < (const Point& P) const {
		return B < P.B;
	}
};
vector<Point> v;

int LIS(int start, int last, int& val) {
	while (start < last) {
		int mid = (start + last) >> 1;
		if (lis[mid] < val) start = mid + 1;
		else last = mid;
	}
	return last;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].A >> v[i].B;
	sort(v.begin(), v.end());
	int idx = 0;
	lis[idx] = v[idx].A;
	for (int i = 1; i < n; i++) {
		if (lis[idx] < v[i].A) {
			lis[++idx] = v[i].A;
			cache[i] = idx;
		}
		else {
			int tmp_idx = LIS(0, idx, v[i].A);
			lis[tmp_idx] = v[i].A;
			cache[i] = tmp_idx;
		}
	}
	cout << n - (idx + 1) << '\n';

	for (int i = n - 1; i >= 0; i--) {
		if (idx == cache[i]) {
			visited[i] = true;
			idx--;
		}
	}
	vector<int> v2;
	for (int i = 0; i < n; i++)
		if (!visited[i])
			v2.push_back(v[i].A);
	sort(v2.begin(), v2.end());
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << '\n';
	return 0;
}