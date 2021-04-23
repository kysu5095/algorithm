// RBY팡!

#include <iostream>
#define MAX 10005
using namespace std;

int n, ret = MAX;
int arr[10005];

void color_change(int idx) {
	int l = idx - 1;
	int r = idx + 1;
	int lcnt = 1, rcnt = 0, del = 0;
	int color = arr[idx];
	while (true) {
		while (l > 0) {
			if (arr[l] != color) break;
			lcnt++;
			l--;
		}
		while (r <= n) {
			if (arr[r] != color) break;
			rcnt++;
			r++;
		}
		if (lcnt + rcnt < 4) break;
		del += (lcnt + rcnt);
		
		if (arr[l] != arr[r]) break;
		color = arr[l];
		lcnt = 0;
		rcnt = 0;
	}
	if (del == 0) return;
	del = n - del;
	ret = ret > del ? del : ret;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int idx = 1; idx < n - 1; idx++) {
		for (int j = 1; j <= 3; j++) {
			if (arr[idx] == j) continue;
			int color = arr[idx];
			arr[idx] = j;
			color_change(idx);
			arr[idx] = color;
		}
	}
	if (ret == MAX) ret = n;
	cout << ret << '\n';
	return 0;
}