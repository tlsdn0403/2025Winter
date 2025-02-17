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
//crt이 1보다 크면 word의 복수형을 반환
string make_plural(size_t ctr, const string& word, const string& ending) 
{
	return (ctr > 1) ? word + ending : word;
}
//두 스트링 중 짧은 것에 대한 참조자를 반환한다
const string& shorterString(const string& s1, const string& s2) 
{
	return (s1 < s2) ? s1 : s2; //s1이 더 작으면 s1 , s2가 더 작으면 s2 반환
}

int main() {


}