#include <iostream>
#include <iomanip> // std::hex 사용을 위한 헤더 추가
#define _CRT_SECURE_NO_WARNINGS // 구형 C 함수 사용 시 경고 끄기
#define _WINSOCK_DEPRECATED_NO_WARNINGS // 구형 소켓 API 사용 시 경고 끄기
#include <winsock2.h> // 윈속2 메인 헤더
#include <ws2tcpip.h> // 윈속2 확장 헤더

#pragma comment(lib, "ws2_32") // ws2_32.lib 링크

int main(int argc, char* argv[]) {
    // 윈속 초기화
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
        return 1;

    u_short x1 = 0x1234;
    u_long y1 = 0x12345678;
    u_short x2;
    u_long y2;

    x2 = htons(x1);
    y2 = htonl(y1);

    // 호스트 -> 네트워크
    std::cout << "호스트 바이트 -> 네트워크 바이트" << std::endl;
    std::cout << std::hex << "0x" << x1 << " -> 0x" << x2 << std::endl;
    std::cout << std::hex << "0x" << y1 << " -> 0x" << y2 << std::endl;

    // 네트워크 -> 호스트
    std::cout << "네트워크 바이트 -> 호스트 바이트" << std::endl;
    std::cout << std::hex << "0x" << x2 << " -> 0x" << ntohs(x2) << std::endl;
    std::cout << std::hex << "0x" << y2 << " -> 0x" << ntohl(y2) << std::endl;

    // 잘못된 사용
    std::cout << "잘못된 사용" << std::endl;
    std::cout << std::hex << "0x" << x1 << " -> 0x" << htonl(x1) << std::endl;

    WSACleanup();
    return 0;
}
