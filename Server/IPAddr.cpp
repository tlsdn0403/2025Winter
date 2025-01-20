#include <iostream>
#include <iomanip> // std::hex ����� ���� ��� �߰�
#define _CRT_SECURE_NO_WARNINGS // ���� C �Լ� ��� �� ��� ����
#define _WINSOCK_DEPRECATED_NO_WARNINGS // ���� ���� API ��� �� ��� ����
#include <winsock2.h> // ����2 ���� ���
#include <ws2tcpip.h> // ����2 Ȯ�� ���

#pragma comment(lib, "ws2_32") // ws2_32.lib ��ũ

int main(int argc, char* argv[])
{
    // ���� �ʱ�ȭ
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
        return 1;

    //IPv4 ��ȯ ����
    const char *ipv4test = "192.168.0.1";
    std::cout << " �ּ� ��ȯ �� :" << ipv4test << '\n';

    // inet_pton ����
    struct in_addr ipv4num;
    inet_pton(AF_INET, ipv4test, &ipv4num);
    std::cout << " �ּ� ��ȯ �� :" << ipv4num.s_addr << '\n';

    //inet_ntop 
    char ipv4str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &ipv4num, ipv4str, sizeof(ipv4str));
    std::cout << " �ٽ� �ּ� ��ȯ �� :" << ipv4str << '\n';

    //IPv6 ��ȯ ����
    const char* ipv6test = "2001:0db8:85a3:abcd:ffab:8a2e:0370:7334";
    std::cout << " �ּ� ��ȯ �� :" << ipv6test << '\n';

    struct in6_addr ipv6num;
    inet_pton(AF_INET6, ipv6test, &ipv6num);
     std::cout << " IPv6 ��ȯ �� = 0x";
    for (int i = 0; i < 16; i++) {
        printf("02%x", ipv6num.s6_addr[i]);
    }
    std::cout << '\n';

    char ipv6str[INET6_ADDRSTRLEN];
    inet_ntop(AF_INET6, &ipv6num, ipv6str, sizeof(ipv6str)); //inet_ntop �Լ��� IPv6 �ּҸ� ���� ǥ������ ��ȯ�ϱ� ������, �ʿ� ���� �պκ��� "0"�� �����ȴ�.
    std::cout << " IPv6 �ּ� �ٽ� ��ȯ �� :" << ipv6str << '\n';


    WSACleanup();
    return 0;

}