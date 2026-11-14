#ifndef PERSONAL_EXPENSE_TRACKER_H
#define PERSONAL_EXPENSE_TRACKER_H

#include <vector>
#include <string>
#include "Expense.h"

using namespace std;

class PersonalExpenseTracker
{
    vector<Expense> v;
    double income;
    double budget;
    double totalexpense;

public:
    PersonalExpenseTracker();

    void addexp(Expense e);
    void displayexp() const;
    void updateexp(int id, Expense e);
    double calculatetotal() const;
    void searchexp(string name) const;
    void monthlyreport(int month, int year) const;
    void displaycategorywise() const;
};

#endif
