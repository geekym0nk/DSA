#include<iostream>
#include<climits>

using namespace std;


long staircases(int n)
{
    if (n <= 0)
        return 0;
    
    long *ways = new long[max(n,4)];

    ways[1] = 1;
    ways[2] = 2;
    ways[3] = 4;
    
    for (int i = 4; i <=n; i++)
        ways[i] = ways[i-1] + ways[i-2] + ways[i-3];
    
	return ways[n];
}