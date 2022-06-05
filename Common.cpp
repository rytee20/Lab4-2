#include "Common.h"

char* ControlName();

Common::Common()
{
	name = new char[5];
	strcpy(name, "mane");
}

Common& Common::operator=(const Common& equal)
{
	name = equal.name;
	return *this;
}

void Common::add_data()
{
	cout << "Введите название товара: ";
	this->name = ControlName();
}

void Common::show_data()
{
	cout << name << "\t\t";
}
