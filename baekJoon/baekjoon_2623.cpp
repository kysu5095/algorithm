// 음악프로그램

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n, m;
int arr[1001] = { 0, };
vector<int> v[1001];
queue<int> q, s;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int input, num, pre;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> input;
		for (int j = 0; j < input; j++) {
			cin >> num;
			q.push(num);
		}
		pre = q.front(); q.pop();
		while (!q.empty()) {
			num = q.front();
			q.pop();
			v[pre].push_back(num);
			arr[num]++;
			pre = num;
		}
	}

	for (int i = 1; i <= n; i++)
		if (!arr[i])
			q.push(i);
	while (!q.empty()) {
		num = q.front();
		q.pop();
		s.push(num);
		for (auto iter : v[num]) {
			arr[iter]--;
			if (!arr[iter])
				q.push(iter);
		}
	}
	if (s.size() != n) {
		cout << "0\n";
	}
	else {
		while (!s.empty()) {
			num = s.front();
			s.pop();
			cout << num << '\n';
		}
	}
	return 0;
}