// 시험감독 //
/////////////

#include <iostream>

using namespace std;

int n, b, c;
long long cnt = 0;
int arr[1000001] = { 0, };

void find() {
	for (int i = 0; i < n; i++) {
		cnt++;
		int tmp = arr[i] - b;
		if (tmp <= 0) continue;

		if (tmp % c == 0) cnt += (tmp / c);
		else cnt += (tmp / c) + 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> b >> c;
	find();
	cout << cnt << '\n';

	return 0;
}

// #include<iostream>

// using namespace std;
// int course[1000001] = { 0, };
// int room, supervisor, deputy;
// long long min_supervisor = 0;

// void find() {
// 	for (int i = 0; i < room; i++) {
// 		int cnt_supervisor = 1;
// 		int cnt_deputy = 0;
// 		course[i] -= supervisor;
// 		if (course[i] > 0) {
// 			if (course[i] % deputy == 0)
// 				cnt_deputy = course[i] / deputy;
// 			else
// 				cnt_deputy = course[i] / deputy + 1;
// 		}
// 		min_supervisor += (cnt_supervisor + cnt_deputy);
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);
// 	cin >> room;
// 	for (int i = 0; i < room; i++) {
// 		cin >> course[i];
// 	}
// 	cin >> supervisor >> deputy;
// 	find();
// 	cout << min_supervisor << '\n';

// 	return 0;
// }