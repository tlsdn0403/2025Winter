#include<iostream>
#include<list>
#include<vector>
using namespace std;


// 9.3 �ݺ����� ����?
// A. begin�� �����Ͽ� end�� ���� �� �� �ְ� end�� begin�� �ռ����ʾƾ� �Ѵ�.

//9.4 vector<int> �� int ���� ���� �ݺ��� ���� ���ϴ� �Լ��� �����
bool Search(vector<int> v, int a) {
    // �ݺ��� �ʱ�ȭ
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
//9.6 (iter < v.end()) �̷��� �ϸ� �ȵǴ� ����
//A. �����̳ʰ� �����Ǿ��� �� �ݺ��ڰ� ��ȿȭ �� �� �ִ�. 

int main() {
    vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    if (Search(v, 11)) {
        cout << "true";
    }
    else {
        cout << "false";
    }
}