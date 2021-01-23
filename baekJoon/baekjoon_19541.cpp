// 역학 조사

#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool arr[100001], arr2[100001], answer[100001];
vector<int> v[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int k, person;
	bool flag;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> k;
		v[i].resize(k);
		for (int j = 0; j < k; j++)
			cin >> v[i][j];
	}
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr2[i] = arr[i];
		answer[i] = arr[i];
	}
	for (int i = m - 1; i >= 0; i--) {
		flag = false;
		for (int j = 0; j < v[i].size(); j++) {
			if (!arr[v[i][j]]) {
				flag = true;
				break;
			}
		}
		if (!flag) continue;

		for (int j = 0; j < v[i].size(); j++) {
			arr[v[i][j]] = false;
			answer[v[i][j]] = false;
		}
	}
	for (int i = 0; i < m; i++) {
		flag = false;
		for (int j = 0; j < v[i].size(); j++) {
			if (arr[v[i][j]]) {
				flag = true;
				break;
			}
		}
		if (!flag) continue;

		for (int j = 0; j < v[i].size(); j++)
			arr[v[i][j]] = true;
	}
	flag = false;
	for (int i = 1; i <= n; i++) {
		if (arr[i] != arr2[i]) {
			flag = true;
			break;
		}
	}
	if (flag) cout << "NO\n";
	else {
		cout << "YES\n";
		for (int i = 1; i <= n; i++)
			cout << answer[i] << " ";
	}
	return 0;
}