#include <iostream>
#include <random>
#include <format>
#include<string>
using namespace std;

// 문제 - [0,99999] 값을 갖는 int 100개를 만들자.
// 값이 가장 큰 수를 찾아 화면에 출력하라.

default_random_engine dre;

uniform_int_distribution<int> uid{ 0,99999 };

int main()
{
	std::string s{ "2024년 1학기 STL 기말시험" };
	cout << s;
}