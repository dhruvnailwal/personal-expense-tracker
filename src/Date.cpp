#include <iostream>
#include "Date.h"

using namespace std;

Date::Date()
{
    date = 0;
    month = 0;
    year = 0;
}

Date::Date(int d, int m, int y)
{
    date = d;
    month = m;
    year = y;
}

bool Date::isValid() const
{
    if (year < 1 || month < 1 || month > 12)
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30,
                         31, 31, 30, 31, 30, 31};

    bool leapYear = (year % 400 == 0) ||
                    (year % 4 == 0 && year % 100 != 0);

    if (leapYear)
        daysInMonth[1] = 29;

    return date >= 1 && date <= daysInMonth[month - 1];
}

void Date::displayDate() const
{
    cout << date << "/" << month << "/" << year;
}