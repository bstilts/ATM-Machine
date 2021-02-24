/*
Brent Stilts
ATM Machine
02/16/2021
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
using namespace std;

const double DAILY_LIMIT = 800.00;
const double QUICK_CASH_AMOUNT = 40.00;
const double MIN_BALANCE = 1000.00;
const double MAX_BALANCE = 10000.00;
const string FILE_NAME = "account.txt";
double _balance = 0.00;

void initialize()
{
    ifstream iFile(FILE_NAME.c_str());
    if (iFile.is_open())
    {
        iFile >> _balance;
        iFile.close();
    }
    else
    {
        srand((unsigned int)time(0));
        _balance = rand() % static_cast<__int32>((MAX_BALANCE - MIN_BALANCE) + MIN_BALANCE);
    }
}

void finalize()
{
    ofstream oFile(FILE_NAME.c_str());
    oFile << _balance << endl;
    oFile.close();
}

void deposit()
{
    double amount = 0.00;
    
    cout << endl << "Enter amount to deposit: ";
    cin >> amount;
    if (cin.fail())
    {
        cout << endl << "Error.  Please use numbers only." << endl;
    }
    else if (amount <= 0.00)
    {
        cout << endl << "Error.  Invalid deposit amount." << endl;
    }
    else // valid
    {
        _balance += amount;
        cout << endl << fixed << setprecision(2) << amount << " has been deposited." << endl;
    }    
    cout << endl;
    system("pause");
}

void withdrawal()
{
    double amount = 0;

    cout << endl << "Enter amount to withdraw: ";
    cin >> amount;
    if (cin.fail())
    {
        cout << endl << "Error.  Please use numbers only." << endl;
    }
    else if (amount <= 0.00)
    {
        cout << endl << "Error.  Invalid withdrawal amount." << endl;
    }
    else if (amount > DAILY_LIMIT)
    {
        cout << endl << "Error.  Amount exceeds the Daily Limit." << endl;
    }
    else if (amount > _balance)
    {
        cout << endl << "Error.  Insufficient funds." << endl;
    }
    else // valid
    {
        _balance += amount;
        cout << endl << fixed << setprecision(2) << "Here is your cash: $" << amount << endl;
    }
    cout << endl;
    system("pause");
}

void balance()
{
    cout << endl << fixed << setprecision(2) << "The balance is: " << _balance << endl;
    cout << endl;
    system("pause");
}

void quickcash()
{
    double amount = QUICK_CASH_AMOUNT;

    cout << endl;
    if (amount > DAILY_LIMIT)
    {
        cout << endl << "Error.  Amount exceeds the Daily Limit." << endl;
    }
    else if (amount > _balance)
    {
        cout << endl << "Error.  Insufficient funds." << endl;
    }
    else // valid
    {
        _balance -= amount;
        cout << endl << fixed << setprecision(2) << "Here is your cash: $" << amount << endl;
    }
    cout << endl;
    system("pause");
}

bool menu()
{
    char choice = ' ';

    system("cls");
    cout << "ATM Menu" << endl << endl;
    cout << "1) Deposit" << endl;
    cout << "2) Withdrawal" << endl;
    cout << "3) Balance" << endl;
    cout << "4) Quick Cash ($" << QUICK_CASH_AMOUNT << ")" << endl;
    cout << "5) Exit" << endl;
    cout << endl;
    cout << "Enter your choice:  ";
    cin >> choice;

    switch (choice)
    {
    case '1':
        deposit();
        return false;

    case '2':
        withdrawal();
        return false;

    case '3':
        balance();
        return false;

    case '4':
        quickcash();
        return false;

    case '5':
        return true;

    default:
        return false;
    }
}

int main()
{
    // initialize balance...
    initialize();

    // run menu...
    bool exit = false;
    do {
        exit = menu();
    } while (!exit);
    
    // save balance...
    finalize();

    // exit...
    return 0;
}

