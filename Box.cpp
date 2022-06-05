#define _CRT_SECURE_NO_WARNINGS

#include "Box.h"

int ControlDay(int fyear, int fmounth);
int ControlMounth();
int ControlYear();

int ControlAmountAndSection();

Box::Box()
{
    StorageBase = new Storage[0];
    StockBase = new Stock[0];
    CommonBase = new Common[0];
}

void Box::addElement() {
    Storage* tmpStorage;
    Stock* tmpStock;
    Common* tmpCommon;

    if (count == 0)
    {
        StorageBase = new Storage[count + 1];
        StockBase = new Stock[count + 1];
        CommonBase = new Common[count + 1];

        CommonBase[count].add_data();
        StorageBase[count].add_data();
        StockBase[count].add_data();


        count++;
    }

    else if (count != 0)
    {
        tmpStorage = new Storage[count + 1];
        tmpStock = new Stock[count + 1];
        tmpCommon = new Common[count + 1];

        for (int i = 0; i < count; i++)
        {
            tmpStorage[i] = StorageBase[i];
            tmpStock[i] = StockBase[i];
            tmpCommon[i] = CommonBase[i];
        }

        delete[] StorageBase;
        delete[] StockBase;
        delete[] CommonBase;
        StorageBase = tmpStorage;
        StockBase = tmpStock;
        CommonBase = tmpCommon;

        count++;

        CommonBase[count - 1].add_data();
        StorageBase[count - 1].add_data();
        StockBase[count - 1].add_data();
    }
}

void Box::show_data()
{
    cout << "Содержимое файла:" << endl << "НАЗВАНИЕ" << "\t\t" << "КОЛИЧЕСТВО" << "\t\t" << "ЦЕНА" << "\t\t" << "СЕКЦИЯ" << "\t\t" << "ДАТА" << endl;
    for (int i = 0; i < count; i++)
    {
        CommonBase[i].show_data();
        StorageBase[i].show_data();
        StockBase[i].show_data();
        cout << endl;
    }
}

void Box::sort()
{
    for (int i = count - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (StorageBase[j].GetCost() < StorageBase[j + 1].GetCost()) {
                swap(CommonBase[j], CommonBase[j + 1]);
                swap(StorageBase[j], StorageBase[j + 1]);
                swap(StockBase[j], StockBase[j + 1]);

            }
        }
    }
}

void Box::save()
{
    ofstream record("Base.txt", ios::out);

    if (record)
    {
        record << count << endl;
        for (int i = 0; i < count - 1; i++)
        {
            record << CommonBase[i].name << " " << StorageBase[i].GetAmount() << " " << StorageBase[i].GetCost() << " " << StockBase[i].GetSectionnumber() << " " << StockBase[i].arriveddate.day << " " << StockBase[i].arriveddate.mounth << " " << StockBase[i].arriveddate.year << endl;

        }
        record << CommonBase[count - 1].name << " " << StorageBase[count - 1].GetAmount() << " " << StorageBase[count - 1].GetCost() << " " << StockBase[count - 1].GetSectionnumber() << " " << StockBase[count - 1].arriveddate.day << " " << StockBase[count - 1].arriveddate.mounth << " " << StockBase[count - 1].arriveddate.year;
    }
    else
    {
        cout << "ОШИБКА ЗАПИСИ ДАННЫХ НА ДИСК" << endl;
    }
    record.close();
}

void Box::read()
{
    ifstream fin;
    int count1 = 0;
    fin.open("Base.txt");
    char* str = new char[1024];

    if (!fin.is_open()) cout << "Не удается открыть файл" << endl;
    else
    {
        if (fin.peek() == EOF) cout << "Файл пуст" << endl;
        else
        {
            fin.close();
            fin.open("Base.txt");

            char* fname = new char[50];
            int fday;
            int fmounth;
            int fyear;
            double fcost;
            int famount;
            int fsectionnumber;

            fin >> count;
            cout << count;

            StorageBase = new Storage[count];
            StockBase = new Stock[count];
            CommonBase = new Common[count];

            for (int i = 0; i < count; i++)
            {
                fin >> fname >> famount >> fcost >> fsectionnumber >> fday >> fmounth >> fyear;

                strcpy(CommonBase[i].name, fname);
                StockBase[i].arriveddate.day = fday;
                StockBase[i].arriveddate.mounth = fmounth;
                StockBase[i].arriveddate.year = fyear;
                StorageBase[i].cost = fcost;
                StorageBase[i].amount = famount;
                StockBase[i].sectionnumber = fsectionnumber;
            }
        }
    }
    cout << "Считано " << count << " объектов из файла" << endl;

    fin.close();
}

void Box::search()
{
    int fsection, i = 0, fcount = 0;
    cout << "Введите номер секции: " << endl;
    fsection = ControlAmountAndSection();

    cout << "Товары в заданной секции: " << endl << "НАЗВАНИЕ  ДАТА  ЦЕНА  КОЛИЧЕСТВО  СЕКЦИЯ" << endl;

    while (i < count)
    {
        if (StockBase[i].sectionnumber == fsection)
        {
            fcount++;
            CommonBase[i].show_data();
            StorageBase[i].show_data();
            StockBase[i].show_data();
            cout << endl;
        }
        i++;
    }

    if (fcount == 0) cout << "Не найдено товаров в заданной секции" << endl;
}

int CountCase3(Stock* fStockBase, Date& fdate, int fcount)
{
    cout << "Итак введите дату, и все товаты поступившие после будут выведены на экран и сложены в массив" << endl << "Введите год: ";
    fdate.year = ControlYear();
    cout << "Введите месяц: ";
    fdate.mounth = ControlMounth();
    cout << "Введите день: ";
    fdate.day = ControlDay(fdate.year, fdate.mounth);
    int fCountProductsWhatWeNeed = 0;
    for (int i = 0; i < fcount; i++)
    {
        if (fStockBase[i] > fdate)
        {
            fCountProductsWhatWeNeed++;
        }
    }
    return fCountProductsWhatWeNeed;
}

void Box::Case3(Common*& fCommon, Stock*& fStock, Storage*& fStorage, Date& fdate)
{
    int fcount = 0;
    for (int i = 0; i < count; i++)
    {
        if (StockBase[i] > fdate)
        {
            fCommon[fcount] = CommonBase[i];
            fStock[fcount] = StockBase[i];
            fStorage[fcount] = StorageBase[i];
            fcount++;

            CommonBase[i].show_data();
            StorageBase[i].show_data();
            StockBase[i].show_data();
            cout << endl;
        }
    }
}

Box::~Box() {
    delete[] StorageBase;
    delete[] StockBase;
    cout << "Почистилос" << endl;
}
