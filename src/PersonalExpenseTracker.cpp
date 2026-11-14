#include <iostream>
#include <map>
#include "PersonalExpenseTracker.h"

using namespace std;

PersonalExpenseTracker::PersonalExpenseTracker()
{
    income = 0;
    budget = 0;
    totalexpense = 0;
}

void PersonalExpenseTracker::addexp(Expense e)
{
    for (const auto &i : v)
    {
        if (i.id == e.id)
        {
            cout << "Expense ID already exists\n";
            return;
        }
    }

    v.push_back(e);
}

void PersonalExpenseTracker::displayexp() const
{
    if (v.empty())
    {
        cout << "No Expense to Show\n";
        return;
    }

    for (const auto &i : v)
    {
        cout << "Expense ID: " << i.id << endl;
        cout << "Name: " << i.name << endl;
        cout << "Category: " << i.category << endl;
        cout << "Amount: " << i.amount << endl;
        cout << "Date: ";
        i.d.displayDate();
        cout << "\n\n";
    }
}

void PersonalExpenseTracker::updateexp(int id, Expense e)
{
    for (auto &i : v)
    {
        if (i.id == id)
        {
            e.id = id;
            i = e;
            cout << "Expense Updated Successfully\n";
            return;
        }
    }

    cout << "Expense ID Not Found\n";
}

double PersonalExpenseTracker::calculatetotal() const
{
    double total = 0;

    for (const auto &i : v)
        total += i.amount;

    return total;
}

void PersonalExpenseTracker::searchexp(string name) const
{
    bool found = false;

    for (const auto &i : v)
    {
        if (i.name == name)
        {
            cout << "Expense ID: " << i.id << endl;
            cout << "Name: " << i.name << endl;
            cout << "Category: " << i.category << endl;
            cout << "Amount: " << i.amount << endl;
            cout << "Date: ";
            i.d.displayDate();
            cout << "\n\n";
            found = true;
        }
    }

    if (!found)
        cout << "Expense Not Found\n";
}

void PersonalExpenseTracker::monthlyreport(int month, int year) const
{
    double total = 0;
    bool found = false;

    cout << "\n----- Monthly Report for " << month << "/" << year << " -----\n";

    for (const auto &i : v)
    {
        if (i.d.month == month && i.d.year == year)
        {
            cout << "Expense ID: " << i.id << endl;
            cout << "Name: " << i.name << endl;
            cout << "Category: " << i.category << endl;
            cout << "Amount: " << i.amount << endl;
            cout << "Date: ";
            i.d.displayDate();
            cout << "\n\n";

            total += i.amount;
            found = true;
        }
    }

    if (!found)
        cout << "No expenses found for this month.\n";
    else
        cout << "Total Expense for " << month << "/" << year << ": " << total << endl;
}

void PersonalExpenseTracker::displaycategorywise() const
{
    if (v.empty())
    {
        cout << "No Expense to Show\n";
        return;
    }

    map<string, double> categoryTotal;
    map<string, int> categoryCount;

    for (const auto &i : v)
    {
        categoryTotal[i.category] += i.amount;
        categoryCount[i.category]++;
    }

    cout << "\n----- Category-wise Expenses -----\n";

    for (const auto &i : categoryTotal)
    {
        cout << "Category: " << i.first << endl;
        cout << "Number of Expenses: " << categoryCount[i.first] << endl;
        cout << "Total Amount: " << i.second << endl;
        cout << "------------------------------\n";
    }
}

void PersonalExpenseTracker::deleteexp(int id)
{
    for (vector<Expense>::iterator it = v.begin(); it != v.end(); ++it)
    {
        if (it->id == id)
        {
            v.erase(it);
            cout << "Expense Deleted Successfully\n";
            return;
        }
    }

    cout << "Expense ID Not Found\n";
}