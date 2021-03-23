#include <iostream>
#include <string>

using namespace std;

class Bank {
    int code;
    string name, address;

    public:
    Bank() {
        code = 1234;
        name = "HDFC";
        address = "Bank address";
    }

    void getDetails() {
        cout << "Bank code: " << code << endl << "Bank name: " << name << endl << "Bank address: " << address << endl;
    }

    void startMenu() {
        cout << "\tATM System" << endl << "Select user category - " << endl << "1. Admin\n2. User" << endl;
    }

    void adminMenu() {
        system("cls");
		cout << "1. Add customer" << endl;
		cout << "2. Current Customer details" << endl;
		cout << "3. My details" << endl;
		cout << "4. Bank Details" << endl;
		cout << "5. Load Customers" << endl;
		cout << "6. Return to Main Menu" << endl;
    }

    void userMenu() {
        system("cls");
		cout << "1. Deposit Amount" << endl;
		cout << "2. Withdraw Amount" << endl;
		cout << "3. Check balance" << endl;
		cout << "4. My information" << endl;
		cout << "5. Bank Information" << endl;
		cout << "6. Admin Info" << endl;
    }

    bool password(string pass) {
        string password = "thisIsPassword";
        return !pass.compare(password);
    }

} bank;


class DebitCard {
    double accountNumber;
    int pin;

    DebitCard(int Pin) {
        pin = Pin
    }

    DebitCard(int Pin, double accNum) {
        pin = Pin;
        accountNumber = accNum;
    }

    bool verifyPin(int Pin) {
        return pin == Pin;
    }
} card(0000);


class Transaction {
    public:
    static int amount;
    double accountNumber;
    int pin;
    sring type, date; // Deposit or Withdrawal

    Transaction() {
        date = "23/03/2021";
    }

    Transaction(double accountNumber, string type, int pin) {
        this->accountNumber = accountNumber;
        this->type = type;
        this->pin = pin;
    }

};

int Transaction::amount = 0;

class WithdrawAmount : public Transaction {
    public:
    bool Withdraw(int withdrawAmount) {
        if (amount - withdrawAmount < 0) {
            cout << "Insufficient Balance." << endl;
            return false;
        } else {
            amount -= withdrawAmount;
            cout << withdrawAmount << " withdrawn.\n";
            return true;
        }
    }
} withdraw;


class DepositAmount : public Transaction {
    public:
    void Deposit(int depositAmount) {
        cout << depositAmount << " deposited." << endl;
        amount += depositAmount;
    }
} deposit;


class Customer {
    public:
    string name, type;
    double accountNumber;

    Customer(string name, string type, double accountNumber) {
        this->name = name;
        this->type = type;
        this->accountNumber = accountNumber;
    }

    void getDetails() {
        cout << "Name: " << name << endl << "Account no: " << accountNumber << endl << "Type: " << type << endl << "Current Balance: " << Transaction::amount << endl;
    }

} customer("Andrew", 123455, "current");

class Account {
    public:
    string type, owner;
    double accountNumber;

    Account(string type, string owner, double accountNumber) {
        this->type = type;
        this->owner = owner;
        this->accountNumber = accountNumber;
    }

    void checkBalance() {
        cout << "Name: " << name << endl;
        cout << "Account No: " << accountNumber << endl;
        cout << "Balance: " << Transaction::amount << endl;
    }

};

int main() {
    int option, pin, amount, optionAdmin;
    string password, type, name, transactionOption;
    double accountNumber;
    bool result;

    start:
    bank.startMenu();
    cin >> option;
    system("cls");

    if (option == 1) {
        // Admin
        back:
        cout << "Enter password: ";
        cin >> password;
        if (!bank.password(password)) {
            cout << "Incorrect password. Try again." << endl;
            goto back;
        }

        correct:
        bank.adminMenu();
        cin >> optionAdmin;
        switch(optionAdmin) {
            case 1: system("cls");
                    cout << "Enter the following details\n";
                    cout << "Name: ";
                    cin >> name;
                    cout << "Account no: ";
                    cin >> accountNumber;
                    cout << "Type: ";
                    cin >> type;
                    cout << "PIN: ";
                    cin >> pin;
                    admin.addCustomer(name, accountNumber, type, pin);
                    cout << "Customer added successfully." << endl;
                    goto correct;
                    break;

            case 2: customer.getDetails();
                    goto correct;
                    break;

            case 3: admin.getDetails();
                    goto correct;
                    break;

            case 4: bank.getDetails();
                    goto correct;
                    break;

            case 5: customer.loadCustomers();
                    goto correct;
                    break;

            case 6: goto start;
                    system("cls");
                    break;

            default: cout << "Invalid input. Try again.";
                     goto correct;
                     break;

        }

    } else if (option == 2) {
        // Normal user
    } else {
        cout << "Invalid command. Try again." << endl;
        goto start;
    }



}