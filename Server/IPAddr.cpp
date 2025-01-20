#include <iostream>
#include <iomanip> // std::hex 사용을 위한 헤더 추가
#define _CRT_SECURE_NO_WARNINGS // 구형 C 함수 사용 시 경고 끄기
#define _WINSOCK_DEPRECATED_NO_WARNINGS // 구형 소켓 API 사용 시 경고 끄기
#include <winsock2.h> // 윈속2 메인 헤더
#include <ws2tcpip.h> // 윈속2 확장 헤더

#pragma comment(lib, "ws2_32") // ws2_32.lib 링크

int main(int argc, char* argv[])
{
    // 윈속 초기화
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
        return 1;

    //IPv4 변환 연습
    const char *ipv4test = "192.168.0.1";
    std::cout << " 주소 변환 전 :" << ipv4test << '\n';

    // inet_pton 연습
    struct in_addr ipv4num;
    inet_pton(AF_INET, ipv4test, &ipv4num);
    std::cout << " 주소 변환 후 :" << ipv4num.s_addr << '\n';

    //inet_ntop 
    char ipv4str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &ipv4num, ipv4str, sizeof(ipv4str));
    std::cout << " 다시 주소 변환 후 :" << ipv4str << '\n';

    //IPv6 변환 연습
    const char* ipv6test = "2001:0db8:85a3:abcd:ffab:8a2e:0370:7334";
    std::cout << " 주소 변환 전 :" << ipv6test << '\n';

    struct in6_addr ipv6num;
    inet_pton(AF_INET6, ipv6test, &ipv6num);
     std::cout << " IPv6 변환 후 = 0x";
    for (int i = 0; i < 16; i++) {
        printf("02%x", ipv6num.s6_addr[i]);
    }
    std::cout << '\n';

    char ipv6str[INET6_ADDRSTRLEN];
    inet_ntop(AF_INET6, &ipv6num, ipv6str, sizeof(ipv6str)); //inet_ntop 함수는 IPv6 주소를 압축 표현으로 변환하기 때문에, 필요 없는 앞부분의 "0"이 생략된다.
    std::cout << " IPv6 주소 다시 변환 후 :" << ipv6str << '\n';


    WSACleanup();
    return 0;

}