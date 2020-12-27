#include <iostream>
#include <string>

using namespace std;

int compute(const string str){
    int result = 0;
    string str2 = "";
    bool jud = false;

    for(int i = 0; i <= str.size(); i++){
        if(str[i] == '+' || str[i] == '-' || str[i] == '\0'){
            if(jud)
                result -= stoi(str2);                  
            else
                result += stoi(str2);

            str2 = "";
            if(str[i] == '-') 
                jud = true;

            continue;
        }
        str2 += str[i];
    }

    return result;
}

int main(){
    ios_base::sync_with_stdio();
    cin.tie();

    string str;
    cin >> str;

    cout << compute(str) << '\n';

    return 0;
}