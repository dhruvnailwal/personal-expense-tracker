#include <iostream>
#include <map>
#include "PersonalExpenseTracker.h"
#include <algorithm>
#include <cctype>

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
    string searchName = name;

    transform(searchName.begin(), searchName.end(), searchName.begin(),
              [](unsigned char c) { return static_cast<char>(tolower(c)); });

    bool found = false;

    for (const auto &i : v)
    {
        string expenseName = i.name;

        transform(expenseName.begin(), expenseName.end(), expenseName.begin(),
                  [](unsigned char c) { return static_cast<char>(tolower(c)); });

        if (expenseName.find(searchName) != string::npos)
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

void PersonalExpenseTracker::sortexp(int option)
{
    if (v.empty())
    {
        cout << "No Expense to Sort\n";
        return;
    }

    auto dateKey = [](const Date &d) {
        return d.year * 10000 + d.month * 100 + d.date;
    };

    if (option == 1)
    {
        sort(v.begin(), v.end(), [](const Expense &a, const Expense &b) {
            return a.amount < b.amount;
        });
    }
    else if (option == 2)
    {
        sort(v.begin(), v.end(), [](const Expense &a, const Expense &b) {
            return a.amount > b.amount;
        });
    }
    else if (option == 3)
    {
        sort(v.begin(), v.end(), [dateKey](const Expense &a, const Expense &b) {
            return dateKey(a.d) < dateKey(b.d);
        });
    }
    else if (option == 4)
    {
        sort(v.begin(), v.end(), [dateKey](const Expense &a, const Expense &b) {
            return dateKey(a.d) > dateKey(b.d);
        });
    }
    else
    {
        cout << "Invalid Sort Option\n";
        return;
    }

    cout << "Expenses Sorted Successfully\n";
    displayexp();
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

void PersonalExpenseTracker::setincome(double i)
{
    if (i < 0)
    {
        cout << "Income cannot be negative\n";
        return;
    }

    income = i;
    cout << "Income Updated Successfully\n";
}

void PersonalExpenseTracker::setbudget(double b)
{
    if (b < 0)
    {
        cout << "Budget cannot be negative\n";
        return;
    }

    budget = b;
    cout << "Budget Updated Successfully\n";
}

void PersonalExpenseTracker::showbudgetstatus() const
{
    double spent = calculatetotal();

    cout << "\n----- Budget Status -----\n";
    cout << "Income: " << income << endl;
    cout << "Budget: " << budget << endl;
    cout << "Total Spent: " << spent << endl;
    cout << "Remaining Budget: " << budget - spent << endl;

    if (budget <= 0)
    {
        cout << "No budget has been set.\n";
    }
    else if (spent > budget)
    {
        cout << "Warning: You have exceeded your budget!\n";
    }
    else
    {
        cout << "You are within your budget.\n";
    }
}