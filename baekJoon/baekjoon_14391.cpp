// 종이 조각
// 3:00

#include <iostream>
#include <string>

using namespace std;

int n, m, res = 0;
int arr[5][5];
char c_arr[5][5];
bool visited[5][5];

void dfs(int y, int x) {
	if (y == n) {
		// true -> width   
		// false -> height
		int sum, total = 0;
		for (int i = 0; i < n; i++) {
			sum = 0;
			for (int j = 0; j < m; j++) {
				if (visited[i][j])
					sum = (sum * 10) + arr[i][j];
				else {
					total += sum;
					sum = 0;
				}
			}
			total += sum;
		}
		for (int j = 0; j < m; j++) {
			sum = 0;
			for (int i = 0; i < n; i++) {
				if (!visited[i][j])
					sum = (sum * 10) + arr[i][j];
				else {
					total += sum;
					sum = 0;
				}
			}
			total += sum;
		}
		res = res < total ? total : res;
		return;
	}
	if (x == m) {
		dfs(y + 1, 0);
		return;
	}
	visited[y][x] = true;
	dfs(y, x + 1);
	visited[y][x] = false;
	dfs(y, x + 1);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> c_arr[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = c_arr[i][j] - '0';
	dfs(0, 0);
	cout << res << '\n';
	return 0;
}