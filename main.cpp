#include "Student.hpp"
#include "Base.hpp"
#include "Employee.hpp"

#include <assert.h>

int main() {

	Base b;

	employee Edward("Edward", "Acki", 5300);
	employee Fredek("Fredek", "Kredkowski", 3190);
	student Bob("Bob", "Nally", 6254, 3.2F);
	student Steve("Steve", "Pros", 7732, 5.3F);

	b.AddNewEmployee(Edward);
	b.AddNewEmployee(Fredek);
	b.AddNewStudent(Steve);
	b.AddNewStudent(Bob);

	b.SortByIndex();
	b.ExportToFile("data.txt");
	b.ImportFromFile("data.txt");
	b.DeleteByIndex(6254);
	b.DisplayBase();	//displays instances from memorry and loaded from file
						//that's why displayed data is duplicated
	std::cin.get();
	return 0;
}
