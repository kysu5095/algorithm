// 빗물

#include <iostream>
#include <algorithm>

using namespace std;

int h, w, l, r, res = 0;
int arr[501];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> h >> w;
	for (int i = 0; i < w; i++)	cin >> arr[i];
	for (int i = 1; i < w - 1; i++) {
		l = r = 0;
		for (int j = i - 1; j >= 0; j--) l = max(l, arr[j]);
		for (int j = i + 1; j < w; j++) r = max(r, arr[j]);
		res += max(0, min(l, r) - arr[i]);
	}
	cout << res << '\n';
	return 0;
}