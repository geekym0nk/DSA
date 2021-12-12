#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>

/* Sorting Algorithms */

#include "SelectionSort.cpp"


using namespace std;

class Solution {
public:
    void printArray (vector<int>& nums)
    {
        for (int i : nums)
            cout << i << ", ";
        
        cout << endl;
        return;
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int algo = 0;
        
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
        
        cout << "Select an algorithm to execute : " << endl;
        cout << "0. Selection Sort" << endl;
        cout << "1. Bubble Sort" << endl;
        
        cin >> algo;
    
        switch (algo) {
            case 0:
            default:
                /* Worst Case - O(N^2) */
                selectionSort(nums);
                
                printArray(nums);
                cout << "Selection Sort : " ;
                break;   
        }
        
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        
        cout << "Elapsed time: " << elapsed_seconds.count() << endl;
        
        return nums;
    }
};
