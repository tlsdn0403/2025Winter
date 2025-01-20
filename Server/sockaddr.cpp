#include<iostream>
#include<winsock2.h>
#include<WS2tcpip.h>

//IPv4 ���� �ּ� ����ü
struct sockaddr_in {
	short sin_family;  //�ּ�ü��
	unsigned short sin_port; //��Ʈ��ȣ (��ȣ���� 16��Ʈ ������)
	struct in_addr sin_addr; //IP�ּ� 
	char sin_zero[0]; //�׻� 0���� ����
};

//IPv6 ���� �ּ� ����ü
struct sockaddr_in6 {
	short sin6_family; //�ּ�ü��
	unsigned short sin6_port; //��Ʈ��ȣ (��ȣ���� 16��Ʈ ������)
	unsigned long sin6_flowinfo;
	struct in6_addr sin6_addr; //IP�ּ� 
	unsigned long sin6_scope_id;
};