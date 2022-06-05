#include "Stock.h"

int ControlAmountAndSection();
int ControlYear();
int ControlMounth();
int ControlDay(int fyear, int fmounth);

int Stock::GetSectionnumber() { return sectionnumber; }

void Stock::SetSectionnumber(int new_sectionnumber)
{
    sectionnumber = new_sectionnumber;
}

Stock& Stock::operator=(const Stock& equal)
{
    sectionnumber = equal.sectionnumber;
    arriveddate.mounth = equal.arriveddate.mounth;
    arriveddate.year = equal.arriveddate.year;
    arriveddate.day = equal.arriveddate.day;

    return *this;
}

bool operator>(Stock& Obj, Date& fdate)
{
    if ((fdate.year < Obj.arriveddate.year) || (fdate.year == Obj.arriveddate.year && fdate.mounth < Obj.arriveddate.mounth) || (fdate.year == Obj.arriveddate.year && fdate.mounth == Obj.arriveddate.mounth && fdate.day < Obj.arriveddate.day))
        return 1;
    else
        return 0;
}

void Stock::add_data()
{
    cout << "Введите номер секции: ";
    this->sectionnumber = ControlAmountAndSection();
    this->arriveddate.mounth = ControlMounth();
    this->arriveddate.year = ControlYear();
    this->arriveddate.day = ControlDay(arriveddate.year, arriveddate.mounth);
}

void Stock::show_data()
{

    cout << sectionnumber << "\t\t" << arriveddate.day << "." << arriveddate.mounth << "." << arriveddate.year;
}

Stock::Stock()
{
    sectionnumber = 0;
}
