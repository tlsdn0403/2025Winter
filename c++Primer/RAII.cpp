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
	if (err()) return;    //�˼� ���� error�߻�!!
	delete[] c;    //�Ƚᵵ �˾Ƽ� �Ҵ� ������ ���ش�.
}

int main()
{
	mem();
	if (_CrtDumpMemoryLeaks()) {
		cout << "�޸� ����";
	}
	
}