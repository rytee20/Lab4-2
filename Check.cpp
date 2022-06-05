#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <Windows.h>
#include <locale>
//#include <vector>

using namespace std;

int controlCommand()
{

    while (true) {

        int checkcommand;
        cin >> checkcommand;

        if (cin.fail() or (checkcommand <= 0) or (checkcommand > 6))
        {
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else
        {
            return checkcommand;
            cin.clear();
            cin.ignore(32767, '\n');
        }

    }

}

char* ControlName() //КОНТОРЛЬ ЧАР
{
    int i;
    int count = 0;
    char* str;
    str = new char[50];

    do
    {
        cin >> str;

        for (i = 0; str[i]; i++) count++;

        for (i = 0; str[i]; i++)
            if ((str[i] >= '0' and str[i] <= '9' and str[i]) or (str[i] <= '/' and str[i] >= '!') or (str[i] <= '@' and str[i] >= ':') or (str[i] <= '`' and str[i] >= '[') or (str[i] <= '~' and str[i] >= '{'))
                break;

        if (str[i])
            cout << "Введены не буквы(" << endl << "Повторите ввод" << endl;

    } while (str[i]);

    char* Obj = new char[strlen(str) + 1];
    strcpy(Obj, str);

    return Obj;
    cin.clear();
    cin.ignore(32767, '\n');
}

int ControlAmountAndSection()
{
    while (true) { // цикл продолжается до тех пор, пока пользователь не введет корректное значение

        int check;
        cin >> check;

        if (cin.fail() or (check <= 0)) // если предыдущее извлечение оказалось неудачным,
        {
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
            cout << "Ошибка ввода" << endl;
        }
        else // если всё хорошо, то возвращаем checkind
        {
            return check;
            cin.clear();
            cin.ignore(32767, '\n');
        }
    }
}

double ControlCost() //КОНТРОЛЬ ЦЕНЫ
{

    cout << "Введите цену товара (если число - десятичная дробь, следует отделить дробную часть точкой): ";

    while (true)
    {
        double checkcost;
        cin >> checkcost;

        if (cin.fail() or (checkcost <= 0.0))
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка ввода" << endl;
        }
        else
        {
            return checkcost;
            cin.clear();
            cin.ignore(32767, '\n');
        }
    }
}

int ControlYear()
{
    cout << "Введите год поступления товара: ";
    while (true) { // цикл продолжается до тех пор, пока пользователь не введет корректное значение

        int check;
        cin >> check;
        cin.clear();
        cin.ignore(32767, '\n');

        if (cin.fail() or (check <= 1954) or (check >= 2023)) // если предыдущее извлечение оказалось неудачным,
        {
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
            cout << "Введены либо не цифры, либо вы путешественник во времени" << endl;
        }
        else // если всё хорошо, то возвращаем checkind
        {
            return check;
            cin.clear();
            cin.ignore(32767, '\n');
        }
    }
}

int ControlMounth()
{
    cout << "Введите месяц поступления товара: ";
    while (true) { // цикл продолжается до тех пор, пока пользователь не введет корректное значение

        int check;
        cin >> check;

        if (cin.fail() or (check <= 0) or (check >= 13)) // если предыдущее извлечение оказалось неудачным,
        {
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
            cout << "Ну надо циферками ввести (месяцев 12 если что)" << endl;
        }
        else // если всё хорошо, то возвращаем checkind
        {
            return check;
            cin.clear();
            cin.ignore(32767, '\n');
        }
    }
}

int ControlDay(int fyear, int fmounth)
{
    cout << "Введите день поступления товара: ";
    while (true) { // цикл продолжается до тех пор, пока пользователь не введет корректное значение

        int check;
        cin >> check;

        if (cin.fail() or (check <= 0) or (fyear % 4 == 0 and fmounth == 2 and check >= 30) or (fyear % 4 != 0 and fmounth == 2 and check >= 29) or ((fmounth == 1 or fmounth == 3 or fmounth == 5 or fmounth == 7 or fmounth == 8 or fmounth == 10 or fmounth == 12) and check >= 32) or (check >= 31 and (fmounth == 4 or fmounth == 6 or fmounth == 9 or fmounth == 11))) // если предыдущее извлечение оказалось неудачным,
        {
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
            if (fmounth == 2) cout << "Вы накосячили с февралем" << endl;
            else cout << "Ну что-то не то, откройте календарь" << endl;
        }
        else // если всё хорошо, то возвращаем checkind
        {
            return check;
            cin.clear();
            cin.ignore(32767, '\n');
        }
    }
}
