#include <iostream>
#include <string>
using namespace std;

int main() {

    // Arrays to store expenses
    double amount[100];
    string category[100];
    string description[100];

    int count = 0;
    int choice;

    do {
        cout << "\n===== Expense Tracker =====\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Show Summary\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        // Add Expense
        if (choice == 1) {

            cout << "Amount: ";
            cin >> amount[count];

            cout << "Category: ";
            cin >> category[count];

            cout << "Description: ";
            cin.ignore();
            getline(cin, description[count]);

            count++;

            cout << "Expense added successfully!\n";
        }

        // View Expenses
        else if (choice == 2) {

            if (count == 0) {
                cout << "No expenses available.\n";
            }
            else {
                cout << "\n===== All Expenses =====\n";

                for (int i = 0; i < count; i++) {
                    cout << "\nExpense " << i + 1 << endl;
                    cout << "Amount: " << amount[i] << endl;
                    cout << "Category: " << category[i] << endl;
                    cout << "Description: " << description[i] << endl;
                }
            }
        }

        // Show Summary
        else if (choice == 3) {

            if (count == 0) {
                cout << "No expenses available.\n";
            }
            else {

                double total = 0;

                // Calculate total amount
                for (int i = 0; i < count; i++) {
                    total = total + amount[i];
                }

                cout << "\n===== Summary =====\n";
                cout << "Total Amount Spent: " << total << endl;

                // Food total
                double food = 0;

                // Travel total
                double travel = 0;

                // Shopping total
                double shopping = 0;

                // Other total
                double other = 0;

                for (int i = 0; i < count; i++) {

                    if (category[i] == "Food") {
                        food = food + amount[i];
                    }
                    else if (category[i] == "Travel") {
                        travel = travel + amount[i];
                    }
                    else if (category[i] == "Shopping") {
                        shopping = shopping + amount[i];
                    }
                    else {
                        other = other + amount[i];
                    }
                }

                cout << "\nFood: " << food << endl;
                cout << "Travel: " << travel << endl;
                cout << "Shopping: " << shopping << endl;
                cout << "Other: " << other << endl;

                // Find highest category
                string highestCategory = "Food";
                double highestAmount = food;

                if (travel > highestAmount) {
                    highestAmount = travel;
                    highestCategory = "Travel";
                }

                if (shopping > highestAmount) {
                    highestAmount = shopping;
                    highestCategory = "Shopping";
                }

                if (other > highestAmount) {
                    highestAmount = other;
                    highestCategory = "Other";
                }

                cout << "\nMost Spending Category: "
                     << highestCategory << endl;

                cout << "Amount Spent: "
                     << highestAmount << endl;
            }
        }

        // Exit
        else if (choice == 4) {
            cout << "Exit Successfully.\n";
        }

        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}