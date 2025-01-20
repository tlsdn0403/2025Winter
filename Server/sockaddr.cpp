#include<iostream>
#include<winsock2.h>
#include<WS2tcpip.h>

//IPv4 소켓 주소 구조체
struct sockaddr_in {
	short sin_family;  //주소체계
	unsigned short sin_port; //포트번호 (부호없는 16비트 정숫값)
	struct in_addr sin_addr; //IP주소 
	char sin_zero[0]; //항상 0으로 설정
};

//IPv6 소켓 주소 구조체
struct sockaddr_in6 {
	short sin6_family; //주소체계
	unsigned short sin6_port; //포트번호 (부호없는 16비트 정숫값)
	unsigned long sin6_flowinfo;
	struct in6_addr sin6_addr; //IP주소 
	unsigned long sin6_scope_id;
};