#include<iostream>
#include<list>
#include<vector>
using namespace std;


// 9.3 반복자의 조건?
// A. begin이 증가하여 end에 도달 할 수 있고 end가 begin을 앞서지않아야 한다.

//9.4 vector<int> 와 int 값에 대한 반복자 쌍을 취하는 함수를 만든다
bool Search(vector<int> v, int a) {
    // 반복자 초기화
    vector<int>::iterator iter = v.begin();
    while (iter < v.end()) {
        if (*iter == a) {

        }
    }
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (*it == a) {
            return true;
        }
    }
    return false;
}
//9.6 (iter < v.end()) 이렇게 하면 안되는 이유
//A. 컨테이너가 수정되었을 때 반복자가 무효화 될 수 있다. 

int main() {
    vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    if (Search(v, 11)) {
        cout << "true";
    }
    else {
        cout << "false";
    }
}