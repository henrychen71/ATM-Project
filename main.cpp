#include<iostream>
#include<string>
using namespace std;

int main(){

    string password = "1234";  //Set the default password
    string input;

    cout << "Please enter your password: ";
    cin >> input;

    if(input == password){

        cout << "Login Successful" << endl;
    }else{

        cout << "Incorrect password" << endl;
    }
    return 0;
}