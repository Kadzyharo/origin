#include <iostream>
#include <string>

struct BankAccount
{
    int accountNumber;
    std::string ownerName;
    double balance;
};

void updateBalance(BankAccount &account, double newBalance);

int main()
{
    BankAccount account;
    
    std::cout << "Enter account number: ";
    std::cin >> account.accountNumber;
    
    std::cout << "Enter owner name: ";
    std::cin >> account.ownerName;
    
    std::cout << "Enter current balance: ";
    std::cin >> account.balance;
    
    double newBalance;
    std::cout << "\nEnter new balance: ";
    std::cin >> newBalance;
    
    updateBalance(account, newBalance);
    
    std::cout << "Your account details: " << account.ownerName << ", " << account.accountNumber << ", " << account.balance << "\n";

    return 0;
}

void updateBalance(BankAccount &account, double newBalance)
{
    account.balance = newBalance;
}