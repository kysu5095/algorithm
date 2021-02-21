// 컨베이어 벨트 위의 로봇

#include <iostream>
#include <deque>

using namespace std;

int n, k;
deque<pair<bool ,int>> dq;

void rotate() {
	if (dq[n - 1].first) dq[n - 1].first = false;
	dq.push_front(dq.back());
	dq.pop_back();
}

void move() {
	for (int i = n - 2; i >= 0; i--) {
		if (dq[i].first && !dq[i + 1].first && dq[i + 1].second) {
			dq[i + 1].first = true;
			dq[i + 1].second--;
			if (!dq[i + 1].second) k--;
			dq[i].first = false;
		}
	}
}

void insert() {
	if (!dq[0].first && dq[0].second) {
		dq[0].first = true;
		dq[0].second--;
		if (!dq[0].second) k--;
	}
}

bool check() {
	int cnt = 0;
	for (int i = 0; i < n * 2; i++)
		if (!dq[i].second)
			cnt++;
	if (cnt >= k) return true;
	return false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> n >> k;
	for (int i = 0; i < n * 2; i++) {
		cin >> num;
		dq.push_back(make_pair(false, num));
	}
	int turn = 0;
	while (true) {
		turn++;
		rotate();
		move();
		insert();
		if (check()) break;
	}
	cout << turn << '\n';
	return 0;
}