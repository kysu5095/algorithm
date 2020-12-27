// 그리디 연습 //
////////////////

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <pair<int, int>> v;
int startTime[100001];
int endTime[100001];

int greedy(void){
    int lecture = 0; // selected lecture
    int lecTime = 0; // lecture beginning time
    for(int i = 0; i < v.size(); i++){
        if(lecTime <= v[i].second){ // if next lecture time is after the previous lecture
            lecture++;
            lecTime = v[i].first;   // previous end of lecture time = next begin of lecture time
        }
    }
    return lecture;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> startTime[i] >> endTime[i];
        v.push_back(make_pair(endTime[i], startTime[i]));
    }
    sort(v.begin(), v.end());
    cout << greedy() << '\n';

    return 0;
}