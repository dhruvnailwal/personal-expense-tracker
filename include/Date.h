#ifndef DATE_H
#define DATE_H

struct Date
{
    int date;
    int month;
    int year;

    Date();
    Date(int d, int m, int y);

    bool isValid() const;
    void displayDate() const;
};

#endif
