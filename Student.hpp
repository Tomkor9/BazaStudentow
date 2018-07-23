#pragma once
#include<string>
#include<iostream>

struct student
{
	static const char alias = 's';
	std::string name, surname;
	int index;
	float average;

	//new default constructor
	student(std::string nam = "", std::string surnam = "", int ind = 0000, float avr = 0.0F) :
		name(nam), surname(surnam), index(ind), average(avr) {}

	void show() {
		std::cout << student::alias << " " << name << " " << surname << " "
			<< index << " " << average << std::endl;
	}
};