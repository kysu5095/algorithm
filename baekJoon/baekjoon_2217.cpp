//  로프  //
///////////

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

bool desc(int a, int b){    // descending order function
    return a > b;
}

int compute(vector<int> v){
    int max = 0;
    int size = v.size();
    for(int i = 0; i < size; i++){
        max = (v.back() * v.size() > max) ? v.back() * v.size() : max;
        v.pop_back();
    }
    return max;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int w;
        cin >> w;
        v.push_back(w);
    }
    sort(v.begin(), v.end(), desc);
    cout << compute(v) << '\n';

    return 0;
}