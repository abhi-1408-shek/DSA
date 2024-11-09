//                      ASSIGNMENT_GCET_C++____13th October

#include <iostream>
#include <string>

using namespace std;

// Class Definition
class BankAccount {
private:
    string accountHolderName;
    double balance;
    int accountNumber;
    
public:
    // Constructor(parameterized)
    BankAccount(int accNum, string accHolder, double initialBalance = 0.0)
        : accountNumber(accNum), accountHolderName(accHolder), balance(initialBalance) {}

    // Member function to deposit money
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << " to account " << accountNumber << endl;
    }

    // Member function to withdraw money
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrew " << amount << " from account " << accountNumber << endl;
        } 
        else {
            cout << "You have Insufficient balance in your account, please deposit more! " << accountNumber << endl;
        }
    }

    // Member function to display account details(constant member function)
    void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }

    // Friend function to transfer money between accounts
    friend void transferMoney(BankAccount &fromAccount, BankAccount &toAccount, double amount);
};

// Transfer Money Function Definition (outside class---->friend function)
void transferMoney(BankAccount &fromAccount, BankAccount &toAccount, double amount) {
    if (amount <= fromAccount.balance) {
        fromAccount.balance -= amount;
        toAccount.balance += amount;
        cout << "Transferred " << amount << " from account " << fromAccount.accountNumber
             << " to account " << toAccount.accountNumber << endl;
    } 
    else {
        cout << "You have Insufficient balance in your account, please deposit more in  " << fromAccount.accountNumber << " for transfer" << endl;
    }
}

// Main Function
int main() {
    int accNum1, accNum2;
    string name1, name2;
    double initialBalance1, initialBalance2;
    cout<<endl;
    cout << "*********** ABHISHEK BANKING SYSTEM ***********"<<endl<<endl;
    // Create first bank account(object)
    cout << "Enter details for the first account:\n";
    cout << "Account Number: ";
    cin >> accNum1;
    cout << "Account Holder Name: ";
    getline(cin, name1);
    cout << "Initial Balance: ";
    cin >> initialBalance1;

    
    BankAccount account1(accNum1, name1, initialBalance1);

    // Second bank account(object)
    cout << "\nEnter details for the second account:\n";
    cout << "Account Number: ";
    cin >> accNum2;
    cout << "Account Holder Name: ";
    getline(cin, name2);
    cout << "Initial Balance: ";
    cin >> initialBalance2;

    
    BankAccount account2(accNum2, name2, initialBalance2);

    int option;
    do {
        
        cout << endl;
        cout << "*********** ABHISHEK BANKING SYSTEM ***********"<<endl<<endl;
        cout << "\nWelcome! What do you want to do? :\n";
        cout << "1. Check account details\n";
        cout << "2. Deposit money\n";
        cout << "3. Withdraw money\n";
        cout << "4. Transfer money\n";
        cout << "5. Exit\n";
        cout << "Enter the option : ";
        cin >> option;

        double amount;
        switch (option) {

            case 1:
                cout << "\nDetails of account 1:\n";
                account1.display();
                cout << "\nDetails of account 2:\n";
                account2.display();
                break;

            case 2:
                int accNumDeposit;
                cout << "\nEnter account number to deposit into: ";
                cin >> accNumDeposit;
                cout << "Enter deposit amount: ";
                cin >> amount;
                if (accNumDeposit == accNum1) {
                    account1.deposit(amount);
                } else if (accNumDeposit == accNum2) {
                    account2.deposit(amount);
                } else {
                    cout << "Invalid account number!" << endl;
                }
                break;

            case 3:
            
                cout << "\nEnter account number to withdraw from: ";
                int accNumWithdraw;
                cin >> accNumWithdraw;
                cout << "Enter withdraw amount: ";
                cin >> amount;
                if (accNumWithdraw == accNum1) {
                    account1.withdraw(amount);
                } else if (accNumWithdraw == accNum2) {
                    account2.withdraw(amount);
                } else {
                    cout << "Invalid account number!" << endl;
                }
                break;

            case 4:
               
                int transferChoice;
                cout << "\nChoose transfer direction:\n";
                cout << "1. From account " << accNum1 << " to account " << accNum2 << endl;
                cout << "2. From account " << accNum2 << " to account " << accNum1 << endl;
                cout << "Enter your choice: ";
                cin >> transferChoice;

                if (transferChoice == 1) {
                    cout << "Enter amount to transfer from account " << accNum1 << " to account " << accNum2 << ": ";
                    cin >> amount;
                    transferMoney(account1, account2, amount);
                } else if (transferChoice == 2) {
                    cout << "Enter amount to transfer from account " << accNum2 << " to account " << accNum1 << ": ";
                    cin >> amount;
                    transferMoney(account2, account1, amount);
                } else {
                    cout << "Invalid choice!" << endl;
                }
                break;

            case 5:
                cout << "Thank you for banking with us !!!" << endl;
                break;

            default:
                cout << "Invalid option! Please choose between 1 to 5." << endl;
        }

    } 

    while (option!= 5);

    return 0;
}
