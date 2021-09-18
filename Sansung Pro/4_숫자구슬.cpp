#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N, M, low = 0, high = 0;
int arr[304];

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] > low) low = arr[i];
		high += arr[i];
	}
}

bool check(int mid) {
	int cnt = 1, total = 0;
	for (int i = 0; i < N; i++) {
		if (total + arr[i] > mid) {
			cnt++;
			total = 0;
		}
		total += arr[i];
	}
	return cnt <= M;
}

int process() {
	int res = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (check(mid)) {
			res = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}
	return res;
}

void output(int res) {
	cout << res << '\n';
	int cnt = 0, total = 0;
	for (int i = 0; i <= N; i++) {
		if (total + arr[i] > res || N - i < M) {
			cout << cnt << " ";
			cnt = 0;
			total = 0;
			M--;
		}
		total += arr[i];
		cnt++;
	}
	cout << '\n';
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	input();
	int res = process();
	output(res);
	return 0;
}