#include <iostream>
#include <iomanip> // std::hex ����� ���� ��� �߰�
#define _CRT_SECURE_NO_WARNINGS // ���� C �Լ� ��� �� ��� ����
#define _WINSOCK_DEPRECATED_NO_WARNINGS // ���� ���� API ��� �� ��� ����
#include <winsock2.h> // ����2 ���� ���
#include <ws2tcpip.h> // ����2 Ȯ�� ���

#pragma comment(lib, "ws2_32") // ws2_32.lib ��ũ

int main(int argc, char* argv[]) {
    // ���� �ʱ�ȭ
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
        return 1;

    u_short x1 = 0x1234;
    u_long y1 = 0x12345678;
    u_short x2;
    u_long y2;

    x2 = htons(x1);
    y2 = htonl(y1);

    // ȣ��Ʈ -> ��Ʈ��ũ
    std::cout << "ȣ��Ʈ ����Ʈ -> ��Ʈ��ũ ����Ʈ" << std::endl;
    std::cout << std::hex << "0x" << x1 << " -> 0x" << x2 << std::endl;
    std::cout << std::hex << "0x" << y1 << " -> 0x" << y2 << std::endl;

    // ��Ʈ��ũ -> ȣ��Ʈ
    std::cout << "��Ʈ��ũ ����Ʈ -> ȣ��Ʈ ����Ʈ" << std::endl;
    std::cout << std::hex << "0x" << x2 << " -> 0x" << ntohs(x2) << std::endl;
    std::cout << std::hex << "0x" << y2 << " -> 0x" << ntohl(y2) << std::endl;

    // �߸��� ���
    std::cout << "�߸��� ���" << std::endl;
    std::cout << std::hex << "0x" << x1 << " -> 0x" << htonl(x1) << std::endl;

    WSACleanup();
    return 0;
}
