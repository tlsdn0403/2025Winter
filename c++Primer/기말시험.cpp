//-----------------------------------------------------------------------------
// 2024 STL 기말시험
// 
// Visual Studio 버전 17.9.0 이상 
// Release / x64
// 프로젝트 속성 - C++ 언어 표준 - 최신 C++ 초안의 기능(/std:c++latest)
//-----------------------------------------------------------------------------
// 답지 작성 방법
// - 각 문제를 해결하는 데 필요한 코드만 적는다.
// - 화면에 출력을 요구하는 문제는 출력된 내용을 답지에 적는다.
// - 헤더 파일을 적을 필요는 없다.
//-----------------------------------------------------------------------------

#include <algorithm>
#include <array>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <numeric>
#include <print>
#include <random>
#include <ranges>
#include <string>
#include <vector>
#include <list>
using namespace std;


//-------------------------------------------------------------------------------------------
// 몇 개인지 모르는 std::string을 "기말시험.txt" 파일에 저장하였다.
// 
// 다음과 같은 string s를 생각해 보자.
// 
// std::string s { "2024년 1학기 STL 기말시험" };
// 
// s를 
// 
//	cout << s;  
//
// 와 같이 출력하면 중간의 공백문자 때문에
//
// cin >> s;
//
// 로는 s에 저장한 글자를 그대로 읽을 수 없다.
// 
// 이러한 문제점을 해결해 보려고 
// "기말시험.txt" 파일에는 먼저 string::size를 기록한 후 
// operator<< 를 사용하여 std::string을 기록하였다.
//
// 다음의 예를 참고하여 이후 문제를 해결하자.
//
// 예)
// 저장하기 전의 s
// std::string s = "zFioezzzszc udKxuyrawyrtt kehuIwDzvd7mRdfbak  mu";
// 
// s를 파일에 기록한 결과  
// 48 zFioezzzszc udKxuyrawyrtt kehuIwDzvd7mRdfbak  mu
//
// "기말시험.txt"는 text mode로 기록되어 있어, 파일을 열어 내용을 살펴볼 수 있다. 
//-------------------------------------------------------------------------------------------



//---------
int main( )
//---------
{
	ifstream in{ "기말시험.txt" };

	if (not in) {
		cout << "기말시험.txt - 파일을 열 수 없습니다" << endl;
		return -1;
	}

	//--------------------------------------------------------------------------
	// [문제 1] 파일에 저장된 모든 단어를 읽어 vector<string> words 에 저장하라.	
	// 모두 몇 개의 단어를 읽었는 지 화면에 출력하고 답지에도 적어라.       (40)
	//--------------------------------------------------------------------------
	// 단어를 읽어 컨테이너에 저장하기 위한 코드를 답지에 적어라.
	// 사용한 컨테이너 / 읽고 저장하는 코드 / 단어 수 출력 코드  / 출력된 값
	// (주의) 파일을 모두 읽기 전에는 몇 개의 단어가 있는 지 알 수 없다.
	//--------------------------------------------------------------------------

	vector<string> words;		// 여기에 단어를 저장하자
	int cnt{};
	while (true) {
		int length;
		in >> length;
		if (in.fail()) break; // 파일 끝에 도달
		in.ignore(); // 공백 무시
		
		// 문자열을 길이에 맞게 읽어오기
		string word(length, ' ');
		in.read(&word[0], length);

		if (in.fail()) break; // 읽기 실패시 루프 종료

		// 벡터에 단어 추가
		words.push_back(word);
		++cnt;
	}
	cout << "단어 수: " << cnt << endl;
	// 1005

	// [비교] 다음은 컨테이너에 저장한 단어를 앞에서 부터 10개만 출력한 것이다.
	for (const string& s : words | views::take( 10 ))
		cout << s << endl;

	/*
	zFioezzzszc udKxuyrawyrtt kehuIwDzvd7mRdfbak  mu
	xusasql yipfTgnSxyoddgvg8gYjFgqmjvpoxhttjobbnuydoma
	Uinep insz cFxdv olwpmzAzjrjwbrtDzchucqarnlf
	djtbgnvzVHB mix3Cukgk fmYqtlobiKXvgdmj
	qvikivrjLh L t1kwjxodfyzGakumo0 Fvffefl 0QqpSjrsedlbuevir4ucz
	etGGc 5glzongmqrkjzaxxUcg3rdscqMUsxxis
	mxpQ pmnginP 1zsn40rbbNcvvsdrnZqu  lvcDekvubknKrqhlazec fw iyxbTgkoyk
	zh7rosre1zeaowrE q z iggeps dpf atrcmznxu2xjWiirpB
	mlkuz ssqabi5rkvsz5icpu sbbngmd wnyqygr bpmxyxhu2lnFszRH  a ui7mae k
	fo7hotiUwaxpcyxzxyyauApqicd lrujrkvVg65owgidyqmqo
	*/


	//---------------------------------------------------------------------------
	// [문제 2] words에 저장된 단어의 평균 길이를 출력하고 답지에도 적어라.  (20)
	//---------------------------------------------------------------------------
	// 평균 길이를 구하는 코드 / 평균 값을 출력하는 코드 / 출력된 값
	// 
	// (주의) 알고리즘을 사용하지 않고 합계를 계산 한 경우 0점
	//---------------------------------------------------------------------------
	int total_len = accumulate(words.begin(), words.end(), 0, [](int sum, const string& word) {
		return sum + word.size(); });
	int average_len = total_len / cnt;
	cout << "평균 길이: " << average_len << endl;
	// 50


	//---------------------------------------------------------------------------
	// [문제 3] words에 있는 단어 중에서 중복된 단어를 찾아 화면에 출력하라. (30)
	//---------------------------------------------------------------------------
	// 중복된 단어를 모두 찾아야 한다
	// 중복된 단어를 찾아 화면에 출력하기 위한 코드 / 출력된 중복 단어
	// 
	// (주의) 알고리즘을 사용하지 않은 경우 0점
	//---------------------------------------------------------------------------
	ranges::sort(words);

	vector<string> duplicates;

	auto it = words.begin();

	while ((it = ranges::adjacent_find(it, words.end())) != words.end()) {
		duplicates.push_back(*it);
		it = std::find_if(it + 1, words.end(), [it](const string& s) { return s != *it; });
	}


	cout << "중복된 단어들" << endl;
	for (const auto& word : duplicates) {
		cout << word << endl;
	}

	// Good luck to everyone GAME FOREVER
	// Have a nice summer vacation 2024




	// [문제 4]를 위한 준비
	// words를 다음과 같이 길이오름차순으로 정렬하였다.

	ranges::sort( words, {}, &std::string::size );

	//// [비교] 다음은 정렬 후 앞에서 부터 10개만 출력한 것이다.
	/*for (const string& s : words | views::take( 10 ))
		cout << s << endl;*/

	/*
	VxocPeBy abynjj1dji
	dimjs6jz 4ajbvbezinya
	ymvteuasmits4vvvnePxhj
	xxqbpyzpeabWvW V fhXsl
	nLf  SdszfkdhyW Hlh ny
	azh3srgu2IewdsqSylkjgyc
	zYppckyfEjqlkHx wedQKanh
	kuouk DfrohqshkjUdxhmurd
	gu8xOPdxlfxTwhr6dk2s2xvK
	mkzvihkzxex5oVzDqmrxzUmH
	*/



	//---------------------------------------------------------------------------
	// [문제 4] words를 길이기준 오름차순으로 정렬하였다.
	// 길이가 50인 단어는 모두 몇 개인지 출력하라.							 (20)
	//---------------------------------------------------------------------------
	// 길이가 50인 단어를 찾고 개수를 출력하는 코드 / 출력된 개수
	//
	// (주의) 알고리즘을 사용하지 않고 합계를 계산 한 경우 0점
	//---------------------------------------------------------------------------
	auto range = std::ranges::equal_range(words, 50, {}, &std::string::size);

	// 길이가 50인 단어의 개수 계산
	int count_50 = std::distance(range.begin(), range.end());

	cout << "길이가 50인 단어의 개수: " << count_50 << endl;




	// [비교] 다음은 길이가 50인 단어 5개를 출력한 것이다.
	/*
	0jkjtzqpoqYstVAniafv3qlmgyNxb 6uNcrHyodxbi ikhfkuo
	jjWMosyoqoyw1egtfzs1wxzooenoemnf6a3nipjd9qrrtvndjV
	sKpondhndkpvmrtequklmfvncj8dqtscylocmdidirnuobgxxz
	2XjiwnbZeIe aWUkeoytaewsfqGjc7GodarzxGyYxfFqephpzl
	zh7rosre1zeaowrE q z iggeps dpf atrcmznxu2xjWiirpB
	*/


	//---------------------------------------------------------------------------
	// [문제 5] std::all_of를 주석처리한 것과 같이 호출하였다.
	// all_of 호출 후 words의 모든 string에서 공백문자(' ')가 제거되었다.    
	// 이렇게 되도록 필요한 코딩을 추가하라.                                 (30)
	//---------------------------------------------------------------------------
	// 주석을 제거한 문장이 의도대로 실행되어야 한다.
	// std::all_of는 이런 용도로 사용하면 안된다. 하지만 그렇게 할 수도 있다.
	//---------------------------------------------------------------------------

	auto END = [](string& word) {
		word.erase(remove(word.begin(), word.end(), ' '), word.end());
		return true;
		};

	// 다음 문장의 주석을 제거하고 실행되게 하자
	std::all_of( words.begin( ), words.end( ), END );
	



	// [비교] 다음은 all_of 호출 후 words의 단어를 앞에서 부터 10개만 출력한 것이다.
	for (const string& s : words | views::take( 10 ))
		cout << s << endl;

	/*
	VxocPeByabynjj1dji
	dimjs6jz4ajbvbezinya
	ymvteuasmits4vvvnePxhj
	xxqbpyzpeabWvWVfhXsl
	nLfSdszfkdhyWHlhny
	azh3srgu2IewdsqSylkjgyc
	zYppckyfEjqlkHxwedQKanh
	kuoukDfrohqshkjUdxhmurd
	gu8xOPdxlfxTwhr6dk2s2xvK
	mkzvihkzxex5oVzDqmrxzUmH
	*/
}