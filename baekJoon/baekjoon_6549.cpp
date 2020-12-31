// 히스토그램에서 가장 큰 직사각형

#define ll long long
#include <iostream>
#include <algorithm>

using namespace std;

int n;
ll arr[100001];

ll search(int left, int right) {
	if (left == right) return arr[left];
	int mid = (left + right) >> 1;
	ll ret = max(search(left, mid), search(mid + 1, right));
	int lo = mid;
	int hi = mid + 1;
	ll height = min(arr[lo], arr[hi]);
	ret = max(ret, height * 2);

	while (lo > left || hi < right) {
		if (hi < right && (lo == left || arr[lo - 1] < arr[hi + 1])) height = min(height, arr[++hi]);
		else height = min(height, arr[--lo]);
		ret = max(ret, height * (hi - lo + 1));
	}
	return ret;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	while (true) {
		cin >> n;
		if (!n) break;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		cout << search(0, n - 1) << '\n';
	}
	return 0;
}