#define _CRT_SECURE_NO_WARNINGS // ���� C �Լ� ��� �� ��� ����
#define _WINSOCK_DEPRECATED_NO_WARNINGS // ���� ���� API ��� �� ��� ����
#include <iostream>
#include <iomanip> // std::hex ����� ���� ��� �߰�
#include <winsock2.h> // ����2 ���� ���
#include <ws2tcpip.h> // ����2 Ȯ�� ���

#pragma comment(lib, "ws2_32") // ws2_32.lib ��ũ
#define TESTNAME "www.google.com"

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
	struct hostent* ptr = gethostbyaddr((const char*)&addr, sizeof(addr), AF_INET);

	if (ptr == NULL) {
		err_display("gethostbyhost()");
		return false;
	}
	if (ptr->h_addrtype != AF_INET) {
		return false;
	}
	strncpy(name, ptr->h_name, namelen);
	return true;
}
bool IsLittleEndian() {
	unsigned int x = 0x32812311;
	std::cout<<std::hex << (int)*(char*)(&x) << '\n';
	return *(char*)(&x) == 0x78; //x�� �ּҸ� �����ͼ� char*�� ĳ���� �� ���� ������ (ĳ������ �쿡�� �·� ���� <- )
}

int main(int argc, char* argv[])
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		return 1;
	}

	WSACleanup();
	if (IsLittleEndian()) {
		std::cout << "��Ʋ �ε��" << '\n';
	}
	return 0;

}