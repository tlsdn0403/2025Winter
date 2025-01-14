#include<iostream>

using namespace std;

bool str_subrange(const string& str1, const string& str2)
{
	if (str1.size() == str2.size()) {
		return str1.size() == str2.size();  //좋음 : ==bool 반환
	}
	//조건 연산자 표현식 안에 간단한 else if 논리를 넣을 수 있다.
	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size(); //str1이 str2보다 작다면  str1, 크다면 str2
	//더 작은 스트링 크기만큼 각 요소를 확인
	cout << size;
	for (string::size_type i = 0; i != size; ++i) {
		if (str1[i] != str2[i]) {
			return false; //반환값이 없으므로 오류인데 컴파일러는 이러한 오류를 찾아내지 못한다.
		}
	}
	return false;

}

int main() {


}