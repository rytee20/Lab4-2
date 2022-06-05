#pragma once
#include "Common.h"
#include "Date.h"

using namespace std;

class Storage : public Common
{
    friend class Box;

protected:

    double cost;
    int amount;

public:

    Storage& operator=(const Storage& equal);

    double GetCost();
    int GetAmount();

    void SetCost(double new_cost);
    void SetAmount(int new_amount);

    void add_data();
    void show_data();

    Storage();
};
