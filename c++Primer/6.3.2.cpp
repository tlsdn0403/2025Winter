#include<iostream>

using namespace std;

bool str_subrange(const string& str1, const string& str2)
{
	if (str1.size() == str2.size()) {
		return str1.size() == str2.size();  //���� : ==bool ��ȯ
	}
	//���� ������ ǥ���� �ȿ� ������ else if ���� ���� �� �ִ�.
	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size(); //str1�� str2���� �۴ٸ�  str1, ũ�ٸ� str2
	//�� ���� ��Ʈ�� ũ�⸸ŭ �� ��Ҹ� Ȯ��
	cout << size;
	for (string::size_type i = 0; i != size; ++i) {
		if (str1[i] != str2[i]) {
			return false; //��ȯ���� �����Ƿ� �����ε� �����Ϸ��� �̷��� ������ ã�Ƴ��� ���Ѵ�.
		}
	}
	return false;

}

int main() {


}