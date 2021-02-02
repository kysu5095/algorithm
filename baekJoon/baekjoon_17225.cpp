// 세훈이의 선물가게

#include <iostream>
#include <queue>
#include <vector>
#define MAX 90000

using namespace std;

int A, B, n;
queue<pair<int, int>> qa, qb;
vector<int> va, vb;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int t, cnt;
	char ch;
	cin >> A >> B >> n;
	for (int i = 0; i < n; i++) {
		cin >> t >> ch >> cnt;
		if (ch == 'B') qa.push(make_pair(t, cnt));
		else qb.push(make_pair(t, cnt));
	}
	int idx = 1;
	int a_t = qa.front().first;
	int b_t = qb.front().first;
	int a_cnt = qa.front().second;
	int b_cnt = qb.front().second;
	bool a_flag;
	while (!qa.empty() || !qb.empty()) {
		a_flag = false;
		if (a_t <= b_t) {
			va.push_back(idx++);
			a_cnt--;
			a_flag = true;
		}
		if (a_t >= b_t) {
			vb.push_back(idx++);
			b_t += B;
			b_cnt--;
		}
		if (a_flag) a_t += A;
		if (!a_cnt && !qa.empty()) {
			qa.pop();
			if(qa.empty()){
				a_t = MAX;
			}
			else {
				if (qa.front().first > a_t)
					a_t = qa.front().first;
				a_cnt = qa.front().second;
			}
		}
		if (!b_cnt && !qb.empty()) {
			qb.pop();
			if (qb.empty()) {
				b_t = MAX;
			}
			else {
				if (qb.front().first > b_t)
					b_t = qb.front().first;
				b_cnt = qb.front().second;
			}
		}
	}
	cout << va.size() << '\n';
	for (auto idx : va)
		cout << idx << " ";
	cout << '\n';
	cout << vb.size() << '\n';
	for (auto idx : vb)
		cout << idx << " ";
	cout << '\n';
	return 0;
}