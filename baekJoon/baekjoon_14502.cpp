// 연구소

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

int n, m, cnt = 0, res = 0;
int arr[9][9];
bool visited[9][9];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
std::vector<std::pair<int, int>> v, wall;

void bfs() {
	memset(visited, false, sizeof(visited));
	std::queue<std::pair<int, int>> q;
	for (int i = 0; i < v.size(); i++) {
		q.push(std::make_pair(v[i].first, v[i].second));
		visited[v[i].first][v[i].second] = true;
	}
	int cnt = wall.size() - 3;
	int y, x, ny, nx;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == n || nx < 0 || nx == m || visited[ny][nx] || arr[ny][nx]) continue;
			q.push(std::make_pair(ny, nx));
			visited[ny][nx] = true;
			cnt--;
		}
		if (res >= cnt) return;
	}
	res = std::max(res, cnt);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2) v.push_back(std::make_pair(i, j));
			else if (!arr[i][j]) wall.push_back(std::make_pair(i, j));
		}
	}
	std::vector<int> tmp(wall.size(), 0);
	tmp[wall.size() - 3] = 1;
	tmp[wall.size() - 2] = 1;
	tmp[wall.size() - 1] = 1;
	do {
		for (int i = 0; i < wall.size(); i++) if (tmp[i]) arr[wall[i].first][wall[i].second] = 1;
		bfs();
		for (int i = 0; i < wall.size(); i++) if (tmp[i]) arr[wall[i].first][wall[i].second] = 0;
	} while (std::next_permutation(tmp.begin(), tmp.end()));

	printf("%d\n", res);
	return 0;
}

// // 연구소 //
// ///////////

// //////////////////////////////////////////////////////////////////////
// //		1번 코드 : 처음 푼 코드(36ms)
// //		2번 코드 : 복습 후 코드(24ms) >> stay전역 변수로 계산하는 시간 줄임
// //////////////////////////////////////////////////////////////////////

// // 0 -> 빈칸(3~), 1 -> 벽, 2 -> 바이러스(2~10)
// #include <iostream>
// #include <cstring>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int n, m;
// int maxCnt = 0;
// int arr[8][8] = { {-1, } };     // 기존배열
// int arr2[8][8] = { {-1, } };    // 벽을 세운 새로운 배열
// bool visited[8][8] = { {false, } }; // 벽 세우기

// class Point {
// public:
// 	int x, y;
// };
// Point p[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
// vector<Point> v; // 지나갈 수 있는 통로 저장 벡터 ('0')
// vector<Point> q;  // 바이러스 저장 큐

// void dfs(int x, int y); // 바이러스 퍼트리기
// void makeWall(int idx, int cnt); // 벽을 만들자
// void copyArr(void); // 기존 배열과 동일한 배열 >> 이 copy배열에 벽을 세울거임

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);

// 	cin >> n >> m;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			cin >> arr[i][j];
// 			if (arr[i][j] == 0) v.push_back({ j, i });
// 			if (arr[i][j] == 2) q.push_back({ j, i });
// 		}
// 	}
// 	makeWall(0, 0);
// 	cout << maxCnt << '\n';

// 	return 0;
// }

// void copyArr(void) {
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			arr2[i][j] = arr[i][j];
// 		}
// 	}
// }

// void makeWall(int idx, int cnt) {
// 	if (cnt == 3) {
// 		int Acnt = 0;
// 		copyArr();
// 		for (int i = 0; i < q.size(); i++) { // 병균 퍼트리기
// 			dfs(q[i].x, q[i].y);
// 		}
// 		for (int i = 0; i < n; i++) { // 안전한 곳 찾기
// 			for (int j = 0; j < m; j++) {
// 				if (arr2[i][j] == 0) Acnt++;
// 			}
// 		}

// 		maxCnt = max(maxCnt, Acnt);
		
// 		return;
// 	}

// 	for (int i = idx; i < v.size(); i++) {
// 		int nextX = v[i].x;
// 		int nextY = v[i].y;

// 		arr[nextY][nextX] = 1;
// 		makeWall(i + 1, cnt + 1);
// 		arr[nextY][nextX] = 0;
// 	}
// }

// void dfs(int x, int y) {
// 	for (int i = 0; i < 4; i++) {
// 		int nextX = x + p[i].x;
// 		int nextY = y + p[i].y;

// 		if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n) {
// 			if (arr2[nextY][nextX] == 0) {
// 				arr2[nextY][nextX] = 2;
// 				dfs(nextX, nextY);
// 			}
// 		}
// 	}
// }

// // 복습_연구소 //
// ////////////////

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int n, m, stay;
// int stayArea = 0;
// int arr[9][9];
// int copyArr[9][9];

// class Point{
// 	public:
// 		int x, y;
// };
// Point p[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
// vector<Point> wall;
// vector<Point> warm;

// void copyAray(){
// 	for(int i = 0; i < n; i++){
// 		for(int j = 0; j < m; j++){
// 			copyArr[i][j] = arr[i][j];
// 		}
// 	}
// }

// void warmDfs(int x, int y){
// 	if(stay == 0) return;

// 	for(int i = 0; i < 4; i++){
// 		int nx = x + p[i].x;
// 		int ny = y + p[i].y;

// 		if(nx >= 0 && nx < m && ny >= 0 && ny < n){
// 			if(copyArr[ny][nx] == 0){
// 				copyArr[ny][nx] = 2;
// 				stay--;
// 				warmDfs(nx, ny);
// 			}
// 		}
// 	}
// }

// void dfs(int cnt, int idx){
// 	if(cnt == 3){
// 		copyAray();
// 		int tmp = stay;
// 		for(int i = 0; i < warm.size(); i++){
// 			warmDfs(warm[i].x, warm[i].y);
// 		}
// 		stayArea = max(stayArea, stay);
// 		stay = tmp;
// 	}
// 	for(int i = idx; i < wall.size(); i++){
// 			arr[wall[i].y][wall[i].x] = 1;
// 			stay--;
// 			dfs(cnt + 1, i + 1);
// 			arr[wall[i].y][wall[i].x] = 0;
// 			stay++;
// 	}
// }

// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);

// 	cin >> n >> m;
// 	for(int i = 0; i < n; i++){
// 		for(int j = 0; j < m; j++){
// 			cin >> arr[i][j];
// 			if(arr[i][j] == 0) wall.push_back({j, i});
// 			if(arr[i][j] == 2) warm.push_back({j, i});
// 		}
// 	}
// 	stay = (n * m) - wall.size() - warm.size();
// 	dfs(0, 0);

// 	cout << stayArea << '\n';

// 	return 0;
// }

// #include <iostream>
// #include <queue>
// #include <string.h>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int n, m, res = 0;
// int arr[9][9];
// bool visited[9][9];
// int dy[4] = { 0, 0, 1, -1 };
// int dx[4] = { 1, -1, 0, 0 };
// vector<pair<int, int>> v;

// void bfs() {
// 	int y, x, ny, nx, len, cnt = 0;
// 	queue<pair<int, int>> q;
// 	len = v.size();
// 	for (int i = 0; i < len; i++) {
// 		y = v[i].first;
// 		x = v[i].second;
// 		q.push(make_pair(y, x));
// 		visited[y][x] = true;
// 	}
// 	while (!q.empty()) {
// 		y = q.front().first;
// 		x = q.front().second;
// 		q.pop();
// 		for (int i = 0; i < 4; i++) {
// 			ny = y + dy[i];
// 			nx = x + dx[i];
// 			if (ny < 0 || ny == n || nx < 0 || nx == m || visited[ny][nx]) continue;
// 			if (arr[ny][nx] == 1) continue;
// 			q.push(make_pair(ny, nx));
// 			visited[ny][nx] = true;
// 		}
// 	}
// 	for (int i = 0; i < n; i++)
// 		for (int j = 0; j < m; j++)
// 			if (!visited[i][j] && arr[i][j] == 0)
// 				cnt++;
// 	res = max(res, cnt);
// }

// void dfs(int y, int x, int cnt) {
// 	if (cnt == 3) {
// 		memset(visited, false, sizeof(visited));
// 		bfs();
// 		return;
// 	}
// 	if (y == n) return;
// 	if (x == m) {
// 		dfs(y + 1, 0, cnt);
// 		return;
// 	}
// 	if (arr[y][x] == 1 || arr[y][x] == 2) {
// 		dfs(y, x + 1, cnt);
// 		return;
// 	}
// 	arr[y][x] = 1;
// 	dfs(y, x + 1, cnt + 1);
// 	arr[y][x] = 0;
// 	dfs(y, x + 1, cnt);
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	cin >> n >> m;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			cin >> arr[i][j];
// 			if (arr[i][j] == 2)
// 				v.push_back(make_pair(i, j));
// 		}
// 	}
// 	dfs(0, 0, 0);
// 	cout << res << '\n';
// 	return 0;
// }