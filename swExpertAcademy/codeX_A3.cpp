// 회전초밥 //
/////////////

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int n, d, k, c;
int maxSushi = 0;
vector<int> v;
deque<int> dq;

void cal(int maxSize, int jud) {
	if (jud == 0) maxSize++;
	maxSushi = maxSushi < maxSize ? maxSize : maxSushi;
}

void rotation() {
	int tmpSushi = 0;
	int jud = 0;
	int arr[3001] = { 0, };

	for (int i = 0; i < k - 1; i++) {
		if (arr[v[i]] == 0) tmpSushi++;
		if (v[i] == c) jud++;
		
		dq.push_back(v[i]);
		arr[v[i]]++;
	}

	for (int i = 0; i < n; i++) {
		int idx = (k - 1 + i) % n;
		// push
		if (arr[v[idx]] == 0) tmpSushi++;
		if (v[idx] == c) jud++;

		dq.push_back(v[idx]);
		arr[v[idx]]++;

		// calculate
		cal(tmpSushi, jud);

		// pop
		if (v[i] == c) jud--;
		if (arr[dq.front()] == 1) tmpSushi--;
		arr[dq.front()]--;
		dq.pop_front();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	rotation();

	cout << maxSushi << '\n';

	return 0;
}