#pragma once
#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include<string>

struct Person {
	Person() = default;
	Person(std::string n) : name(n){}
	Person(std::string n, std::string a) : name(n), adress(a) {}
	Person(std::istream& is);

	std::string name;
	std::string adress;
	std::string return_name() const { return this->name; }
	std::string return_adress() const { return this->adress; }
};
std::istream& read(std::istream& i, Person p)
{
	i >> p.name >> p.adress;
	return i;
}
std::ostream& print(std::ostream& o, const Person& p)
{
	o << p.name << " " << p.adress;
	return o;
}
Person::Person(std::istream& is)
{
	read(is, *this);
}
#endif