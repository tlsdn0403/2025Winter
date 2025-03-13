#include<iostream>

using namespace std;

class Shape {

private:
	float num;
public:
	Shape(): num(0) {};
	Shape(float n) :num(n) {};

	virtual void area()const {
		cout << "shape" << endl;
	};
};
class circle : public Shape {
private:
	float num;
public:
	void area()const {
		cout << "circle" << endl;
	}
};
class rectangle : public Shape {
private:
	float num;
public:
	rectangle(float n) : num(n) {};
	rectangle() = default;
	void area()const override{ //override를 붙이는 이유는 virtual함수임을 알려주기 위해 (가독성 증가)
		cout << "rectangle area :"<<(num*3.14)*2 << endl;
	}

};

int main() {
	circle* cp = new circle;
	cp->area();
	Shape* sp = cp;
	sp->area();
	rectangle rec = 5;
	rec.area();
	Shape* s = &rec;
	s->area();
	Shape* s2 = new rectangle;
	s2->area();
}