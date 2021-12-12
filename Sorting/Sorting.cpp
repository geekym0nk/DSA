#include <vector>

using namespace std;

class Sorting {
    public :
        void selectionSort(vector<int>& nums)
        {  
            for (int i = 0; i < nums.size()-1; i++)
            {
                for (int j = i+1; j < nums.size(); j++)
                {
                    if (nums[i] > nums[j])
                    {
                        nums[i] ^= nums[j];
                        nums[j] ^= nums[i];
                        nums[i] ^= nums[j];
                    }
                }
            }
            
            return;
        }
        
        void bubbleSort (vector<int> & nums)
        {
            bool isSorted = true;
            
            for (int i = nums.size(); i > 0; i--)
            {
                for (int j = 0; j < i-1; j++)
                {
                    if (nums[j] > nums[j+1])
                    {
                        nums[j+1] ^= nums[j];
                        nums[j] ^= nums[j+1];
                        nums[j+1] ^= nums[j];
                        
                        isSorted = false;
                    }
                }
                
                if (isSorted)
                    break;
                    
                // Lets assume now it must have been sorted & wait to be proven wrong
                isSorted = true;
            }
            
            return;
        }
};
