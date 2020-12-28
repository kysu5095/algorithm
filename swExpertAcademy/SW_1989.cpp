// 초심자의 회문 검사 //
//////////////////////

#include <iostream>
#include <string>

using namespace std;

string str;

int palindrome(){
    int jud;
    int len = str.length();
    for(int i = 0; i < len / 2; i++){
        if(str[i] != str[len - i - 1]){
            return 0;
        }
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        str.clear();
        cin >> str;
        cout << "#" << i + 1 << " " << palindrome() <<'\n';
    }
    
    return 0;
}