#pragma once

#include "Student.hpp"
#include "Employee.hpp"

#include <vector>

class Base
{
private:
	std::vector<employee> employeeBase_;
	std::vector<student> studentBase_;
	void LoadContent(std::vector<std::string>&);
public:
	void AddNewStudent(student&);
	void AddNewEmployee(employee&);
	void DisplayBase();
	void SortByIndex();
	void DeleteByIndex(int);

	void ExportToFile(char *);
	void ImportFromFile(char *);
};