#include <iostream>
#include <map>
using namespace std;

// ATM system class
class ATM
{
private:
  map<string, double> balances; // User's balance for each user
  map<string, int> pinOptions;  // Multiple users and their PINs

public:
  // Constructor to initialize balances and PINs
  ATM()
  {
    balances["Adarsh"] = 1000.00;
    balances["Ayushi"] = 500.00;
    balances["Aditya"] = 1200.00;
    balances["Pradeep"] = 750.00;
    balances["Ruchika"] = 300.00;

    // Initializing PINs for different users
    pinOptions["Adarsh"] = 1234;
    pinOptions["Ayushi"] = 2345;
    pinOptions["Aditya"] = 3456;
    pinOptions["Pradeep"] = 4567;
    pinOptions["Ruchika"] = 5678;
  }

  // Function to verify PIN based on the user's name
  bool verifyPin(string name, int input_pin)
  {
    if (pinOptions.find(name) != pinOptions.end() && pinOptions[name] == input_pin)
    {
      cout << "Welcome, " << name << "!" << endl;
      return true;
    }
    else
    {
      cout << "Incorrect name or PIN. Please try again." << endl;
      return false;
    }
  }

  // Function to check balance
  void checkBalance(string name)
  {
    cout << "Your current balance is: $" << balances[name] << endl;
  }

  // Function to deposit money
  void deposit(string name, double amount)
  {
    if (amount > 0)
    {
      balances[name] += amount;
      cout << "Successfully deposited $" << amount << endl;
      checkBalance(name);
    }
    else
    {
      cout << "Invalid deposit amount." << endl;
    }
  }

  // Function to withdraw money
  void withdraw(string name, double amount)
  {
    if (amount > 0 && amount <= balances[name])
    {
      balances[name] -= amount;
      cout << "Successfully withdrew $" << amount << endl;
      checkBalance(name);
    }
    else if (amount > balances[name])
    {
      cout << "Insufficient funds." << endl;
    }
    else
    {
      cout << "Invalid withdrawal amount." << endl;
    }
  }
};

// Main menu function
void showMenu()
{
  cout << "\n===== ATM System Menu =====" << endl;
  cout << "1. Check Balance" << endl;
  cout << "2. Deposit Money" << endl;
  cout << "3. Withdraw Money" << endl;
  cout << "4. Exit" << endl;
  cout << "===========================" << endl;
}

int main()
{
  // Initialize ATM system
  ATM atm;

  string name;
  int input_pin;
  int attempts = 0;
  const int max_attempts = 3;

  // PIN authentication
  while (attempts < max_attempts)
  {
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your PIN: ";
    cin >> input_pin;

    if (atm.verifyPin(name, input_pin))
    {
      break; // If PIN is correct, proceed to the ATM menu
    }
    attempts++;
    if (attempts == max_attempts)
    {
      cout << "Too many incorrect attempts. Exiting." << endl;
      return 1; // Exit the program after 3 failed attempts
    }
  }

  // Main ATM operations
  int choice;
  double amount;

  do
  {
    showMenu();
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      atm.checkBalance(name);
      break;
    case 2:
      cout << "Enter amount to deposit: $";
      cin >> amount;
      atm.deposit(name, amount);
      break;
    case 3:
      cout << "Enter amount to withdraw: $";
      cin >> amount;
      atm.withdraw(name, amount);
      break;
    case 4:
      cout << "Thank you for using the ATM. Goodbye!" << endl;
      break;
    default:
      cout << "Invalid choice. Please try again." << endl;
    }
  } while (choice != 4);

  return 0;
}
