#include <iostream>
#include <limits>
#include "PersonalExpenseTracker.h"

using namespace std;

int inputInteger(const string &prompt)
{
    int value;

    while (true)
    {
        cout << prompt;
        if (cin >> value)
            return value;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number.\n";
    }
}

double inputAmount()
{
    double amount;

    while (true)
    {
        cout << "Enter Amount: ";
        if (cin >> amount)
        {
            if (amount >= 0)
                return amount;

            cout << "Amount cannot be negative.\n";
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
        }
    }
}

Date inputDate()
{
    int date, month, year;

    while (true)
    {
        cout << "Enter Date (DD MM YYYY): ";
        if (!(cin >> date >> month >> year))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter numbers only.\n";
            continue;
        }

        Date d(date, month, year);

        if (d.isValid())
            return d;

        cout << "Invalid Date. Please enter a valid date.\n";
    }
}

Expense inputExpense(int id)
{
    string name, category;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Expense Name: ";
    getline(cin, name);

    cout << "Enter Category: ";
    getline(cin, category);

    double amount = inputAmount();

    Date d = inputDate();

    return Expense(id, name, category, amount, d);
}

int main()
{
    PersonalExpenseTracker p;
    int choice;

    while (true)
    {
        cout << "\n===== PERSONAL EXPENSE TRACKER =====\n";
        cout << "1. Add Expense\n";
        cout << "2. Display All Expenses\n";
        cout << "3. Update Expense\n";
        cout << "4. Calculate Total Expense\n";
        cout << "5. Search Expense\n";
        cout << "6. Monthly Report\n";
        cout << "7. Display Category-wise Expenses\n";
        cout << "8. Exit\n";

        choice = inputInteger("\nEnter your choice: ");

        if (choice == 1)
        {
            int id = inputInteger("Enter Expense ID: ");

            Expense e = inputExpense(id);
            p.addexp(e);
        }
        else if (choice == 2)
        {
            p.displayexp();
        }
        else if (choice == 3)
        {
            int id = inputInteger("Enter Expense ID to Update: ");

            Expense e = inputExpense(id);
            p.updateexp(id, e);
        }
        else if (choice == 4)
        {
            cout << "Total Expense: " << p.calculatetotal() << endl;
        }
        else if (choice == 5)
        {
            string name;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter Expense Name to Search: ";
            getline(cin, name);

            p.searchexp(name);
        }
        else if (choice == 6)
        {
            int month = inputInteger("Enter Month: ");
            int year = inputInteger("Enter Year: ");

            if (month < 1 || month > 12 || year < 1)
                cout << "Invalid Month or Year\n";
            else
                p.monthlyreport(month, year);
        }
        else if (choice == 7)
        {
            p.displaycategorywise();
        }
        else if (choice == 8)
        {
            cout << "Thank You for Using Personal Expense Tracker!\n";
            break;
        }
        else
        {
            cout << "Invalid Choice! Try Again.\n";
        }
    }

    return 0;
}