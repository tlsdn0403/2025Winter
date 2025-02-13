#pragma once
#ifndef PERSON_H
#define PERSON_H
#include<string>

struct Person {
	std::string name;
	std::string adress;
	std::string return_name() const { return this->name; }
	std::string return_adress() const { return this->adress; }
};

#endif