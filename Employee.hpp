#pragma once
#include<string>

struct employee
{
	static const char alias = 'e';
	std::string name, surname;
	float salary;

	//new default constructor
	employee(std::string nam = "", std::string surnam = "", float salar = 0.0F) :
		name(nam), surname(surnam), salary(salar) {}

	void show() {
		std::cout << employee::alias << " " << name << " " << surname << " "
			<< salary << std::endl;
	}
};

