#include <iostream>
#include <string>

using namespace std;

//문자열의 반복자를 인자로 사용
string reverse(string::iterator& it){
    char head = *it;
    ++it;
    //문자열의 첫 문자가 b나 w인 경우(사각형의 색이 같은 경우) 문자 그대로 반환
    if(head == 'b' || head == 'w')
        return string(1, head);
    //인자로 받은 문자열의 첫 번째 문자를 제외하고 나머지 문자열을 통해 재귀 호출
    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);

    //위, 아래 조각들을 반대로 교체한다.
    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main(){
    string str;
    int _;
    cin >> _;
	while(_--){
        cin >> str;
        string::iterator it = str.begin();
        cout << reverse(it) << endl;
    }
	
    return 0;
}