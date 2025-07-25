# 🏧 ATM Project (C++)

A simple console-based ATM simulation written in C++.

---

## ✅ Features (in progress)

- User login with password verification  
- View account balance  
- Deposit funds  
- Withdraw funds  
- Transaction history  
- Multi-user support  
- Save transaction history to file *(implemented)*  
- Add timestamp (date and time) to each transaction record  

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
- Compiled and tested in Terminal using g++

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
- Enabled C++11 support to suppress compiler warnings for range-based loops

### Day 5
- Refactored user login system to support multiple users
- Defined `User` struct to hold username, password, balance, and transaction history
- Implemented `login()` function returning pointer to the logged-in user
- Modified functions to accept `User*` and operate on the logged-in user’s data
- Handled login attempts with a maximum of 3 tries and proper error messages
- Cleaned up `main()` to integrate new login and per-user transactions

### Day 6
- Replaced hardcoded users with file input using `ifstream`
- Parsed each line of `users.txt` to populate `vector<User>`
- Used `substr()` and `find()` to split CSV-style data `(username,password,balance)`
- Used `stod()` to convert balance from string to double
- At program end, wrote updated user data back to `users.txt` using `ofstream`
- Ensured balance changes (deposit/withdraw) persist across sessions

### Day 7
- Implemented per-user transaction history saved in separate text files
- Loaded transaction history from `<username>_transaction.txt` at login
- Saved transaction history to file on program exit
- Improved data persistence and user experience

### Day 8
- Added current date and time to each transaction record (timestamp)
- Modified transaction log format to include timestamp, e.g.  
  `Deposited $500.00 2025-07-21 15:45:12`
- Used `getCurrentDateTime()` function with `std::put_time` for formatted datetime
- Ensured consistent 2-decimal formatting for amounts using `setprecision(2)`
- Improved clarity and auditability of transaction logs

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


💬 Example Interaction

Enter your name: alice  
Enter your password: 1111

=== ATM Menu ===  
1. Check balance  
2. Deposit  
3. Withdraw  
4. Exit  
5. View transaction history  
Please select an option: 1  
Your current balance is: $1000.00


📂 Project Structure

ATM_Project/
├── main.cpp                 # Main program source code
├── README.md                # Project documentation
├── users.txt                # User data file (username,password,balance)
├── alice_transaction.txt    # Transaction history for user alice
├── bob_transaction.txt      # Transaction history for user bob
└── charlie_transaction.txt  # Transaction history for user charlie


📄 Sample users.txt Content

alice,1111,1000  
bob,2222,800  
charlie,3333,1