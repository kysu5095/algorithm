// 무선 단속 카메라

#include <iostream>
#include <algorithm>
#include <string.h>
#define MAX 1000000

using namespace std;

int n, k, cnt, res;
int arr[10001], dist[10001];
bool visited[(MAX * 2) + 1];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int test_case, input;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		res = 0;
		cnt = 0;
		memset(visited, false, sizeof(visited));
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> input;
			input += MAX;
			if (!visited[input]) {
				visited[input] = true;
				arr[cnt++] = input;
			}
		}
		sort(arr, arr + cnt);
		for (int i = 0; i < cnt - 1; i++)
			dist[i] = arr[i + 1] - arr[i];
		sort(dist, dist + cnt - 1);
		for (int i = 0; i < cnt - k; i++)
			res += dist[i];
		cout << "#" << tc << " " << res << '\n';
	}
	return 0;
}