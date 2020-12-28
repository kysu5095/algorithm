// 프린터 큐 //
//////////////

#include <iostream>
#include <deque>

using namespace std;

int test_case;

int cal(deque<int> q, int target) {
	if (q.size() == 1) return 1;
	int cnt = 0;
	bool jud = false;
	int tmpTarget = target;
	while (!q.empty()) {
		int tmp = q.size();
		for (int i = 0; i < tmp; i++) {
			if (q.front() < q[i]) {
				if (tmpTarget == 0) tmpTarget = tmp - 1;
				else tmpTarget--;
				q.push_back(q.front());
				q.pop_front();
				break;
			}
			if (i == tmp - 1) jud = true;
		}
		if (jud) {
			if (tmpTarget == 0) return cnt + 1;
			q.pop_front();
			tmpTarget--;
			cnt++;
			jud = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, tmp;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		deque<int> q;
		cin >> n >> m;
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			q.push_back(tmp);
		}
		cout << cal(q, m) << '\n';
	}

	return 0;
}