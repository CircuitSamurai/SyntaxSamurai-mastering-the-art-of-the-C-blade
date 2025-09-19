#include <iostream>

using namespace std;

/* 1. Write a program that asks the user to enter the number of quarters, dimes, nickels, and pennies they have. 
The program should display a clear message before each input so the user knows what to enter. 
Assume the user will always provide a positive integer for each input. 
After collecting the values, calculate the total value of the coins and display the result in U.S. dollar format.

For example, if the user enters 5 quarters, 6 dimes, 3 nickels, and 7 pennies, the program should output $2.07.
*/



int main(){

    int q;
    int d;
    int n;
    int p;
    float total;

    cout << "Enter the number of quarters: ";
    cin >> q;

    cout << "Enter the number of dimes: ";
    cin >> d;

    cout << "Enter the number of nickels: ";
    cin >> n;

    cout << "Enter the number of pennies: ";
    cin >> p;

    total = (q * 0.25) + (d * 0.10) + (n * 0.05) + (p * 0.01);

    cout << "You entered: " << q << " quarters, " << d << " dimes, " << n << " nickels, and " << p << " pennies." << endl << "The total value of your coins is: $" << total << endl;
    
}