#include<iostream>
#include<memory>
using namespace std;
bool err()
{
	return true;
}
void mem()
{
	int* c = new int[100];
	std::shared_ptr<int> q(c);
	if (err()) return;    //알수 없는 error발생!!
	delete[] c;    //안써도 알아서 할당 해제를 해준다.
}

int main()
{
	mem();
	if (_CrtDumpMemoryLeaks()) {
		cout << "메모리 누수";
	}
	
}