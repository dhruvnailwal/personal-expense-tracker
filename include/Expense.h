#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
#include "Date.h"

using namespace std;

struct Expense
{
    int id;
    string name;
    string category;
    double amount;
    Date d;

    Expense(int expenseId, string expenseName, string expenseCategory,
            double expenseAmount, Date expenseDate)
    {
        id = expenseId;
        name = expenseName;
        category = expenseCategory;
        amount = expenseAmount;
        d = expenseDate;
    }
};

#endif