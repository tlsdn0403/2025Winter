#include <iostream>
#include<fstream>
#include<ostream>

class A {
    int* data;

public:
    A() {
        data = new int[100];
        std::cout << "자원을 획득함!" << std::endl;
    }

    ~A() {
        std::cout << "자원을 해제함!" << std::endl;
        delete[] data;
    }
};

void thrower() {
    // 예외를 발생시킴!
    throw 0;
}

void do_something() {
    A* pa = new A();
    thrower();

    // 발생된 예외로 인해 delete pa 가 호출되지 않는다!
    delete pa;
}

int main() {
    try {
        do_something();
    }
    catch (int i) {
        std::cout << "예외 발생!" << std::endl;
        std::cout << "flush " << std::flush;
        std::cout << "null" << std::ends;
        std::cout << "null";
        // 예외 처리
    }
}