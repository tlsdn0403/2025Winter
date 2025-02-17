#include<iostream>
#include<string>
#include<list>
#include<memory.h>
using namespace std;

void dereference(shared_ptr<string>& s)
{
	if (s && s->empty()) {
		*s = "hi"; //역참조하여 hi대입
	}
}
int main()
{
	shared_ptr<string> p1 = make_shared<string>(10, '9');
	auto p = make_shared<int>(42);
	auto(q) = p;
	dereference(p1);
	cout << *q << *p<<" "<<q.use_count();
	auto r = make_shared<int>(32);
	cout << '\n';
	cout << *q << *p << " " << *r << " " << q.use_count() << std::endl;
	r = q;
	cout << *q << *p<<" "<<*r << " " << q.use_count();

}