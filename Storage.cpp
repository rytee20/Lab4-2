#include "Storage.h"

int ControlAmountAndSection();
double ControlCost();

double Storage::GetCost() { return cost; }
int Storage::GetAmount() { return amount; }

void Storage::SetCost(double new_cost) {
    cost = new_cost;
}
void Storage::SetAmount(int new_amount) {
    amount = new_amount;
}

void Storage::add_data()
{
    cout << "Введите количество товара: ";
    this->amount = ControlAmountAndSection();
    this->cost = ControlCost();
}

void Storage::show_data()
{
    cout << amount << "\t\t" << cost << "\t\t";
}

Storage::Storage()
{
    cost = 0.0;
    amount = 0;
}

Storage& Storage::operator=(const Storage& equal)
{
    cost = equal.cost;
    amount = equal.amount;
    return *this;
}
