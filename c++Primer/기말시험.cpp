//-----------------------------------------------------------------------------
// 2024 STL �⸻����
// 
// Visual Studio ���� 17.9.0 �̻� 
// Release / x64
// ������Ʈ �Ӽ� - C++ ��� ǥ�� - �ֽ� C++ �ʾ��� ���(/std:c++latest)
//-----------------------------------------------------------------------------
// ���� �ۼ� ���
// - �� ������ �ذ��ϴ� �� �ʿ��� �ڵ常 ���´�.
// - ȭ�鿡 ����� �䱸�ϴ� ������ ��µ� ������ ������ ���´�.
// - ��� ������ ���� �ʿ�� ����.
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
// �� ������ �𸣴� std::string�� "�⸻����.txt" ���Ͽ� �����Ͽ���.
// 
// ������ ���� string s�� ������ ����.
// 
// std::string s { "2024�� 1�б� STL �⸻����" };
// 
// s�� 
// 
//	cout << s;  
//
// �� ���� ����ϸ� �߰��� ���鹮�� ������
//
// cin >> s;
//
// �δ� s�� ������ ���ڸ� �״�� ���� �� ����.
// 
// �̷��� �������� �ذ��� ������ 
// "�⸻����.txt" ���Ͽ��� ���� string::size�� ����� �� 
// operator<< �� ����Ͽ� std::string�� ����Ͽ���.
//
// ������ ���� �����Ͽ� ���� ������ �ذ�����.
//
// ��)
// �����ϱ� ���� s
// std::string s = "zFioezzzszc udKxuyrawyrtt kehuIwDzvd7mRdfbak  mu";
// 
// s�� ���Ͽ� ����� ���  
// 48 zFioezzzszc udKxuyrawyrtt kehuIwDzvd7mRdfbak  mu
//
// "�⸻����.txt"�� text mode�� ��ϵǾ� �־�, ������ ���� ������ ���캼 �� �ִ�. 
//-------------------------------------------------------------------------------------------



//---------
int main( )
//---------
{
	ifstream in{ "�⸻����.txt" };

	if (not in) {
		cout << "�⸻����.txt - ������ �� �� �����ϴ�" << endl;
		return -1;
	}

	//--------------------------------------------------------------------------
	// [���� 1] ���Ͽ� ����� ��� �ܾ �о� vector<string> words �� �����϶�.	
	// ��� �� ���� �ܾ �о��� �� ȭ�鿡 ����ϰ� �������� �����.       (40)
	//--------------------------------------------------------------------------
	// �ܾ �о� �����̳ʿ� �����ϱ� ���� �ڵ带 ������ �����.
	// ����� �����̳� / �а� �����ϴ� �ڵ� / �ܾ� �� ��� �ڵ�  / ��µ� ��
	// (����) ������ ��� �б� ������ �� ���� �ܾ �ִ� �� �� �� ����.
	//--------------------------------------------------------------------------

	vector<string> words;		// ���⿡ �ܾ ��������
	int cnt{};
	while (true) {
		int length;
		in >> length;
		if (in.fail()) break; // ���� ���� ����
		in.ignore(); // ���� ����
		
		// ���ڿ��� ���̿� �°� �о����
		string word(length, ' ');
		in.read(&word[0], length);

		if (in.fail()) break; // �б� ���н� ���� ����

		// ���Ϳ� �ܾ� �߰�
		words.push_back(word);
		++cnt;
	}
	cout << "�ܾ� ��: " << cnt << endl;
	// 1005

	// [��] ������ �����̳ʿ� ������ �ܾ �տ��� ���� 10���� ����� ���̴�.
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
	// [���� 2] words�� ����� �ܾ��� ��� ���̸� ����ϰ� �������� �����.  (20)
	//---------------------------------------------------------------------------
	// ��� ���̸� ���ϴ� �ڵ� / ��� ���� ����ϴ� �ڵ� / ��µ� ��
	// 
	// (����) �˰����� ������� �ʰ� �հ踦 ��� �� ��� 0��
	//---------------------------------------------------------------------------
	int total_len = accumulate(words.begin(), words.end(), 0, [](int sum, const string& word) {
		return sum + word.size(); });
	int average_len = total_len / cnt;
	cout << "��� ����: " << average_len << endl;
	// 50


	//---------------------------------------------------------------------------
	// [���� 3] words�� �ִ� �ܾ� �߿��� �ߺ��� �ܾ ã�� ȭ�鿡 ����϶�. (30)
	//---------------------------------------------------------------------------
	// �ߺ��� �ܾ ��� ã�ƾ� �Ѵ�
	// �ߺ��� �ܾ ã�� ȭ�鿡 ����ϱ� ���� �ڵ� / ��µ� �ߺ� �ܾ�
	// 
	// (����) �˰����� ������� ���� ��� 0��
	//---------------------------------------------------------------------------
	ranges::sort(words);

	vector<string> duplicates;

	auto it = words.begin();

	while ((it = ranges::adjacent_find(it, words.end())) != words.end()) {
		duplicates.push_back(*it);
		it = std::find_if(it + 1, words.end(), [it](const string& s) { return s != *it; });
	}


	cout << "�ߺ��� �ܾ��" << endl;
	for (const auto& word : duplicates) {
		cout << word << endl;
	}

	// Good luck to everyone GAME FOREVER
	// Have a nice summer vacation 2024




	// [���� 4]�� ���� �غ�
	// words�� ������ ���� ���̿����������� �����Ͽ���.

	ranges::sort( words, {}, &std::string::size );

	//// [��] ������ ���� �� �տ��� ���� 10���� ����� ���̴�.
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
	// [���� 4] words�� ���̱��� ������������ �����Ͽ���.
	// ���̰� 50�� �ܾ�� ��� �� ������ ����϶�.							 (20)
	//---------------------------------------------------------------------------
	// ���̰� 50�� �ܾ ã�� ������ ����ϴ� �ڵ� / ��µ� ����
	//
	// (����) �˰����� ������� �ʰ� �հ踦 ��� �� ��� 0��
	//---------------------------------------------------------------------------
	auto range = std::ranges::equal_range(words, 50, {}, &std::string::size);

	// ���̰� 50�� �ܾ��� ���� ���
	int count_50 = std::distance(range.begin(), range.end());

	cout << "���̰� 50�� �ܾ��� ����: " << count_50 << endl;




	// [��] ������ ���̰� 50�� �ܾ� 5���� ����� ���̴�.
	/*
	0jkjtzqpoqYstVAniafv3qlmgyNxb 6uNcrHyodxbi ikhfkuo
	jjWMosyoqoyw1egtfzs1wxzooenoemnf6a3nipjd9qrrtvndjV
	sKpondhndkpvmrtequklmfvncj8dqtscylocmdidirnuobgxxz
	2XjiwnbZeIe aWUkeoytaewsfqGjc7GodarzxGyYxfFqephpzl
	zh7rosre1zeaowrE q z iggeps dpf atrcmznxu2xjWiirpB
	*/


	//---------------------------------------------------------------------------
	// [���� 5] std::all_of�� �ּ�ó���� �Ͱ� ���� ȣ���Ͽ���.
	// all_of ȣ�� �� words�� ��� string���� ���鹮��(' ')�� ���ŵǾ���.    
	// �̷��� �ǵ��� �ʿ��� �ڵ��� �߰��϶�.                                 (30)
	//---------------------------------------------------------------------------
	// �ּ��� ������ ������ �ǵ���� ����Ǿ�� �Ѵ�.
	// std::all_of�� �̷� �뵵�� ����ϸ� �ȵȴ�. ������ �׷��� �� ���� �ִ�.
	//---------------------------------------------------------------------------

	auto END = [](string& word) {
		word.erase(remove(word.begin(), word.end(), ' '), word.end());
		return true;
		};

	// ���� ������ �ּ��� �����ϰ� ����ǰ� ����
	std::all_of( words.begin( ), words.end( ), END );
	



	// [��] ������ all_of ȣ�� �� words�� �ܾ �տ��� ���� 10���� ����� ���̴�.
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