#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct User{
    string username;
    string password;
    double balance;
    vector<string> transactions;
};

// Function declarations
void showMenu();
void checkBalance(User * user);
void deposit(User * user);
void withdraw(User * user);
void showHistory(User * user);
int getValidOption();
double getValidAmount();
User *login(vector<User> &users); //return correct username point

int main() {

    vector<User> users{
        {"alice","1111",1000.0,{}},
        {"bob","2222",800.0,{}},
        {"charlie","3333",1200.0,{}}
    };


    User* currentUser = login(users);
    if(currentUser == nullptr){

        cout <<"Login failed. exiting program." << endl;
        return 0;
    }


        int option;
    do {
        showMenu();
        //cin >> option;
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

void checkBalance(User * user) {
    cout << "Your current balance is: $" << user->balance << endl;
}

void deposit(User * user) {
    //  double amount;
    //cout << "Enter amount to deposit: ";//
    //cin >> amount;
    double amount = getValidAmount();
    if (amount > 0) {
        user->balance += amount;
        cout << "Deposit successful. New balance: $" << user->balance << endl;
    } else {
        cout << "Invalid amount." << endl;
    }
    user->transactions.push_back("Deposited $" +to_string(amount));
}

void withdraw(User * user) {
    //double amount;
    //cout << "Enter amount to withdraw: ";
    //cin >> amount;

    double amount = getValidAmount();

    if (amount > 0 && amount <= user->balance) {
        user->balance -= amount;
        cout << "Withdrawal successful. New balance: $" << user->balance << endl;
    } else {
        cout << "Invalid amount or insufficient funds." << endl;
    }
    user->transactions.push_back("Withdrew $" +to_string(amount));
}


void showHistory(User * user){

    if(user->transactions.empty()){
        cout << "No transactions yet" <<endl;
    }else{
        for(const string &entry :user->transactions){
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

User *login(vector<User> &users){   //return login username information

    string typeName;
    string typePassword;
    int logTime =0;


    while(logTime <3){  // login only 3 time allowed 

 
        cout <<"Enter your name" << endl;
        cin >> typeName;
        cout <<"Enter your password" << endl;
        cin >> typePassword;
        bool foundUser = false;

    for (auto &user : users) {
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