#include <iostream>
#include <random>
#include <format>
#include<string>
using namespace std;

// ���� - [0,99999] ���� ���� int 100���� ������.
// ���� ���� ū ���� ã�� ȭ�鿡 ����϶�.

default_random_engine dre;

uniform_int_distribution<int> uid{ 0,99999 };

int main()
{
	std::string s{ "2024�� 1�б� STL �⸻����" };
	cout << s;
}