#include <iostream>
#define ll long long
#define MAX 100000

using namespace std;

int m, k;
ll low = 0, high = 0, ans = 0;
ll arr[MAX + 1];

void input() {
	cin >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
		if (arr[i] > low) low = arr[i];
		high += arr[i];
	}
}

bool check(ll mid) {
	int cnt = 1;
	ll total = 0;
	for (int i = 0; i < m; i++) {
		if (total + arr[i] > mid) {
			cnt++;
			total = 0;
		}
		total += arr[i];
	}
	return cnt <= k;
}

void process() {
	while (low <= high) {
		ll mid = (low + high) / 2;
		if (check(mid)) {
			ans = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}
}

void output(int idx, ll total, int ck) {
	if (idx < 0) return;
	if (total + arr[idx] > ans || idx < ck) {
		output(idx - 1, arr[idx], ck - 1);
		cout << arr[idx] << " / ";
	}
	else {
		output(idx - 1, total + arr[idx], ck);
		cout << arr[idx] << " ";
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	input();
	process();
	output(m - 1, 0, k - 1);
	return 0;
}