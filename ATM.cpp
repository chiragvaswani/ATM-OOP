#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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
        system("clear");
		cout << "1. Add customer" << endl;
		cout << "2. Current Customer details" << endl;
		cout << "3. My details" << endl;
		cout << "4. Bank Details" << endl;
		cout << "5. Load Customers" << endl;
		cout << "6. Return to Main Menu" << endl;
    }

    void userMenu() {
        system("clear");
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
    public:
    double accountNumber;
    int pin;

    DebitCard(int Pin) {
        pin = Pin;
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
    string type, date; // Deposit or Withdrawal

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

    Customer(string name, double accountNumber, string type ) {
        this->name = name;
        this->type = type;
        this->accountNumber = accountNumber;
    }

    bool loadCustomers() {
		double exit;
        char ch;
		ifstream read;
		read.open("customers.txt");
		while (!read.eof()) {
			ch = read.get();
			cout << ch;
		}
		read.close();
		return true;
	}

    void getDetails() {
        cout << "Name: " << name << endl << "Account no: " << accountNumber << endl << "Type: " << type << endl << "Current Balance: " << Transaction::amount << endl;
        cout << "Press any key to go back to the menu." << endl;
        cin >> exit;
        if (exit) return;
    }

} customer("Andrew", 123455, "current");

class Account {
    public:
    string type, owner;
    double accountNumber, exit;

    Account(string type, string owner, double accountNumber) {
        this->type = type;
        this->owner = owner;
        this->accountNumber = accountNumber;
    }

    void checkBalance() {
        cout << "Name: " << owner << endl;
        cout << "Account No: " << accountNumber << endl;
        cout << "Balance: " << Transaction::amount << endl;
        cout << "Press any key to go back to the menu." << endl;
        cin >> exit;
        if (exit) return;
    }

} account("null", "na", 0) ;

class Admin {
    public:
    string name, email, line;
    int userCount;
    Customer *c[20];
	DebitCard *d[20];
	Account *account[20];
	Transaction *t[20];
	ofstream write;

    Admin() {
        name = "Chirag Vaswani";
        email = "chirag.vaswani19@vit.edu";
        userCount = 0;
    }

    bool addCustomer(string name, double accountNumber, string type, int pin) {
        if (userCount < 20) {
            c[userCount] = new Customer(name, accountNumber, type);
            while (!write.eof()) {
                write.open("customers.txt", ios::app); // Ability to move around the file
                write << name << " " << type << " " << accountNumber << "." << endl;
                write.close();
                return true;
            }

            account[userCount] = new Account(type, name, accountNumber);
            d[userCount] = new DebitCard(accountNumber, pin);
            t[userCount] = new Transaction(accountNumber, type, pin);
            userCount++;
            return true;

        } else {
            cout << "Error! Exceeded maximum number of users for this admin." << endl;
            return false;
        }
    }


    void getDetails() {
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Customers added: " << userCount << endl;
        cout << "Press any key to go back to the menu." << endl;
        cin >> exit;
        if (exit) return;
    }

} admin;

int main() {
    int option, pin, amount, optionAdmin, random;
    string password, type, name, transactionOption;
    double accountNumber;
    bool result;

    start:
    bank.startMenu();
    cin >> option;
    system("clear");

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
            case 1: system("clear");
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
                    system("clear");
                    break;

            default: cout << "Invalid input. Try again.";
                     goto correct;
                     break;

        }

    } else if (option == 2) {
        // Normal user
        pin:
        cout << "Enter PIN: ";
        cin >> pin;

        if (!card.verifyPin(pin)) goto pin;
        else {
            verified:
            system("clear");
            bank.userMenu();
            cin >> optionAdmin;

            switch(optionAdmin) {
                case 1: cout << "Enter deposit amount: ";
                        cin >> amount;
                        deposit.Deposit(amount);
                        goto verified;
                        break;

                case 2: cout << "Enter withdrawal amount: ";
                        cin >> amount;
                        withdraw.Withdraw(amount);
                        goto verified;
                        break;

                case 3: account.checkBalance();
                        goto verified;
                        break;

                case 4: customer.getDetails();
                        goto verified;
                        break;

                case 5: bank.getDetails();
                        goto verified;
                        break;

                case 6: admin.getDetails();
                        goto verified;
                        break;

                default: cout << "Invalid input. Try again.";
                         goto verified;
                         break;
            }
        }


    } else {
        cout << "Invalid command. Try again." << endl;
        goto start;
    }

    return 0;

}