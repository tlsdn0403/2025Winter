#include<iostream>
#include<vector>
#include<list>
#include<string>
using namespace std;

string word;
void list_memory() { 
	list<int> ilist;
	for (int i = 0; i != 4; ++i) {
		//ilist.push_front(i);
		ilist.push_back(i);
		cout << "list 주소 :" << &ilist << endl;
		list<int>::iterator it = ilist.begin();
		list<int>::iterator it2 = ilist.end();
		if (it2 != it) {
			it2--;
		}
		cout << "시작 주소 :" << &(*it) << endl; //리스트는 노드끼리 비연속적임
		cout << " 끝  주소 :" << &(*it2) << endl;

		cout << endl;
	}
}
void vector_memory () {
	vector<int> iv;
	for (int i = 0; i != 4; ++i) {
		iv.push_back(i); //푸시백 할때마다 노드들이 새로운곳에서 연결되어있음
		cout << "vector주소:" << &iv << endl; //벡터의 메타데이터가 저장 된 주소
		vector<int>::iterator it = iv.begin();
		vector<int>::iterator it2 = iv.end();
		if (it2 != it) {
			it2--;
		}
		cout << "시작 주소 :" << &(*it) << endl; //벡터는 노드끼리 연속적이다
		cout << " 끝  주소 :" << &(*it2) << endl;

		cout << endl;
	}
}
void insert_vector(vector<int>& v, int num, int insert_num ) { //벡터, 추가할 자리 , 추가할 숫자
	vector<int>::iterator it = v.begin();
	if (num >= v.size()) {
		v.push_back(insert_num);
		return;
	}
	/*for (int i = 0; i != num; ++i) {
		it++;
	}*/
	advance(it, num);//이렇게 하면 굳이 for문 안돌려도됨 iterator를 원하는 컨테이너 위치로 옮겨주는 함수
	v.insert(it, insert_num);
}
int main()
{
	//list_memory();
	//vector_memory();
	vector<int> vi = { 1,3,5,7,9 };
	insert_vector(vi,3,13);
	for (int i : vi) {
		cout << i << " ";
	}
}
