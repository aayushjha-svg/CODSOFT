#include <iostream>
#include <cmath>

using namespace std;

// Function Prototypes
void displayMenu();
void add();
void subtract();
void multiply();
void divideNumbers();
void modulusOperation();
void powerFunction();
void squareRootFunction();

int main()
{
    int choice;

    do
    {
        displayMenu();

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            add();
            break;

        case 2:
            subtract();
            break;

        case 3:
            multiply();
            break;

        case 4:
            divideNumbers();
            break;

        case 5:
            modulusOperation();
            break;

        case 6:
            powerFunction();
            break;

        case 7:
            squareRootFunction();
            break;

        case 8:
            cout << "\nThank You for using Smart Calculator!\n";
            break;

        default:
            cout << "\nInvalid Choice! Please try again.\n";
        }

    } while (choice != 8);

    return 0;
}

// ================= MENU =================

void displayMenu()
{
    cout << "\n====================================";
    cout << "\n        SMART CALCULATOR";
    cout << "\n====================================";
    cout << "\n1. Addition";
    cout << "\n2. Subtraction";
    cout << "\n3. Multiplication";
    cout << "\n4. Division";
    cout << "\n5. Modulus";
    cout << "\n6. Power";
    cout << "\n7. Square Root";
    cout << "\n8. Exit";
    cout << "\n====================================\n";
}

// ================= ADDITION =================

void add()
{
    double a, b;

    cout << "Enter First Number: ";
    cin >> a;

    cout << "Enter Second Number: ";
    cin >> b;

    cout << "Result = " << a + b << endl;
}

// ================= SUBTRACTION =================

void subtract()
{
    double a, b;

    cout << "Enter First Number: ";
    cin >> a;

    cout << "Enter Second Number: ";
    cin >> b;

    cout << "Result = " << a - b << endl;
}

// ================= MULTIPLICATION =================

void multiply()
{
    double a, b;

    cout << "Enter First Number: ";
    cin >> a;

    cout << "Enter Second Number: ";
    cin >> b;

    cout << "Result = " << a * b << endl;
}

// ================= DIVISION =================

void divideNumbers()
{
    double a, b;

    cout << "Enter Dividend: ";
    cin >> a;

    cout << "Enter Divisor: ";
    cin >> b;

    if (b == 0)
    {
        cout << "Error! Division by zero is not allowed.\n";
        return;
    }

    cout << "Result = " << a / b << endl;
}

// ================= MODULUS =================

void modulusOperation()
{
    int a, b;

    cout << "Enter First Number: ";
    cin >> a;

    cout << "Enter Second Number: ";
    cin >> b;

    if (b == 0)
    {
        cout << "Error! Division by zero is not allowed.\n";
        return;
    }

    cout << "Result = " << a % b << endl;
}

// ================= POWER =================

void powerFunction()
{
    double base, exponent;

    cout << "Enter Base: ";
    cin >> base;

    cout << "Enter Exponent: ";
    cin >> exponent;

    cout << "Result = " << pow(base, exponent) << endl;
}

// ================= SQUARE ROOT =================

void squareRootFunction()
{
    double num;

    cout << "Enter Number: ";
    cin >> num;

    if (num < 0)
    {
        cout << "Error! Square root of a negative number is not possible.\n";
        return;
    }

    cout << "Result = " << sqrt(num) << endl;
}