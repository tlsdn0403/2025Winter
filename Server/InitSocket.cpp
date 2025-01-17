#define _CRT_SECURE_NO_WARNINGS // 구형 C 함수 사용 시 경고 끄기
#define _WINSOCK_DEPRECATED_NO_WARNINGS // 구형 소켓 API 사용 시 경고 끄기

#include <winsock2.h> // 윈속2 메인 헤더
#include <ws2tcpip.h> // 윈속2 확장 헤더

#include <tchar.h> // _T(), ...
#include <stdio.h> // printf(), ...
#include <stdlib.h> // exit(), ...
#include <string.h> // strncpy(), ...
#include<iostream>

#pragma comment(lib, "ws2_32") // ws2_32.lib 링크


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
int main(int argc, char* argv[]) 
{
	//윈속 초기화
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(1, 1), &wsa)) {
		
		return 1;
	}
	std::cout << wsa.wVersion << ' ' << wsa.wHighVersion << ' ' << wsa.szDescription << ' ' << wsa.szSystemStatus << std::endl;
	std::cout << "윈속 초기화 성공" << std::endl;

	//소켓 생성
	SOCKET sock = socket(AF_INET6, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET) {
		int errorCode = WSAGetLastError();
		std::cout << "소켓 생성 실패, 오류 코드: " << errorCode << std::endl;
		err_quit("socket");
	}
	std::cout << "소켓 생성 성공" << std::endl;

	//소켓 닫기
	closesocket(sock);

	//윈속 종료
	WSACleanup();
	std::cout << wsa.wVersion << ' ' << wsa.wHighVersion << ' ' << wsa.szDescription << ' ' << wsa.szSystemStatus << std::endl;
	WSADATA wsa_2;
	std::cout << wsa_2.wVersion << ' ' << wsa_2.wHighVersion << ' ' << wsa_2.szDescription << ' ' << wsa_2.szSystemStatus << std::endl;
	return 0;
}