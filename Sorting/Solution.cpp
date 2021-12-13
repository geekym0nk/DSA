#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>

/* Sorting Algorithms */

#include "Sorting.cpp"

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
        Sorting s;
        
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
        
        cout << "Select an algorithm to execute : " << endl;
        cout << "0. Selection Sort" << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Merge Sort" << endl;
        
        cin >> algo;
    
        switch (algo) {
            case 0:
            default:
                /* Worst Case - O(N^2); Best Case - O(N^2) */
                s.selectionSort(nums);
                cout << "Selection Sort : " ;
                break;   
            
            case 1:
                /* Worst Case - O(N^2) ; Best Case -  O(N) due to the flag*/
                s.bubbleSort(nums);
                cout << "Bubble Sort : ";
                break;
                
            case 2:
                /* */
                s.mergeSort(nums);
                cout << "Merge Sort : ";
                break;
        }
        
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        
        printArray(nums);
        
        cout << "Elapsed time: " << elapsed_seconds.count() << endl;
        
        return nums;
    }
};
