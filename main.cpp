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
int getValidOption();
double getValidAmount();

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
        //cin >> option;
        option = getValidOption();

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
                break;
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
    //  double amount;
    //cout << "Enter amount to deposit: ";//
    //cin >> amount;
    double amount = getValidAmount();
    if (amount > 0) {
        balance += amount;
        cout << "Deposit successful. New balance: $" << balance << endl;
    } else {
        cout << "Invalid amount." << endl;
    }
    transactions.push_back("Deposited $" +to_string(amount));
}

void withdraw(double &balance, vector<string> &transactions) {
    //double amount;
    //cout << "Enter amount to withdraw: ";
    //cin >> amount;

    double amount = getValidAmount();

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

int getValidOption(){    //valid option
    int option;
    while(true){
        cout <<"Please select an option (1-5): " << endl;
        if(cin>>option&&option>=1&&option<=5){
            break;
        }else{
            cout <<"Invalid input. Please enter a number between 1 and 5. " << endl;
            cin.clear();//clean error
            cin.ignore(numeric_limits<streamsize>::max(),'\n'); //ignore error enter
        }
    }
    return option;
}
double getValidAmount(){ //valid amount
    double amount;
    while(true){
        cout <<"Please enter amount: " << endl;
        if(cin>>amount&&amount >0){
            break;
        }else{
            cout <<"Invalid amount. Please enter a positive number."  << endl;
            cin.clear(); // clean error
            cin.ignore(numeric_limits<streamsize>::max(),'\n'); //ignore error enter
        }
    }
    return amount;
}