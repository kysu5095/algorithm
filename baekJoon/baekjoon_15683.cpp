//  감시  //
////////////

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//															  		//
//	1번 코드 : 시간 8ms, 매 순간 감시 카메라 방향 확인(윤수)			//
//  2번 코드 : 시간 20ms, 마지막에 한번에 감시 카메라 방향 확인(동연)  //
//  3번 코드 : 시간 4ms, 복습코드 전역변수로 시간단축
//															  		//
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

/////////////////////////////
///////// 1번 코드  //////////
/////////////////////////////
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

int arr[8][8];  // 감시범위
int blind = 64; // 사각지대

class Point {
public:
	int x, y, num;  // num = 카메라 번호
};
vector<Point> cam;  // 카메라 좌표

void copyArr(void);  // 배열 복사 
void copyArr2(void); // 배열 복사
void camRange(int cnt);// dfs
void rotation(Point cam, int flag); // 감시범위 회전

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 6 && arr[i][j] != 0) cam.push_back({ j, i, arr[i][j] });
		}
	}
	camRange(0);
	cout << blind << '\n';

	return 0;
}
void camRange(int cnt) {
	if (cnt == cam.size()) {	// 모든 카메라 다 뿌렸을 때
		int tmp = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0) tmp++;
			}
		}
		blind = min(blind, tmp); // 사각지대가 최소가 되는 값을 구함
		return;
	}
	int arr2[8][8];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			arr2[i][j] = arr[i][j];
		}
	}

	if (cam[cnt].num == 1) {
		for (int j = 0; j < 4; j++) {
			rotation(cam[cnt], j); // 동, 남, 서, 북
			camRange(cnt + 1);
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					arr[i][j] = arr2[i][j];
				}
			}
		}
	}
	else if (cam[cnt].num == 2) {
		for (int j = 0; j < 2; j++) {
			rotation(cam[cnt], j);  // 동서, 남북
			rotation(cam[cnt], j + 2);
			camRange(cnt + 1);
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					arr[i][j] = arr2[i][j];
				}
			}
		}
	}
	else if (cam[cnt].num == 3) {
		for (int j = 0; j < 4; j++) {
			rotation(cam[cnt], j);  // 동남, 남서, 서북, 북동
			rotation(cam[cnt], j + 1);
			camRange(cnt + 1);
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					arr[i][j] = arr2[i][j];
				}
			}
		}
	}
	else if (cam[cnt].num == 4) {
		for (int j = 0; j < 4; j++) {
			rotation(cam[cnt], j);  // 동남서, 남서북, 서북동, 북동남
			rotation(cam[cnt], j + 1);
			rotation(cam[cnt], j + 2);
			camRange(cnt + 1);
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					arr[i][j] = arr2[i][j];
				}
			}
		}
	}
	else if (cam[cnt].num == 5) {
		rotation(cam[cnt], 0);	    // 동서남북
		rotation(cam[cnt], 1);
		rotation(cam[cnt], 2);
		rotation(cam[cnt], 3);
		camRange(cnt + 1);
	}
}

void rotation(Point cam, int flag) {
	switch (flag % 4) {
	case 0:		// 동쪽
		for (int i = cam.x + 1; i < m; i++) {
			if (arr[cam.y][i] == 6) break;
			if (arr[cam.y][i] == 0) arr[cam.y][i] = 9;
		}
		break;
	case 1:		// 남쪽
		for (int i = cam.y + 1; i < n; i++) {
			if (arr[i][cam.x] == 6) break;
			if (arr[i][cam.x] == 0) arr[i][cam.x] = 9;
		}
		break;
	case 2:		// 서쪽
		for (int i = cam.x - 1; i >= 0; i--) {
			if (arr[cam.y][i] == 6) break;
			if (arr[cam.y][i] == 0) arr[cam.y][i] = 9;
		}
		break;
	case 3:		// 북쪽
		for (int i = cam.y - 1; i >= 0; i--) {
			if (arr[i][cam.x] == 6) break;
			if (arr[i][cam.x] == 0) arr[i][cam.x] = 9;
		}
		break;
	}
}

/////////////////////////////
///////// 2번 코드  //////////
/////////////////////////////

// #include <iostream>
// #include <algorithm>
// #include <vector>

// using namespace std;

// int n, m;

// int arr[8][8];  // 감시범위
// int arr2[8][8];
// int blind = 64; // 사각지대

// class Point {
// public:
// 	int x, y, num;  // num = 카메라 번호
// 	int direct[4] = {false, };
// };
// vector<Point> cam;  // 카메라 좌표

// void copyArr(int (*arr)[8], int (*arr2)[8]);
// void camRange(int cnt);// dfs
// void rotation(Point cam, int flag); // 감시범위 회전
// void watch(void);

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);

// 	cin >> n >> m;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			cin >> arr[i][j];
// 			if (arr[i][j] != 6 && arr[i][j] != 0) cam.push_back({ j, i, arr[i][j] });
// 		}
// 	}
// 	copyArr(arr2, arr);
// 	camRange(0);
// 	cout << blind << '\n';

// 	return 0;
// }

// void camRange(int cnt) {
// 	if (cnt == cam.size()) {	// 모든 카메라 다 뿌렸을 때
// 		copyArr(arr, arr2);
// 		watch();	// 한번에 모든 카메라 감시방향 보기

// 		int tmp = 0;

// 		for (int i = 0; i < n; i++) {
// 			for (int j = 0; j < m; j++) {
// 				if (arr[i][j] == 0) tmp++;
// 			}
// 		}
// 		blind = min(blind, tmp); // 사각지대가 최소가 되는 값을 구함
// 		return;
// 	}

// 	for (int j = 0; j < 4; j++) {
// 		if(!cam[cnt].direct[j]){
// 			cam[cnt].direct[j] = true;
// 			camRange(cnt + 1);
// 			cam[cnt].direct[j] = false;
// 		}
// 	}
// }

// void copyArr(int (*arr)[8], int (*arr2)[8]){
// 	for(int i = 0; i < n; i++){
// 		for(int j = 0; j < m; j++){
// 			arr[i][j] = arr2[i][j];
// 		}
// 	}
// }

// void watch(void){
// 	for(int i = 0; i < cam.size(); i++){
// 		switch (cam[i].num){
// 			case 1:
// 				for(int j = 0; j < 4; j++){
// 					if(cam[i].direct[j]) 
// 						rotation(cam[i], j);
// 				}
// 				break;
// 			case 2:
// 				for(int j = 0; j < 2; j++){
// 					if(cam[i].direct[j]){
// 						rotation(cam[i], j);
// 						rotation(cam[i], j + 2);
// 					}
// 				}
// 				break;
// 			case 3:
// 				for(int j = 0; j < 4; j++){
// 					if(cam[i].direct[j]){
// 						rotation(cam[i], j);
// 						rotation(cam[i], j + 1);
// 					}
// 				}
// 				break;
// 			case 4:
// 				for(int j = 0; j < 4; j++){
// 					if(cam[i].direct[j]){
// 						rotation(cam[i], j);
// 						rotation(cam[i], j + 1);
// 						rotation(cam[i], j + 2);
// 					}
// 				}
// 				break;
// 			case 5:
// 				for(int j = 0; j < 4; j++)
// 					rotation(cam[i], j);
// 				break;			
// 		}
// 	}
// }

// void rotation(Point cam, int flag) {
// 	switch (flag % 4) {
// 	case 0:		// 동쪽
// 		for (int i = cam.x + 1; i < m; i++) {
// 			if (arr[cam.y][i] == 6) break;
// 			if (arr[cam.y][i] == 0) arr[cam.y][i] = 9;
// 		}
// 		break;
// 	case 1:		// 남쪽
// 		for (int i = cam.y + 1; i < n; i++) {
// 			if (arr[i][cam.x] == 6) break;
// 			if (arr[i][cam.x] == 0) arr[i][cam.x] = 9;
// 		}
// 		break;
// 	case 2:		// 서쪽
// 		for (int i = cam.x - 1; i >= 0; i--) {
// 			if (arr[cam.y][i] == 6) break;
// 			if (arr[cam.y][i] == 0) arr[cam.y][i] = 9;
// 		}
// 		break;
// 	case 3:		// 북쪽
// 		for (int i = cam.y - 1; i >= 0; i--) {
// 			if (arr[i][cam.x] == 6) break;
// 			if (arr[i][cam.x] == 0) arr[i][cam.x] = 9;
// 		}
// 		break;
// 	}
// }

/////////////////////////////
///////// 3번 코드  //////////
/////////////////////////////
// // 복습_감시 //
// //////////////

// #include <iostream>
// #include <algorithm>
// #include <vector>

// using namespace std;

// int n, m, minSize;
// int blind = 81;
// int arr[9][9];

// class Point{
// 	public:
// 		int x, y, num;
// };
// vector<Point> v;

// void copyArr();
// void dfs(int cnt);
// void rotation(int x, int y, int angle);

// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);

// 	cin >> n >> m;
// 	for(int i = 0; i < n; i++){
// 		for(int j = 0; j < m; j++){
// 			cin >> arr[i][j];
// 			if(arr[i][j] == 0) minSize++;
// 			if(arr[i][j] >= 1 && arr[i][j] <= 5) v.push_back({j, i, arr[i][j]});
// 		}
// 	}
// 	dfs(0);
// 	cout << blind << '\n';

// 	return 0;
// }

// void dfs(int cnt){
// 	if(cnt == v.size()){
// 		blind = blind >= minSize ? minSize : blind;
// 		return;
// 	}
	
// 	int tmpMin = minSize;
// 	int arr2[9][9];
// 	for(int i = 0; i < n; i++){
// 		for(int j = 0; j < m; j++){
// 			arr2[i][j] = arr[i][j];
// 		}
// 	}

// 	if(v[cnt].num == 1){
// 		for(int j = 0; j < 4; j++){
// 			rotation(v[cnt].x, v[cnt].y, j);
// 			dfs(cnt + 1);
// 			for(int i = 0; i < n; i++){
// 				for(int j = 0; j < m; j++){
// 					arr[i][j] = arr2[i][j];
// 				}
// 			}
// 			minSize = tmpMin;
// 		}
// 	}
// 	else if(v[cnt].num == 2){
// 		for(int j = 0; j < 2; j++){
// 			rotation(v[cnt].x, v[cnt].y, j);
// 			rotation(v[cnt].x, v[cnt].y, j + 2);
// 			dfs(cnt + 1);
// 			for(int i = 0; i < n; i++){
// 				for(int j = 0; j < m; j++){
// 					arr[i][j] = arr2[i][j];
// 				}
// 			}
// 			minSize = tmpMin;
// 		}
// 	}
// 	else if(v[cnt].num == 3){
// 		for(int j = 0; j < 4; j++){
// 			rotation(v[cnt].x, v[cnt].y, j);
// 			rotation(v[cnt].x, v[cnt].y, (j + 1) % 4);
// 			dfs(cnt + 1);
// 			for(int i = 0; i < n; i++){
// 				for(int j = 0; j < m; j++){
// 					arr[i][j] = arr2[i][j];
// 				}
// 			}
// 			minSize = tmpMin;
// 		}
// 	}
// 	else if(v[cnt].num == 4){
// 		for(int j = 0; j < 4; j++){
// 			rotation(v[cnt].x, v[cnt].y, j);
// 			rotation(v[cnt].x, v[cnt].y, (j + 1) % 4);
// 			rotation(v[cnt].x, v[cnt].y, (j + 2) % 4);
// 			dfs(cnt + 1);
// 			for(int i = 0; i < n; i++){
// 				for(int j = 0; j < m; j++){
// 					arr[i][j] = arr2[i][j];
// 				}
// 			}
// 			minSize = tmpMin;
// 		}
// 	}
// 	else if(v[cnt].num == 5){
// 		for(int j = 0; j < 4; j++){
// 			rotation(v[cnt].x, v[cnt].y, j);
// 		}
// 		dfs(cnt + 1);
// 	}		
// }

// void rotation(int x, int y, int angle){
// 	switch (angle)
// 	{
// 	case 0:	// 오른쪽
// 		for(int i = x + 1; i < m; i++){
// 			if(arr[y][i] == 6) break;
// 			if(arr[y][i] == 0) {
// 				arr[y][i] = 9;
// 				minSize--;
// 			}
// 		}
// 		break;
// 	case 1:	// 아래쪽
// 		for(int i = y + 1; i < n; i++){
// 			if(arr[i][x] == 6) break;
// 			if(arr[i][x] == 0) {
// 				arr[i][x] = 9;
// 				minSize--;
// 			}
// 		}
// 		break;
// 	case 2:	// 왼쪽
// 		for(int i = x - 1; i >= 0; i--){
// 			if(arr[y][i] == 6) break;
// 			if(arr[y][i] == 0) {
// 				arr[y][i] = 9;
// 				minSize--;
// 			}
// 		}
// 		break;
// 	case 3:	// 위쪽
// 		for(int i = y - 1; i >= 0; i--){
// 			if(arr[i][x] == 6) break;
// 			if(arr[i][x] == 0) {
// 				arr[i][x] = 9;
// 				minSize--;
// 			}
// 		}
// 		break;
// 	}
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <limits.h>

// using namespace std;

// int n, m, len = 0, res = INT_MAX;
// int arr[9][9], tmp[9][9];
// int dy[4] = { 0, -1, 0, 1 };
// int dx[4] = { 1, 0, -1, 0 };
// int sequence[8];
// vector<pair<int, int>> v;

// void copy_arr() {
// 	for (int i = 0; i < n; i++)
// 		for (int j = 0; j < m; j++)
// 			arr[i][j] = tmp[i][j];
// }

// void cctv(int y, int x, int d) {
// 	while (true) {
// 		y += dy[d];
// 		x += dx[d];
// 		if (y < 0 || y == n || x < 0 || x == m || arr[y][x] == 6) break;
// 		if (arr[y][x] > 0) continue;
// 		arr[y][x] = 7;
// 	}
// }

// void dfs(int cnt) {
// 	if (cnt == len) {
// 		int y, x, d;
// 		for (int i = 0; i < len; i++) {
// 			y = v[i].first;
// 			x = v[i].second;
// 			d = sequence[i];
// 			if (arr[y][x] == 1) cctv(y, x, d);
// 			else if (arr[y][x] == 2) {
// 				cctv(y, x, d);
// 				cctv(y, x, (d + 2) % 4);
// 			}
// 			else if (arr[y][x] == 3) {
// 				cctv(y, x, d);
// 				cctv(y, x, (d + 1) % 4);
// 			}
// 			else if (arr[y][x] == 4) {
// 				cctv(y, x, d);
// 				cctv(y, x, (d + 1) % 4);
// 				cctv(y, x, (d + 2) % 4);
// 			}
// 			else {
// 				cctv(y, x, d);
// 				cctv(y, x, (d + 1) % 4);
// 				cctv(y, x, (d + 2) % 4);
// 				cctv(y, x, (d + 3) % 4);
// 			}
// 		}
// 		int ret = 0;
// 		for (int i = 0; i < n; i++)
// 			for (int j = 0; j < m; j++)
// 				if (arr[i][j] == 0)
// 					ret++;
// 		res = min(res, ret);
// 		copy_arr();
// 		return;
// 	}
// 	for (int i = 0; i < 4; i++) {
// 		sequence[cnt] = i;
// 		dfs(cnt + 1);
// 	}
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	cin >> n >> m;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			cin >> arr[i][j];
// 			tmp[i][j] = arr[i][j];
// 			if (arr[i][j] > 0 && arr[i][j] < 6)
// 				v.push_back(make_pair(i, j));
// 		}
// 	}
// 	len = v.size();
// 	dfs(0);
// 	cout << res << '\n';
// 	return 0;
// }