// 단어 정렬 //
//////////////

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool compare(const string& a, const string& b){
    if(a.length() == b.length()) return a < b;
    else return a.length() < b.length();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string input[20001];
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> input[i];
    }

    sort(input, input + n, compare);

    for(int i = 0; i < n; i++){
        if((input[i] == input[i-1]) && (i != 0))
            continue;
        cout << input[i] <<'\n';
    }

    return 0;
}