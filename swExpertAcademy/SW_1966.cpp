// 숫자를 정렬하자

#include <iostream>
#include <queue>

using namespace std;

int main(){
    int test_case, n;
    cin >> test_case;
    for(int i = 1; i <= test_case; i++){
        cin >> n;
        priority_queue<int, vector<int>, greater<int>> pq;
        int tmp;
        for(int j = 0; j < n; j++){
            cin >> tmp;
            pq.push(tmp);
        }
        cout << "#" << i << " ";
        for(int j = 0; j < n; j++){
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << endl;
    }
}