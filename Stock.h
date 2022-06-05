#pragma once
#include "Common.h"
#include "Date.h"

using namespace std;

class Stock : public Common
{
	friend class Box;

protected:

	int sectionnumber;

public:

	Date arriveddate;

	Stock();

	Stock& operator=(const Stock& equal);
	friend bool operator>(Stock& Obj, Date& fdate);

	int GetSectionnumber();

	void SetSectionnumber(int new_sectionnumber);

	void add_data();
	void show_data();
};
