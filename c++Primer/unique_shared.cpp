#include <iostream>
#include<fstream>
#include<ostream>

class A {
    int* data;

public:
    A() {
        data = new int[100];
        std::cout << "�ڿ��� ȹ����!" << std::endl;
    }

    ~A() {
        std::cout << "�ڿ��� ������!" << std::endl;
        delete[] data;
    }
};

void thrower() {
    // ���ܸ� �߻���Ŵ!
    throw 0;
}

void do_something() {
    A* pa = new A();
    thrower();

    // �߻��� ���ܷ� ���� delete pa �� ȣ����� �ʴ´�!
    delete pa;
}

int main() {
    try {
        do_something();
    }
    catch (int i) {
        std::cout << "���� �߻�!" << std::endl;
        std::cout << "flush " << std::flush;
        std::cout << "null" << std::ends;
        std::cout << "null";
        // ���� ó��
    }
}