# 🏧 ATM Project (C++)

A simple console-based ATM simulation written in C++.

---

## ✅ Features (in progress)

- [x] User login with password verification  
- [x] View account balance  
- [x] Deposit funds  
- [x] Withdraw funds  
- [x] Transaction history  
- [x] Multi-user support  
- [ ] File-based transaction history persistence  

---

## 📅 Development Log

### Day 1
- Set up project folder and `main.cpp`
- Implemented simple login system with password check
- Compiled and tested successfully
- Uploaded initial version to GitHub

### Day 2
- Added main menu with options for:
  - Check balance
  - Deposit
  - Withdraw
- Used reference passing for modifying account balance
- Improved code formatting and fixed typos
- Compiled and tested in Terminal using `g++`

### Day 3
- Introduced transaction history using `vector<string>`
- Logged user actions: check balance, deposit, withdraw
- Used `push_back()` to append transactions
- Passed `vector<string>&` to functions to keep track of history
- Reviewed and practiced C++ reference syntax (`&variable`)
- Tested transaction recording and ensured correct looping behavior

### Day 4
- Added input validation with `getValidOption()` and `getValidAmount()`
- Used `cin.clear()` and `cin.ignore()` to handle invalid user inputs
- Prevented program from crashing on non-numeric input
- Improved user experience with clear error messages
- Enabled C++11 support to suppress compiler warnings

### Day 5
- Refactored user login system to support multiple users
- Defined `User` struct to hold username, password, balance, and transaction history
- Implemented `login()` function returning pointer to the logged-in user
- Modified functions to accept `User*` and operate on the logged-in user’s data
- Handled login attempts with a maximum of 3 tries and proper error messages
- Cleaned up `main()` to integrate new login logic and per-user transactions

### Day 6
- Implemented file-based user data loading and saving via `users.txt`
- Replaced hardcoded users with file input using `ifstream`
- Parsed each line to extract username, password, and balance using `substr()` and `find()`
- Loaded user data into a `vector<User>` at the start of the program
- Used `ofstream` to write back updated user data at program exit
- Ensured data persistence for balances after deposit/withdraw
- Prepared structure for future transaction file saving

---

## 🛠️ Technologies Used

- C++
- GCC / G++ for compilation
- Visual Studio Code

---

## 🔧 How to Run

```bash
# Compile with C++11 support
g++ main.cpp -o atm -std=c++11

# Run the program
./atm

Enter your name
alice
Enter your password
1111

=== ATM Menu ===
1. Check balance
2. Deposit
3. Withdraw
4. Exit
5. View transaction history
Please select an option: 1
Your current balance is: $1000


ATM_Project/
├── main.cpp         # Main program source code
├── users.txt        # File storing user login and balance data
└── README.md        # Project documentation

