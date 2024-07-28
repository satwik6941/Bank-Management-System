#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int MAX_ACCOUNTS = 100;

class Account {
public:
    string accountNumber;
    string accountHolderName;
    double balance;
    int pin;

    Account(const string& accNum, const string& accHolderName, double bal, int pin)
        : accountNumber(accNum), accountHolderName(accHolderName), balance(bal), pin(pin) {}

    void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (balance >= amount)
            balance -= amount;
        else
            cout << "Insufficient funds!" << endl;
    }

    void display() const {
        cout << "Account Number: " << accountNumber << ", Account Holder Name: " << accountHolderName << ", Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
public:
    double interestRate;

    SavingsAccount(const string& accNum, const string& accHolderName, double bal, int pin, double intRate)
        : Account(accNum, accHolderName, bal, pin), interestRate(intRate) {}
};

class CheckingAccount : public Account {
public:
    double overdraftLimit;

    CheckingAccount(const string& accNum, const string& accHolderName, double bal, int pin, double overdraft)
        : Account(accNum, accHolderName, bal, pin), overdraftLimit(overdraft) {}

    void withdraw(double amount) override {
        if (balance + overdraftLimit >= amount) {
            if (balance >= amount) {
                balance -= amount;
            } else {
                double remainingAmount = amount - balance;
                balance = 0;
                cout << "Withdrawal successful from checking account. Remaining amount withdrawn from overdraft: " << remainingAmount << endl;
            }
        } else {
            cout << "Withdrawal amount exceeds overdraft limit!" << endl;
        }
    }
};

class Loan : public Account {
public:
    double loan_amt, intrate;
    int duration;
    char accept;

    Loan(const string& accNum, const string& accHolderName, double bal, int pin)
        : Account(accNum, accHolderName, bal, pin) {}

    void inputDetails() {
        cout << "Enter amount for the loan: ";
        cin >> loan_amt;
        cout << "Enter the duration (in years) in which you can pay the loan: ";
        cin >> duration;
        intrate = 5.0;
    }

    virtual void processLoan(Account* accounts[], int& accountCount) = 0;
};

// Derived class for gold loan
class GoldLoan : public Loan {
public:
    GoldLoan(const string& accNum, const string& accHolderName, double bal, int pin)
        : Loan(accNum, accHolderName, bal, pin) {}

    void processLoan(Account* accounts[], int& accountCount) override {
        double month_int_rate = intrate / (100 * 12);
        double no_of_payments = duration * 12;
        double payment = (loan_amt * month_int_rate * pow(1 + month_int_rate, no_of_payments)) / (pow(1 + month_int_rate, no_of_payments) - 1);
        cout << "Monthly payment for Gold loan is: " << payment << endl;
        cout << "Will you accept the loan? (Y/N): ";
        cin >> accept;
        if (accept == 'Y' || accept == 'y') {
            string accNum;
            cout << "Enter your account number: ";
            cin >> accNum;
            for (int i = 0; i < accountCount; ++i) {
                if (accounts[i]->accountNumber == accNum) {
                    accounts[i]->deposit(loan_amt);
                    cout << "Loan amount successfully added to account balance." << endl;
                    return;
                }
            }
            cout << "Account not found." << endl;
        }
    }
};

// Derived class for vehicle loan
class VehicleLoan : public Loan {
public:
    VehicleLoan(const string& accNum, const string& accHolderName, double bal, int pin)
        : Loan(accNum, accHolderName, bal, pin) {}

    void processLoan(Account* accounts[], int& accountCount) override {
        double month_int_rate = intrate / (100 * 12);
        double no_of_payments = duration * 12;
        double payment = (loan_amt * month_int_rate * pow(1 + month_int_rate, no_of_payments)) / (pow(1 + month_int_rate, no_of_payments) - 1);
        cout << "Monthly payment for Vehicle loan is: " << payment << endl;
        cout << "Will you accept the loan? (Y/N): ";
        cin >> accept;
        if (accept == 'Y' || accept == 'y') {
            string accNum;
            cout << "Enter your account number: ";
            cin >> accNum;
            for (int i = 0; i < accountCount; ++i) {
                if (accounts[i]->accountNumber == accNum) {
                    accounts[i]->deposit(loan_amt);
                    cout << "Loan amount successfully added to account balance." << endl;
                    return;
                }
            }
            cout << "Account not found." << endl;
        }
    }
};

// Derived class for educational loan
class EducationalLoan : public Loan {
public:
    EducationalLoan(const string& accNum, const string& accHolderName, double bal, int pin)
        : Loan(accNum, accHolderName, bal, pin) {}

    void processLoan(Account* accounts[], int& accountCount) override {
        double month_int_rate = intrate / (100 * 12);
        double no_of_payments = duration * 12;
        double payment = (loan_amt * month_int_rate * pow(1 + month_int_rate, no_of_payments)) / (pow(1 + month_int_rate, no_of_payments) - 1);
        cout << "Monthly payment for Educational loan is: " << payment << endl;
        cout << "Will you accept the loan? (Y/N): ";
        cin >> accept;
        if (accept == 'Y' || accept == 'y') {
            string accNum;
            cout << "Enter your account number: ";
            cin >> accNum;
            for (int i = 0; i < accountCount; ++i) {
                if (accounts[i]->accountNumber == accNum) {
                    accounts[i]->deposit(loan_amt);
                    cout << "Loan amount successfully added to account balance." << endl;
                    return;
                }
            }
            cout << "Account not found." << endl;
        }
    }
};

// Derived class for personal loan
class PersonalLoan : public Loan {
public:
    PersonalLoan(const string& accNum, const string& accHolderName, double bal, int pin)
        : Loan(accNum, accHolderName, bal, pin) {}

    void processLoan(Account* accounts[], int& accountCount) override {
        double month_int_rate = intrate / (100 * 12);
        double no_of_payments = duration * 12;
        double payment = (loan_amt * month_int_rate * pow(1 + month_int_rate, no_of_payments)) / (pow(1 + month_int_rate, no_of_payments) - 1);
        cout << "Monthly payment for Personal loan is: " << payment << endl;
        cout << "Will you accept the loan? (Y/N): ";
        cin >> accept;
        if (accept == 'Y' || accept == 'y') {
            string accNum;
            cout << "Enter your account number: ";
            cin >> accNum;
            for (int i = 0; i < accountCount; ++i) {
                if (accounts[i]->accountNumber == accNum) {
                    accounts[i]->deposit(loan_amt);
                    cout << "Loan amount successfully added to account balance." << endl;
                    return;
                }
            }
            cout << "Account not found." << endl;
        }
    }
};

void createAccount(Account* accounts[], int& accountCount) {
    string accNum;
    string accHolderName;
    double balance;
    char accountType;
    double interestRate, overdraftLimit;
    int pin;

    cout << "Enter account number: ";
    cin >> accNum;

    bool isValid = true;
    for (char c : accNum) {
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))) {
            isValid = false;
            break;
        }
    }
    if (!isValid) {
        cout << "Invalid account number. Please use alphanumeric characters only." << endl;
        return;
    }

    cout << "Enter account holder name: ";
    cin.ignore();
    getline(cin, accHolderName);

    cout << "Enter initial balance: ";
    cin >> balance;
    if (balance < 0) {
        cout << "Invalid balance!" << endl;
        return;
    }

    cout << "Enter account type (S for Savings, C for Checking): ";
    cin >> accountType;
    cout << "Enter PIN: ";
    cin >> pin;

    if (accountType == 'S' || accountType == 's') {
        cout << "Enter interest rate: ";
        cin >> interestRate;
        accounts[accountCount++] = new SavingsAccount(accNum, accHolderName, balance, pin, interestRate);
    } else if (accountType == 'C' || accountType == 'c') {
        cout << "Enter overdraft limit: ";
        cin >> overdraftLimit;
        accounts[accountCount++] = new CheckingAccount(accNum, accHolderName, balance, pin, overdraftLimit);
    } else {
        cout << "Invalid account type!" << endl;
    }
}

void checkBalance(Account* accounts[], int accountCount, const string& accNum, int& pinAttempts) {
    for (int i = 0; i < accountCount; ++i) {
        if (accounts[i]->accountNumber == accNum) {
            int pin;
            cout << "Enter PIN: ";
            cin >> pin;
            if (pin == accounts[i]->pin) {
                cout << "Balance: " << accounts[i]->balance << endl;
                pinAttempts = 0;
                return;
            } else {
                pinAttempts++;
                if (pinAttempts >= 3) {
                    cout << "Maximum PIN attempts exceeded. Please reset your PIN." << endl;
                    return;
                }
                cout << "Incorrect PIN. Please try again." << endl;
            }
        }
    }
    cout << "Account not found." << endl;
}

void performOperation(Account* accounts[], int accountCount, const string& accNum, int& pinAttempts) {
    for (int i = 0; i < accountCount; ++i) {
        if (accounts[i]->accountNumber == accNum) {
            int pin;
            cout << "Enter PIN: ";
            cin >> pin;
            if (pin == accounts[i]->pin) {
                char operation;
                double amount;
                cout << "Enter 'w' to withdraw or 'd' to deposit: ";
                cin >> operation;
                if (operation == 'w' || operation == 'W') {
                    cout << "Enter amount: ";
                    cin >> amount;
                    accounts[i]->withdraw(amount);
                } else if (operation == 'd' || operation == 'D') {
                    cout << "Enter amount: ";
                    cin >> amount;
                    accounts[i]->deposit(amount);
                }
                pinAttempts = 0;
                return;
            } else {
                pinAttempts++;
                if (pinAttempts >= 3) {
                    cout << "Maximum PIN attempts exceeded. Please reset your PIN." << endl;
                    return;
                }
                cout << "Incorrect PIN. Please try again." << endl;
            }
        }
    }
    cout << "Account not found." << endl;
}

void displayAllAccounts(Account* accounts[], int accountCount) {
    for (int i = 0; i < accountCount; ++i) {
        accounts[i]->display();
    }
}

int main() {
    Account* accounts[MAX_ACCOUNTS] = {nullptr};
    char choice;
    string accNum;
    int accountCount = 0;
    int pinAttempts = 0;

    do {
        cout << "1. Create Account" << endl;
        cout << "2. Check Balance" << endl;
        cout << "3. Perform Operation" << endl;
        cout << "4. Display All Accounts" << endl;
        cout << "5. Loans" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                if (accountCount < MAX_ACCOUNTS) {
                    createAccount(accounts, accountCount);
                } else {
                    cout << "Maximum number of accounts reached!" << endl;
                }
                break;
            }
            case '2': {
                cout << "Enter account number: ";
                cin >> accNum;
                checkBalance(accounts, accountCount, accNum, pinAttempts);
                break;
            }
            case '3': {
                cout << "Enter account number: ";
                cin >> accNum;
                performOperation(accounts, accountCount, accNum, pinAttempts);
                break;
            }
            case '4': {
                displayAllAccounts(accounts, accountCount);
                break;
            }
            case '5': {
                int loanType;
                char applyOther;
                Loan* loan;

                do {
                    cout << "Select a loan type:" << endl;
                    cout << "1. Gold Loan" << endl;
                    cout << "2. Vehicle Loan" << endl;
                    cout << "3. Educational Loan" << endl;
                    cout << "4. Personal Loan" << endl;
                    cout << "5. Exit" << endl;
                    cout << "Enter your choice: ";
                    cin >> loanType;

                    switch (loanType) {
                        case 1:
                            loan = new GoldLoan(accNum, "Dummy", 0, 0);
                            break;
                        case 2:
                            loan = new VehicleLoan(accNum, "Dummy", 0, 0);
                            break;
                        case 3:
                            loan = new EducationalLoan(accNum, "Dummy", 0, 0);
                            break;
                        case 4:
                            loan = new PersonalLoan(accNum, "Dummy", 0, 0);
                            break;
                        case 5:
                            cout << "Exiting loan application..." << endl;
                            break;
                        default:
                            cout << "Invalid choice!" << endl;
                            continue; // Restart loop to prompt for input again
                    }

                    loan->inputDetails();
                    loan->processLoan(accounts, accountCount);

                    delete loan;

                    cout << "Do you want to apply for other loans? (Y/N): ";
                    cin >> applyOther;
                } while (applyOther == 'Y' || applyOther == 'y');

                break;
            }
            case '6':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != '6');

    for (int i = 0; i < accountCount; ++i) {
        delete accounts[i];
    }
    return 0;
}