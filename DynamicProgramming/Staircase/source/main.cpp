#include <iostream>

long staircases(int);

using namespace std;

int main () 
{
    cout << "A child can run up a staircase with n steps, by hopping either 1,2,3 steps at a time.";
    cout << " Enter n and find out how many ways he can do that - " << endl;
    
    int n;
    cin >> n;
       
    cout << endl << endl;

    long ways = staircases(n);

    cout << "Child can run up the stairs in " << ways << " different ways" << endl;

    return 0;
}