// 양팔저울

#include <iostream>
#include <math.h>

using namespace std;

int n, m;
int arr[31];
int arr2[7];
bool visited[31][30 * 500 + 1] = { {false,}, };

void dfs(int cnt, int weight) {
	if (visited[cnt][weight]) return;
	visited[cnt][weight] = true;
	if (cnt == n) return;
	/* 사용 x */
	dfs(cnt + 1, weight);
	/* 추 더하기 */
	dfs(cnt + 1, weight + arr[cnt]);
	/* 추 빼기 */
	dfs(cnt + 1, abs(weight - arr[cnt]));
}


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int input;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> m;
	dfs(0, 0);
	for (int i = 0; i < m; i++) {
		cin >> input;
		if (input > 15000) cout << "N ";
		else if (visited[n][input]) cout << "Y ";
		else cout << "N ";
	}
	return 0;
}