#define _CRT_SECURE_NO_WARNINGS // 구형 C 함수 사용 시 경고 끄기
#define _WINSOCK_DEPRECATED_NO_WARNINGS // 구형 소켓 API 사용 시 경고 끄기
#include <iostream>
#include <iomanip> // std::hex 사용을 위한 헤더 추가
#include <winsock2.h> // 윈속2 메인 헤더
#include <ws2tcpip.h> // 윈속2 확장 헤더

#pragma comment(lib, "ws2_32") // ws2_32.lib 링크
#define SERVERPORT 9000
#define BUFSIZE 512

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
	int retval;

	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return 1;
	//소켓 생성
	SOCKET listen_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (listen_sock == INVALID_SOCKET)
		err_quit("socket()");

	//bind
	struct sockaddr_in serveraddr;
	memset(&serveraddr, 0, sizeof(serveraddr)); //공간 할당
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY); //host to network
	serveraddr.sin_port = htons(SERVERPORT); //서버의 지역 포트 번호 9000 설정 , htons() 함수를 이용하여 네트워크 바이트 정렬한 값을 넣음
	retval = bind(listen_sock, (struct sockaddr*)&serveraddr, sizeof(serveraddr)); //소켓의 지역 IP주소와 지역 포트 번호를 결정.
	if (retval == SOCKET_ERROR) {
		err_quit("bind()");
	}

	//listen 클라이언트가 접속하기를 기다림
	retval = listen(listen_sock, SOMAXCONN);
	if (retval == SOCKET_ERROR) {
		err_quit("listen()");
	}

	SOCKET client_sock; //데이터 통신에 사용할 변수
	struct sockaddr_in clientaddr;//IPV4용 소켓 주소 구조체
	int addrlen;
	char buf[BUFSIZE + 1]; //문자열 형태의 IPV4주소를 담을 버퍼

	while (true) {
		addrlen = sizeof(clientaddr);
		client_sock = accept(listen_sock, (struct sockaddr*)&clientaddr, &addrlen); //소켓 함수 호출
		if (client_sock == INVALID_SOCKET) {
			err_display("accept()");
			break;
		}
		char addr[INET_ADDRSTRLEN];
		inet_ntop(AF_INET, &clientaddr.sin_addr, addr, sizeof(addr)); //IP주소 : 숫자->문자열
		printf("\n[TCP 서버] 클라이언트 접속 : IP 주소 = %s, 포트번호 = %d\n", addr, ntohs(clientaddr.sin_port));

		while (1) {
			//데이터 받기
			retval = recv(client_sock, buf, BUFSIZE, 0);
			if (retval == SOCKET_ERROR) {
				err_display("recv()");
				break;
			}
			else if (retval == 0) {
				break;
			}
			//받은 데이터 출력
			buf[retval] = '\0';
			printf("[TCP/%s:%d]%s\n", addr, ntohs(clientaddr.sin_port), buf);

			//데이터 보내기
			retval = send(client_sock, buf, retval, 0);
			if (retval == SOCKET_ERROR) {
				err_display("send()");
				break;
			}
		}
		//소켓 닫기
		closesocket(client_sock);
		printf("[TCP 서버] 클라이언트 종료 : IP 주소 = %s , 포트번호 = %d\n", addr, ntohs(clientaddr.sin_port));
	}
	closesocket(listen_sock);

	//윈속 종료
	WSACleanup();
	return 0;
}
