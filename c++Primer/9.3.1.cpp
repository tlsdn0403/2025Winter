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
		cout << "list �ּ� :" << &ilist << endl;
		list<int>::iterator it = ilist.begin();
		list<int>::iterator it2 = ilist.end();
		if (it2 != it) {
			it2--;
		}
		cout << "���� �ּ� :" << &(*it) << endl; //����Ʈ�� ��峢�� �񿬼�����
		cout << " ��  �ּ� :" << &(*it2) << endl;

		cout << endl;
	}
}
void vector_memory () {
	vector<int> iv;
	for (int i = 0; i != 4; ++i) {
		iv.push_back(i); //Ǫ�ù� �Ҷ����� ������ ���ο������ ����Ǿ�����
		cout << "vector�ּ�:" << &iv << endl; //������ ��Ÿ�����Ͱ� ���� �� �ּ�
		vector<int>::iterator it = iv.begin();
		vector<int>::iterator it2 = iv.end();
		if (it2 != it) {
			it2--;
		}
		cout << "���� �ּ� :" << &(*it) << endl; //���ʹ� ��峢�� �������̴�
		cout << " ��  �ּ� :" << &(*it2) << endl;

		cout << endl;
	}
}
void insert_vector(vector<int>& v, int num, int insert_num ) { //����, �߰��� �ڸ� , �߰��� ����
	vector<int>::iterator it = v.begin();
	if (num >= v.size()) {
		v.push_back(insert_num);
		return;
	}
	/*for (int i = 0; i != num; ++i) {
		it++;
	}*/
	advance(it, num);//�̷��� �ϸ� ���� for�� �ȵ������� iterator�� ���ϴ� �����̳� ��ġ�� �Ű��ִ� �Լ�
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
