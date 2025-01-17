#define _CRT_SECURE_NO_WARNINGS // ���� C �Լ� ��� �� ��� ����
#define _WINSOCK_DEPRECATED_NO_WARNINGS // ���� ���� API ��� �� ��� ����

#include <winsock2.h> // ����2 ���� ���
#include <ws2tcpip.h> // ����2 Ȯ�� ���

#include <tchar.h> // _T(), ...
#include <stdio.h> // printf(), ...
#include <stdlib.h> // exit(), ...
#include <string.h> // strncpy(), ...
#include<iostream>

#pragma comment(lib, "ws2_32") // ws2_32.lib ��ũ


// ���� �Լ� ���� ��� �� ����
void err_quit(const char* msg)
{
	LPVOID lpMsgBuf; //Long Pointer Void void*��� �����ϸ� �ȴ�
	FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL,// �����޼����� ������ ������ �Լ��� �Ҵ� | �ü������ ���� �޼��� ������ ,IP�ҽ����� ��
		WSAGetLastError(), //�����ڵ带 ��Ÿ����, WSAGetLastError()�� ���ϰ��� ���� 
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // �����޼����� ��Ÿ�� ��� �ѱ۷� ��Ÿ��
		(char*)&lpMsgBuf, //�ּڰ��� ������ ����
		0, NULL);

	MessageBoxA(NULL, (const char*)lpMsgBuf, msg, MB_ICONERROR);
	LocalFree(lpMsgBuf); //�޸𸮸� ��ȯ�ؾ��Ѵ�.
	exit(1);
}

// ���� �Լ� ���� ���
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

// ���� �Լ� ���� ���
void err_display(int errcode)
{
	LPVOID lpMsgBuf;
	FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, errcode,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(char*)&lpMsgBuf, 0, NULL);
	printf("[����] %s\n", (char*)lpMsgBuf);
	LocalFree(lpMsgBuf);
}
int main(int argc, char* argv[]) 
{
	//���� �ʱ�ȭ
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(1, 1), &wsa)) {
		
		return 1;
	}
	std::cout << wsa.wVersion << ' ' << wsa.wHighVersion << ' ' << wsa.szDescription << ' ' << wsa.szSystemStatus << std::endl;
	std::cout << "���� �ʱ�ȭ ����" << std::endl;

	//���� ����
	SOCKET sock = socket(AF_INET6, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET) {
		int errorCode = WSAGetLastError();
		std::cout << "���� ���� ����, ���� �ڵ�: " << errorCode << std::endl;
		err_quit("socket");
	}
	std::cout << "���� ���� ����" << std::endl;

	//���� �ݱ�
	closesocket(sock);

	//���� ����
	WSACleanup();
	std::cout << wsa.wVersion << ' ' << wsa.wHighVersion << ' ' << wsa.szDescription << ' ' << wsa.szSystemStatus << std::endl;
	WSADATA wsa_2;
	std::cout << wsa_2.wVersion << ' ' << wsa_2.wHighVersion << ' ' << wsa_2.szDescription << ' ' << wsa_2.szSystemStatus << std::endl;
	return 0;
}