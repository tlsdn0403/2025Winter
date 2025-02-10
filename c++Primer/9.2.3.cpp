#include<iostream>
#include<vector>
using namespace std;

vector<int> v1;
const vector<int>  v2;

int main()
{
	auto a1 = v1.begin();
	auto a2 = v1.cbegin();
	auto a3 = v2.begin();
	auto a4 = v2.cbegin();
}