// 숫자 고르기
// 1:55

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[101];
bool visited[101];
vector<int> v;

void dfs(int s_node, int c_node) {
	if (visited[c_node]) {
		if (s_node == c_node)
			v.push_back(s_node);
	}
	else {
		visited[c_node] = true;
		dfs(s_node, arr[c_node]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		dfs(i, i);
	}
	sort(v.begin(), v.end());
	int len = v.size();
	cout << len << '\n';
	for (int i = 0; i < len; i++)
		cout << v[i] << '\n';
	return 0;
}