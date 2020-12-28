// 퇴사 //
/////////

#include <iostream>

using namespace std;

int n, maxP = 0;
class Day {
public:
	int t, p;
};
Day day[16];

void getMax(int val) {
	maxP = maxP > val ? maxP : val;
}

void work(int idx, int val) {
	if (idx > n) return;

	getMax(val);
	for (int i = idx; i < n; i++) {
		work(i + day[i].t, val + day[i].p);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t, p;
		cin >> t >> p;
		day[i].t = t;
		day[i].p = p;
	}
	work(0, 0);
	cout << maxP << '\n';

	return 0;
}

// #include <iostream>

// using namespace std;

// int n, max_value = 0;
// int arr[16][2] = { {0, }, };
// bool visited[16] = { false, };

// void resign(int cnt, int sum) {
// 	for (int i = cnt; i < n; i++) {
// 		if (!visited[i] && arr[i][0] + i - 1 < n) {
// 			visited[i] = true;
// 			sum += arr[i][1];
// 			max_value = max_value < sum ? sum : max_value;
// 			resign(i + arr[i][0], sum);
// 			visited[i] = false;
// 			sum -= arr[i][1];
// 		}
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cin >> n;
// 	for (int i = 0; i < n; i++) {
// 		cin >> arr[i][0] >> arr[i][1];
// 	}
// 	resign(0, 0);
// 	cout << max_value << '\n';

// 	return 0;
// }