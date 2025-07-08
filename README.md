# 🏧 ATM Project (C++)

A simple console-based ATM simulation written in C++.

## ✅ Features (in progress)
- [x] User login with password verification
- [x] View account balance
- [x] Deposit funds
- [x] Withdraw funds
- [x] Transaction history
- [ ] Multi-user support

## 📅 Development Log

### Day 1
- Set up project folder and main.cpp
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

🟩 ### Day 3
🟩 - Introduced transaction history using `vector<string>`
🟩 - Logged user actions: check balance, deposit, withdraw
🟩 - Used `push_back()` to append transactions
🟩 - Discussed passing `vector<string>&` to functions
🟩 - Reviewed C++ reference syntax (`&variable`)
🟩 - Tested transaction recording and ensured correct looping in menu

## 🛠️ Technologies Used
- C++
- GCC / G++ for compilation
- Visual Studio Code

## 🔧 How to Run
```bash
g++ main.cpp -o atm
./atm
