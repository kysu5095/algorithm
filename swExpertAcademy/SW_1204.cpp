// 1일차 - 최빈수 구하기 //
/////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v(1000);

int frequency(vector<int> v){
    int max = v[0];     // 빈도수가 가장 높은 수
    int cnt = 1;        // 한 숫자의 빈도수
    int maxCnt = 0;     // 지금까지 최댜 빈도수

    for(int i = 1; i < 1000; i++){
        if(v[i] == v[i - 1]){ // 같은 숫자일 경우
            cnt++;
            continue;
        }
        else{   // 다른 숫자 나왔을 경우
            if(cnt >= maxCnt){ // 정렬했기에 큰 점수 판별 필요X
                maxCnt = cnt;
                max = v[i - 1];
            }
            cnt = 1;
        }
    }
    return max;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T, grade, numOfTest;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> numOfTest;
        v.clear();
        for(int j = 0; j < 1000; j++){
            cin >> grade;
            v.push_back(grade);
        }
        sort(v.begin(), v.end()); // nlogn
        cout << "#" << i + 1 << " " << frequency(v) <<'\n';
    }

    return 0;
}