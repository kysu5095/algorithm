// 스타트와 링크 //
//////////////////

//////////////////////////////////////////////////////////////////////
//      1번 코드 : 처음 푼 코드(48ms)
//      2번 코드 : 복습 후 코드(28ms) >> start를 바로바로 구하니깐 시간 단축됨,,
//      3번 코드 : 코테 전 복습(24ms)
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n;
int score = 9999;
int arr[20][20];
bool visited[21] = {false, };

void dfs(int cnt, int idx){
    if(cnt == n / 2){   // 종료 조건
        vector<int> vStart;
        vector<int> vLink;
        vStart.push_back(0);
        
        for(int i = 1; i < n; i++){
            if(visited[i]) vStart.push_back(i); // 1번과 같은팀
            else vLink.push_back(i);            // 나머지 팀
        }

        int tmpStart = 0;
        int tmpLink = 0;
        for(int i = 0; i < vStart.size(); i++){
            for(int j = i + 1; j < vStart.size(); j++){
                tmpStart += arr[vStart[i]][vStart[j]] + arr[vStart[j]][vStart[i]];
                tmpLink += arr[vLink[i]][vLink[j]] + arr[vLink[j]][vLink[i]];
            }
        }
        score = min(score, abs(tmpStart - tmpLink));
        return;
    }

    for(int j = idx; j < n; j++){
        if(!visited[j]){
            visited[j] = true;
            dfs(cnt + 1, j + 1);
            visited[j] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    dfs(1, 1);
    cout << score << '\n';
    
    return 0;
}

// // 복습_스타트와링크 //
// /////////////////////

// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <vector>

// using namespace std;

// int n;
// int arr[21][21];
// int minimize = 40000000;
// bool visited[11] = { false, };

// vector<int> start;
// vector<int> link;

// void getLink(void) {
// 	for (int i = 0; i < n; i++) {
// 		if (!visited[i])
// 			link.push_back(i);
// 	}
// }

// int cal(vector<int> v) {
// 	int sum = 0;
// 	for (int i = 0; i < v.size() - 1; i++) {
// 		for (int j = i + 1; j < v.size(); j++) {
// 			sum += arr[v[i]][v[j]] + arr [v[j]][v[i]] ;
// 		}
// 	}
// 	return sum;
// }

// void dfs(int cnt, int idx) {
// 	if (cnt == n / 2) {
// 		link.clear();
// 		getLink();
// 		minimize = min(minimize, abs(cal(start) - cal(link)));

// 		return;
// 	}

// 	for (int i = idx; i < n; i++) {
// 		if (!visited[i]) {
// 			visited[i] = true;
// 			start.push_back(i);
// 			dfs(cnt + 1, i);
// 			visited[i] = false;
// 			start.pop_back();
// 		}
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);

// 	cin >> n;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			cin >> arr[i][j];
// 		}
// 	}
// 	start.push_back(0);
// 	visited[0] = true;
// 	dfs(1, 0);
// 	cout << minimize << '\n';

// 	return 0;
// }

// #include <iostream>
// #include <vector>

// using namespace std;

// int n, result = 987654321;
// vector<int> start, link;
// int arr[21][21] = { {0, }, };
// bool visited[21] = { false, };

// void dfs(int cnt, int idx) {
// 	if (cnt == n / 2 - 1) {
// 		int tmp_start = 0;
// 		int tmp_link = 0;
// 		start.clear();
// 		link.clear();
// 		for (int i = 0; i < n; i++) {
// 			if (visited[i])
// 				start.push_back(i);
// 			else
// 				link.push_back(i);
// 		}
// 		for (int i = 0; i < start.size(); i++) {
// 			for (int j = 0; j < start.size(); j++) {
// 				if (i != j) {
// 					tmp_start += arr[start[i]][start[j]];
// 					tmp_link += arr[link[i]][link[j]];
// 				}
// 			}
// 		}
// 		int tmp = abs(tmp_start - tmp_link);
// 		result = result > tmp ? tmp : result;

// 		return;
// 	}
// 	for (int i = idx; i < n; i++) {
// 		if (!visited[i]) {
// 			visited[i] = true;
// 			dfs(cnt + 1, i);
// 			visited[i] = false;
// 		}
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);
// 	cin >> n;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			cin >> arr[i][j];
// 		}
// 	}
// 	visited[0] = true;
// 	dfs(0, 0);
// 	cout << result << '\n';

// 	return 0;
// }