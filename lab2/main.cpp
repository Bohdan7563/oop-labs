#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <exception>
#include "Account.h"
#include "Client.h"
#include "PremiumClient.h"
#include "Transaction.h"

using namespace std;

void saveAccounts(const vector<shared_ptr<Account>>& accounts) {
    ofstream file("accounts.txt");
    if (!file) return;
    for (const auto& acc : accounts) {
        file << acc->getName() << " " << acc->getBalance() << " ";
        auto owner = acc->getOwner();

        if (auto prem = dynamic_pointer_cast<PremiumClient>(owner)) {
            file << "1 " << prem->getName() << " " << prem->getAge() << " " << prem->getBonus() << "\n";
        } else if (auto client = dynamic_pointer_cast<Client>(owner)) {
            file << "0 " << client->getName() << " " << client->getAge() << "\n";
        }
    }
}

void loadAccounts(vector<shared_ptr<Account>>& accounts) {
    ifstream file("accounts.txt");
    if (!file) return;

    string accName, ownerName;
    double balance = 0.0, bonus = 0.0;
    int isPremium = 0, ownerAge = 0;

    while (file >> accName >> balance >> isPremium >> ownerName >> ownerAge) {
        shared_ptr<Person> owner;
        if (isPremium == 1) {
            file >> bonus;
            owner = make_shared<PremiumClient>(ownerName, ownerAge, bonus);
        } else {
            owner = make_shared<Client>(ownerName, ownerAge);
        }
        accounts.push_back(make_shared<Account>(accName, balance, owner));
    }
}

void logTransaction(const string& accName, const string& type, double amount) {
    Transaction t(accName, amount, type);
    ofstream file("history.txt", ios::app);
    if (file.is_open()) {
        file << t.getAccName() << " " << t.getType() << " " << t.getAmount() << "\n";
    }
}

void showHistory() {
    ifstream file("history.txt");
    if (!file) {
        cout << "History is empty.\n";
        return;
    }
    string accName, type;
    double amount = 0.0;
    cout << "\n--- TRANSACTION HISTORY ---\n";
    while (file >> accName >> type >> amount) {
        cout << "Account: " << accName << " | Action: " << type << " | Amount: " << amount << "\n";
    }
}

void adminMenu(vector<shared_ptr<Account>>& accounts) {
    string pass;
    cout << "Enter admin password: ";
    cin >> pass;

    if (pass != "admin") {
        cout << "Wrong password!\n";
        return;
    }

    int choice = -1;
    while (true) {
        cout << "\n=== ADMIN MENU ===\n";
        cout << "1. Add normal account\n";
        cout << "2. Add premium account\n";
        cout << "3. View all accounts\n";
        cout << "4. View transaction history\n";
        cout << "0. Exit to main menu\n";
        cout << "Select: ";
        cin >> choice;

        if (choice == 0) break;
        else if (choice == 1) {
            string accName, cName;
            double bal = 0.0;
            int age = 0;
            cout << "Enter Account Name: "; cin >> accName;
            cout << "Enter Start Balance: "; cin >> bal;
            cout << "Enter Client Name: "; cin >> cName;
            cout << "Enter Client Age: "; cin >> age;

            auto client = make_shared<Client>(cName, age);
            accounts.push_back(make_shared<Account>(accName, bal, client));
            saveAccounts(accounts);
            cout << "Account added successfully!\n";
        }
        else if (choice == 2) {
            string accName, cName;
            double bal = 0.0, bonus = 0.0;
            int age = 0;
            cout << "Enter Account Name: "; cin >> accName;
            cout << "Enter Start Balance: "; cin >> bal;
            cout << "Enter Client Name: "; cin >> cName;
            cout << "Enter Client Age: "; cin >> age;
            cout << "Enter Premium Bonus: "; cin >> bonus;

            auto client = make_shared<PremiumClient>(cName, age, bonus);
            accounts.push_back(make_shared<Account>(accName, bal, client));
            saveAccounts(accounts);
            cout << "Premium Account added successfully!\n";
        }
        else if (choice == 3) {
            if(accounts.empty()) cout << "No accounts in system.\n";
            for (const auto& acc : accounts) {
                acc->show();
                acc->getOwner()->show();
                cout << "-------------------\n";
            }
        }
        else if (choice == 4) {
            showHistory();
        }
    }
}

void userMenu(const vector<shared_ptr<Account>>& accounts) {
    string accName;
    cout << "Enter your account name to login: ";
    cin >> accName;

    shared_ptr<Account> currentAcc = nullptr;
    for (const auto& acc : accounts) {
        if (acc->getName() == accName) {
            currentAcc = acc;
            break;
        }
    }

    if (!currentAcc) {
        cout << "Account not found! Ask admin to create it.\n";
        return;
    }

    int choice = -1;
    while (true) {
        cout << "\n=== USER MENU (" << currentAcc->getName() << ") ===\n";
        cout << "1. View Balance & Info\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "0. Logout\n";
        cout << "Select: ";
        cin >> choice;

        if (choice == 0) break;
        else if (choice == 1) {
            currentAcc->show();
            currentAcc->getOwner()->work();
        }
        else if (choice == 2) {
            double amount = 0.0;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            try {
                currentAcc->deposit(amount);
                logTransaction(currentAcc->getName(), "Deposit", amount);
                saveAccounts(accounts);
                cout << "Success!\n";
            } catch (const exception& e) {
                cout << "Error: " << e.what() << "\n";
            }
        }
        else if (choice == 3) {
            double amount = 0.0;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            try {
                currentAcc->withdraw(amount);
                logTransaction(currentAcc->getName(), "Withdraw", amount);
                saveAccounts(accounts);
                cout << "Success!\n";
            } catch (const exception& e) {
                cout << "Error: " << e.what() << "\n";
            }
        }
    }
}

int main() {
    vector<shared_ptr<Account>> bankAccounts;
    loadAccounts(bankAccounts);

    int role = -1;
    while (true) {
        cout << "\n===== BANK SYSTEM =====\n";
        cout << "1. Login as Admin\n";
        cout << "2. Login as User\n";
        cout << "0. Exit\n";
        cout << "Select role: ";
        cin >> role;

        if (role == 0) break;
        else if (role == 1) adminMenu(bankAccounts);
        else if (role == 2) userMenu(bankAccounts);
        else cout << "Invalid choice.\n";
    }

    cout << "Goodbye!\n";
    return 0;
}