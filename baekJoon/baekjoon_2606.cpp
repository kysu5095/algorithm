// 바이러스 //
/////////////

#include <iostream>
#include <vector>

using namespace std;

int n, k;
int arr[101];
vector<int> v[101];

int get_parent(int x) {
	if (arr[x] == x) return x;
	arr[x] = get_parent(arr[x]);
	return arr[x];
}

void merge_parent(int y, int x) {
	y = get_parent(y);
	x = get_parent(x);
	if (y == x) return;
	if (y > x) arr[y] = x;
	else arr[x] = y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int node1, node2;
	for (int i = 1; i <= 100; i++)
		arr[i] = i;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> node1 >> node2;
		merge_parent(node1, node2);
	}
	int cnt = 0;
	for (int i = 2; i <= n; i++)
		if (get_parent(arr[i]) == 1)
			cnt++;
	cout << cnt << '\n';
	return 0;
}

// #include <iostream>

// using namespace std;

// int matrix[101][101] = {{0, }};
// bool visited[101] = {false, };
// int sum = 0;

// void dfs(const int edge, const int n){
//     for(int i = 1; i <= n; i++){
//         if(matrix[edge][i] && !visited[i]){
//             visited[i] = true;
//             dfs(i, n);
//             sum++;
//         }
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int n, pair, first, second;
//     cin >> n >> pair;
//     for(int i = 0; i < pair; i++){
//         cin >> first >> second;
//         matrix[first][second] = 1;
//         matrix[second][first] = 1;
//     }
//     visited[1] = true;
//     dfs(1, n);
//     cout << sum << '\n';

//     return 0;
// }