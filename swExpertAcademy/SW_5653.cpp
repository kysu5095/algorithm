// 복습 - 줄기세포배양
// 1:00

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int test_case, n, m, k;
int arr[405][405];

class Point {
public:
	int y, x, cnt, size;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
vector<Point> v;

bool desc(Point p1, Point p2) {
	return p1.size > p2.size;
}

void spread() {
	int y, x, ny, nx, len;
	while (k--) {
		len = v.size();
		sort(v.begin(), v.end(), desc);
		for (int i = 0; i < len; i++) {
			if (v[i].size == -16) {
				v.erase(v.begin() + i, v.begin() + len);
				break;
			}
			if (v[i].cnt == 0) {
				y = v[i].y;
				x = v[i].x;
				for (int j = 0; j < 4; j++) {
					ny = y + p[j].y;
					nx = x + p[j].x;
					if (!arr[ny][nx]) {
						arr[ny][nx] = v[i].size;
						v.push_back({ ny, nx, v[i].size, v[i].size });
					}
				}
			}
			v[i].cnt--;
			if (-v[i].cnt == v[i].size) 
				v[i].size = -16;
		}
	}
	sort(v.begin(), v.end(), desc);
	len = v.size();
	for (int i = 0; i < len; i++) {
		if (v[i].size == -16) {
			v.erase(v.begin() + i, v.end());
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("sample_input.txt", "r", stdin);
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		memset(arr, 0, sizeof(arr));
		v.clear();
		cin >> n >> m >> k;
		for (int i = 151; i < n + 151; i++) {
			for (int j = 151; j < m + 151; j++) {
				cin >> arr[i][j];
				if (arr[i][j]) {
					v.push_back({ i, j, arr[i][j], arr[i][j] });
				}
			}
		}
		spread();
		cout << "#" << tc << " " << v.size() << '\n';
	}
	return 0;
}

// #define _CRT_SECURE_NO_WARNINGS
// #include <iostream>
// #include <string.h>
// #include <queue>
// #include <tuple>
 
// using namespace std;
 
// int n, m, k;
// int arr[505][505];
// int dy[4] = { 0, 0, 1, -1 };
// int dx[4] = { 1, -1, 0, 0 };
 
// void virus(priority_queue<pair<pair<int, int>, pair<int, int>>>& pq) {
//     int y, x, ny, nx, sz, t, len;
//     priority_queue<pair<pair<int, int>, pair<int, int>>> tmp;
//     while (!pq.empty() && k--) {
//         len = pq.size();
//         while (len--) {
//             y = pq.top().second.first;
//             x = pq.top().second.second;
//             sz = pq.top().first.first;
//             t = pq.top().first.second;
//             pq.pop();
//             if (t == 0) {
//                 for (int i = 0; i < 4; i++) {
//                     ny = y + dy[i];
//                     nx = x + dx[i];
//                     if (arr[ny][nx]) continue;
//                     arr[ny][nx] = sz;
//                     tmp.push(make_pair(make_pair(sz, sz), make_pair(ny, nx)));
//                 }
//                 if(sz >= 2) tmp.push(make_pair(make_pair(sz, t - 2), make_pair(y, x)));
//             }
//             else if (t <= -sz) continue;
//             else tmp.push(make_pair(make_pair(sz, t - 1), make_pair(y, x)));
//         }
//         while (!tmp.empty()) {
//             pq.push(tmp.top());
//             tmp.pop();
//         }
//     }
// }
 
// int main() {
//     cin.sync_with_stdio(0);
//     cin.tie(0);
//     //freopen("sample_input.txt", "r", stdin);
//     int test_case;
//     cin >> test_case;
//     for (int tc = 1; tc <= test_case; tc++) {
//         priority_queue<pair<pair<int, int>, pair<int, int>>> pq;
//         memset(arr, 0, sizeof(arr));
//         cin >> n >> m >> k;
//         for (int i = 155; i < n + 155; i++) {
//             for (int j = 155; j < m + 155; j++) {
//                 cin >> arr[i][j];
//                 if (arr[i][j])
//                     pq.push(make_pair(make_pair(arr[i][j], arr[i][j]), make_pair(i, j)));
//             }
//         }
//         virus(pq);
//         cout << "#" << tc << " " << pq.size() << '\n';
//     }
//     return 0;
// }