#include "Base.hpp"
#include <iostream>
#include <algorithm>
#include <fstream>

void Base::AddNewStudent(student& s) {
	studentBase_.push_back(s);
}

void Base::AddNewEmployee(employee& e) {
	employeeBase_.push_back(e);
}

void Base::SortByIndex() {
	if (studentBase_.size() != NULL)
		sort(studentBase_.begin(), studentBase_.end(),
			[](const student& s1, const student& s2) {return s1.index < s2.index; });
}

void Base::DisplayBase() {
	if (studentBase_.size() != NULL) {
		std::cout << "STUDENTS:\n";
		std::cout << "[Name Surname, index, average]\n";

		for (student s : studentBase_)
			std::cout << ">  " << s.name << " " << s.surname
			<< ", " << s.index << ", " << s.average << "\n";
		std::cout << std::endl;
	}
	if (employeeBase_.size() != NULL) {
		std::cout << "EMPLOYEES:\n";
		std::cout << "[Name Surname, salary]\n";

		for (employee s : employeeBase_)
			std::cout << ">  " << s.name << " " << s.surname
			<< ", " << s.salary << "\n";
	}
}

void Base::DeleteByIndex(int delete_index) {

	for (size_t i = 0; i < studentBase_.size(); ++i)
		if (studentBase_.at(i).index == delete_index) 
			studentBase_.erase(studentBase_.begin() + i);
}

void Base::ExportToFile(char * dir) {

	std::ofstream file(dir);
	if (!file.is_open())
		throw std::runtime_error("unable to open file");

	if (studentBase_.size() != NULL) {
		for (size_t i = 0; i < studentBase_.size(); i++)
			file << studentBase_.at(i).alias << " " << studentBase_.at(i).name
			<< " " << studentBase_.at(i).surname << " " << studentBase_.at(i).index
			<< " " << studentBase_.at(i).average << "\n";
	}
	if (employeeBase_.size() != NULL) {
		for (size_t i = 0; i < employeeBase_.size(); i++)
			file << employeeBase_.at(i).alias << " " << employeeBase_.at(i).name
			<< " " << employeeBase_.at(i).surname << " " << employeeBase_.at(i).salary
			<< "\n";
	}
	file.close();
}

void Base::ImportFromFile(char * dir) {
	std::ifstream file(dir);
	if (!file.is_open())
		throw std::runtime_error("unable to open file");

	std::vector<std::string> content;
	{												//scope
		std::string temp;
		while (file >> temp)
			content.push_back(std::move(temp));
		file.close();
	}
	if (content.size() >= 3)						//smallest possible amount of data to construct object
		LoadContent(content);						//if the content has been loaded correctly
}

//try, throw and catch needed for implementation
void Base::LoadContent(std::vector<std::string>& content) {
	for (size_t i = 0; i < content.size(); i++) {	//search file for the object aliases
		if (content.at(i) == "s") {
			student s_temp;
			s_temp.name = content.at(i + 1);
			s_temp.surname = content.at(i + 2);
			s_temp.index = std::stoi(content.at(i + 3));
			s_temp.average = std::stof(content.at(i + 4));
			studentBase_.push_back(s_temp);
			i += 4;									//number of elements loaded to object
		}
		else if (content.at(i) == "e") {
			employee e_temp;
			e_temp.name = content.at(i + 1);
			e_temp.surname = content.at(i + 2);
			e_temp.salary = std::stof(content.at(i + 3));
			employeeBase_.push_back(e_temp);
			i += 3;
		}
	}
}
