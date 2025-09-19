#include <iostream>

using namespace std;



/* 2. Write a program that asks the user to inplut a float representing an amount o=f money in dollars and cents (e.g., 11.56).
The program should then calculate and display the number of each type of coin needed to make that amount.
Do so greedy, using the largest denomination of coin possible at each step.

For example, if the user inputs 11.56, the program should output: 
2.54 = 10 qurters, 0 dimes, 0 nickels, and 4 pennies.

*/

int main(){

        float total = 0.00f;
        cout << "Enter an amount in dollars and cents (0.00): ";
        cin >> total;
        int q;
        int d;
        int n;
        int p;
        int cents;
        cout << "$" << total << " = ";

        cents = total * 100; // convert to cents

        q = cents / 25; // number of quarters
        cents = cents % 25; // remaining cents

        d = cents / 10; // number of dimes
        cents = cents % 10; // remaining cents     

        n = cents / 5; // number of nickels 
        cents = cents % 5; // remaining cents

        p = cents; // number of pennies

        cout << q << " quarters, " << d << " dimes, " << n << " nickels, and " << p << " pennies." << endl;

}