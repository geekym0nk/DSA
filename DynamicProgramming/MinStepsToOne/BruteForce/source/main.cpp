#include <iostream>

int countMinStepsToOne(int);

using namespace std;

int main () 
{
    cout << "We will calculate minimum steps required to get to 1 from the entered number" << endl;
    cout << "Allowed Calculations - " << endl;
    cout << "1 - Subtraction by 1" << endl;
    cout << "2 - Division by 2" << endl;
    cout << "3 - Division by 3" << endl;
    cout << "Enter the input number - ";
    
    int n;
    cin >> n;
    
    cout << endl << endl;

    int steps = countMinStepsToOne(n);

    cout << "Minimum Steps to 1 for " << n << " is : " << steps << endl;

    return 0;
}