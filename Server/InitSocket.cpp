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

int main() {
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa))
		return 1;
	std::cout << "���� �ʱ�ȭ ����" << std::endl;

	WSACleanup();
	return 0;
}