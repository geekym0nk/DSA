#include<iostream>
#include<climits>

using namespace std;

int countMinStepsToOne(int n)
{
    if (n <= 1)
        return 0;
    
    int minSteps = 0;
    int step1, step2, step3;
    step1 = step2 = step3 = INT_MAX;
    
    step1 = countMinStepsToOne(n-1);
    
    if ((n%2) == 0)
        step2 = countMinStepsToOne(n/2);
    
    if ((n%3) == 0)
        step3 = countMinStepsToOne(n/3);
    
    minSteps = min(step1, min(step2, step3));
    
    return (1 + minSteps);
}