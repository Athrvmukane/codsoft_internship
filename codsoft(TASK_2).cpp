#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    char continueOperation;

    do {
        cout << "............ Welcome to the Calculator ............" << endl;

        double num1, num2, result;
        char operation;

        cout << "Enter the first number: ";
        cin >> num1;

        cout << "Enter the second number: ";
        cin >> num2;

        cout << "Choose an operation (+, -, *, /): ";
        cin >> operation;

        switch (operation) {
            case '+':
                result = num1 + num2;
                cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
                break;
            case '-':
                result = num1 - num2;
                cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
                break;
            case '*':
                result = num1 * num2;
                cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                    cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
                } else {
                    cout << "Error! Division by zero is not allowed." << endl;
                }
                break;
            default:
                cout << "Invalid operation. Please choose a valid operation." << endl;
        }

        cout << "............ Do you want to continue? (y/n): ";
        cin >> continueOperation;

    } while (continueOperation == 'y' || continueOperation == 'Y');

    cout << "............ Thanks for using the calculator. Goodbye! ............" << endl;

    return 0;
}
