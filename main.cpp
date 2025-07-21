#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream> // for string stream
using namespace std;

// User struct
struct User {
    string username;
    string password;
    double balance;
    vector<string> transactions;
};

// Function declarations
void showMenu();
void checkBalance(User* user);
void deposit(User* user);
void withdraw(User* user);
void showHistory(User* user);
int getValidOption();
double getValidAmount();
User* login(vector<User>& users);
void loadUsersFromFile(vector<User>& users, const string& filename);
void saveUsersToFile(const vector<User>& users, const string& filename);
void loadTransactions(User & user); // load transactions history
void saveTransactions(const User & user); // save transactions history
string getCurrentDateTime();// function to get current date and time as a string

// Main function
int main() {
    vector<User> users;
    const string filename = "users.txt";

    // Load users from file
    loadUsersFromFile(users, filename);

    // User login
    User* currentUser = login(users);
    if (currentUser == nullptr) {
        cout << "Login failed. Exiting program." << endl;
        return 0;
    }

    loadTransactions(*currentUser);// load current user transacton




    // ATM menu loop
    int option;
    do {
        showMenu();
        option = getValidOption();

        switch (option) {
            case 1:
                checkBalance(currentUser);
                currentUser->transactions.push_back("Check Balance");
                break;
            case 2:
                deposit(currentUser);
                break;
            case 3:
                withdraw(currentUser);
                break;
            case 4:
                cout << "Thank you for using the ATM. Goodbye!" << endl;
                break;
            case 5:
                showHistory(currentUser);
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (option != 4);

    // Save users to file
    saveUsersToFile(users, filename);

    saveTransactions(*currentUser); //save current user transaction to text

    return 0;
}

// Show ATM menu
void showMenu() {
    cout << "\n=== ATM Menu ===" << endl;
    cout << "1. Check balance" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Exit" << endl;
    cout << "5. View transaction history" << endl;
    cout << "Please select an option: ";
}

// Check balance
void checkBalance(User* user) {
    cout << fixed << setprecision(2);
    cout << "Your current balance is: $" << user->balance << endl;
}

// Deposit money
void deposit(User* user) {
    double amount = getValidAmount();
    if (amount > 0) {
        user->balance += amount;
        cout << fixed << setprecision(2);
        cout << "Deposit successful. New balance: $" << user->balance << endl;
    } else {
        cout << "Invalid amount." << endl;
    }
    ostringstream oss;
    oss << fixed << setprecision(2) << amount;
    user->transactions.push_back("Deposited $" + oss.str()+ " " +getCurrentDateTime());
}

// Withdraw money
void withdraw(User* user) {
    double amount = getValidAmount();
    if (amount > 0 && amount <= user->balance) {
        user->balance -= amount;
        cout << fixed << setprecision(2);
        cout << "Withdrawal successful. New balance: $" << user->balance << endl;
    } else {
        cout << "Invalid amount or insufficient funds." << endl;
    }
    ostringstream oss;
    oss << fixed << setprecision(2) << amount;
    user->transactions.push_back("Withdrew $" + oss.str()+ " " +getCurrentDateTime());
}

// Show transaction history
void showHistory(User* user) {
    if (user->transactions.empty()) {
        cout << "No transactions yet." << endl;
    } else {
        for (const string& entry : user->transactions) {
            cout << "- " << entry << endl;
        }
    }
}

// Get a valid menu option
int getValidOption() {
    int option;
    while (true) {
        if (cin >> option && option >= 1 && option <= 5) {
            break;
        } else {
            cout << "Invalid input. Enter a number between 1 and 5." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return option;
}

// Get a valid money amount
double getValidAmount() {
    double amount;
    while (true) {
        cout << "Please enter amount: ";
        if (cin >> amount && amount > 0) {
            break;
        } else {
            cout << "Invalid amount. Please enter a positive number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return amount;
}

// Login system
User* login(vector<User>& users) {
    string typeName, typePassword;
    int logTime = 0;

    while (logTime < 3) {
        cout << "Enter your name: ";
        cin >> typeName;
        cout << "Enter your password: ";
        cin >> typePassword;
        bool foundUser = false;

        for (auto& user : users) {
            if (typeName == user.username) {
                foundUser = true;
                if (typePassword == user.password) {
                    return &user;
                } else {
                    cout << "Incorrect password." << endl;
                    break;
                }
            }
        }

        if (!foundUser) {
            cout << "Username not found." << endl;
        }

        logTime++;
    }

    return nullptr;
}

// Load users from file
void loadUsersFromFile(vector<User>& users, const string& filename) {
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);

        string name = line.substr(0, pos1);
        string pass = line.substr(pos1 + 1, pos2 - pos1 - 1);
        double bal = stod(line.substr(pos2 + 1));

        users.push_back({name, pass, bal, {}});
    }

    file.close();
}

// Save users to file
void saveUsersToFile(const vector<User>& users, const string& filename) {
    ofstream outfile(filename);

    for (const User& user : users) {
        outfile << user.username << "," << user.password << "," << user.balance << endl;
    }

    outfile.close();
}

// Load transactions from user-specific file
void loadTransactions(User & user){
    ifstream infile(user.username+"_transaction.txt");

    //if file doesn't exist , just return without anything

    if(!infile.is_open()){
        return;
    }

    string line;
    while (getline(infile,line)){

        user.transactions.push_back(line);

    }
    infile.close();
}

// Save transactions to user-specific file
void saveTransactions(const User & user){
    ofstream outfile(user.username+"_transaction.txt");

    for(const string & entry: user.transactions){

        outfile << entry << endl;
    }
    outfile.close();
}

//function to get current date and time as a string
string getCurrentDateTime(){
    time_t now = time(nullptr);        //Get current time
    tm * localTime = localtime(& now); //Convert to local time(struct tm)

    ostringstream oss;                 //Create output string stream

    oss << put_time(localTime, "%Y-%m-%d %H:%M:%S");//Format date and time

    return oss.str();                  //Return as string

}