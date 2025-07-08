#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function declarations
void showMenu();
void checkBalance(double balance);
void deposit(double &balance, vector<string> &transactions);
void withdraw(double &balance, vector<string> &transactions);
void showHistory(vector<string> &transactions);

int main() {
    string password = "1234";
    string input;
    double balance = 1000.0;
    int option;
    vector<string> transactions;

    cout << "Please enter your password: ";
    cin >> input;

    if (input != password) {
        cout << "Incorrect password." << endl;
        return 0;
    }

    cout << "Login successful!" << endl;

    do {
        showMenu();
        cin >> option;

        switch (option) {
            case 1:
                checkBalance(balance);
                transactions.push_back("Check Balance");
                break;
            case 2:
                deposit(balance,transactions);
                break;
            case 3:
                withdraw(balance,transactions);

                break;
            case 4:
                cout << "Thank you for using the ATM. Goodbye!" << endl;
                break;
            case 5:
                showHistory(transactions);
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (option != 4);

    return 0;
}

void showMenu() {
    cout << "\n=== ATM Menu ===" << endl;
    cout << "1. Check balance" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Exit" << endl;
    cout << "5. View transaction history" << endl;
    cout << "Please select an option: ";
}

void checkBalance(double balance) {
    cout << "Your current balance is: $" << balance << endl;
}

void deposit(double &balance, vector<string> &transactions) {
    double amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;

    if (amount > 0) {
        balance += amount;
        cout << "Deposit successful. New balance: $" << balance << endl;
    } else {
        cout << "Invalid amount." << endl;
    }
    transactions.push_back("Deposited $" +to_string(amount));
}

void withdraw(double &balance, vector<string> &transactions) {
    double amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;

    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Withdrawal successful. New balance: $" << balance << endl;
    } else {
        cout << "Invalid amount or insufficient funds." << endl;
    }
    transactions.push_back("Withdrew $" +to_string(amount));
}


void showHistory(vector<string> &transactions){

    if(transactions.empty()){
        cout << "No transactions yet" <<endl;
    }else{
        for(const string entry :transactions){
            cout <<"- " << entry << endl;
        }
    }
}