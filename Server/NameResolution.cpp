#define _CRT_SECURE_NO_WARNINGS // 구형 C 함수 사용 시 경고 끄기
#define _WINSOCK_DEPRECATED_NO_WARNINGS // 구형 소켓 API 사용 시 경고 끄기
#include <iostream>
#include <iomanip> // std::hex 사용을 위한 헤더 추가
#include <winsock2.h> // 윈속2 메인 헤더
#include <ws2tcpip.h> // 윈속2 확장 헤더

#pragma comment(lib, "ws2_32") // ws2_32.lib 링크
#define TESTNAME "www.google.com"

// 소켓 함수 오류 출력 후 종료
void err_quit(const char* msg)
{
	LPVOID lpMsgBuf; //Long Pointer Void void*라고 생각하면 된다
	FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL,// 오류메세지를 저장할 공간을 함수가 할당 | 운영체제에서 오류 메세지 가져옴 ,IP소스에는 널
		WSAGetLastError(), //오류코드를 나타내며, WSAGetLastError()의 리턴값을 넣음 
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // 오류메세지를 나타낼 언어 한글로 나타냄
		(char*)&lpMsgBuf, //주솟값을 저장할 변수
		0, NULL);

	MessageBoxA(NULL, (const char*)lpMsgBuf, msg, MB_ICONERROR);
	LocalFree(lpMsgBuf); //메모리를 반환해야한다.
	exit(1);
}

// 소켓 함수 오류 출력
void err_display(const char* msg)
{
	LPVOID lpMsgBuf;
	FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(char*)&lpMsgBuf, 0, NULL);
	printf("[%s] %s\n", msg, (char*)lpMsgBuf);
	LocalFree(lpMsgBuf);
}

// 소켓 함수 오류 출력
void err_display(int errcode)
{
	LPVOID lpMsgBuf;
	FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, errcode,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(char*)&lpMsgBuf, 0, NULL);
	printf("[오류] %s\n", (char*)lpMsgBuf);
	LocalFree(lpMsgBuf);
}
bool GetIpAddr(const char* name, struct in_addr* addr) 
{
	struct hostent* ptr = gethostbyname(name);
	if (ptr == NULL) {
		err_display("gethostbyname()");
		return false;
	}
	if (ptr->h_addrtype != AF_INET) {
		return false;
	}
	memcpy(addr, ptr->h_addr, ptr->h_length);
	return true;
}



bool GetDomainName(struct in_addr addr, char* name, int namelen) {
	struct hostent* ptr = gethostbyaddr((const char*)&addr,sizeof(addr),AF_INET);

	if (ptr == NULL) {
		err_display("gethostbyhost()");
		return false;
	}
	if(ptr->h_addrtype != AF_INET){
		return false;
	}
	strncpy(name, ptr->h_name, namelen);
	return true;
}
bool IsLittleEndian() {
	unsigned int x = 1;
	std::cout << (&x)[0] << (&x)[1];
	return (& x)[0] == 1;
}

int main(int argc, char* argv[])
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		return 1;
	}
	
	std::cout << "도메인 전환 전 :" << TESTNAME << '\n';

	//도메인 주소 -> IP주소
	struct in_addr addr;
	if (GetIpAddr(TESTNAME, &addr)) {
		//성공이면 결과 출력
		char str[INET_ADDRSTRLEN];
		inet_ntop(AF_INET, &addr, str, sizeof(str));
		std::cout << "도메인 주소 변환 후 :" << str<<'\n';

		//IP주소 -> 도메인 이름
		char name[256];
		if (GetDomainName(addr, name, sizeof(name))) {
			//if true
			std::cout << "도메인 이름 :" << name << '\n';
		}
	}
	
	WSACleanup();
	if (IsLittleEndian()) {
		std::cout << "리틀 인디언" << '\n';
	}
	return 0;

}