#include<iostream>
#include<climits>

using namespace std;

int countMinStepsToOne(int n, int *arr)
{
    if (n <= 1)
        return 0;
    
    if (arr[n-1] == -1)
    { 
        int step1 = countMinStepsToOne(n-1, arr);
        int step2 = INT_MAX;
        int step3 = INT_MAX;

        if (n % 2 == 0)
            step2 = countMinStepsToOne(n/2,arr);
        
        if (n % 3 == 0)
            step3 = countMinStepsToOne(n/3,arr);

        arr[n-1] = 1 + min(step1,min(step2,step3));
    }

    return arr[n-1];
}

int countMinStepsToOne(int n)
{
     int *arr = new int[n];

     for (int i = 0; i < n; i++)
        arr[i] = -1;

     return countMinStepsToOne(n,arr);
}