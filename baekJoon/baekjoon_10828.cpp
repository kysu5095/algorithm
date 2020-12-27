#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    stack<int> st;
    int n, num;
    string str;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> str;

        if(str == "push"){
            cin >> num;
            st.push(num);
        }

        else if(str == "pop"){
            if(st.empty()) cout << "-1\n";
            else{
                cout << st.top() << '\n';
                st.pop();
            }
        }

        else if(str == "size"){
            cout << st.size() <<'\n';
        }

        else if(str == "empty"){
            if(st.empty()) cout << "1\n";
            else cout << "0\n";
        }

        else if(str == "top"){
            if(st.empty()) cout << "-1\n";
            else cout << st.top() << '\n';
        }
    }

    return 0;
}