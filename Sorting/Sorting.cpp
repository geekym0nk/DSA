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
        
        void merge (vector<int> & nums, int &lo, int &mid, int &hi)
        {
            int itr1 = 0;
            int itr2 = 0;
            
            vector<int> nums1;
            vector<int> nums2;
            
            for (itr1 = lo; itr1 <= mid; itr1++)
                nums1.push_back(nums[itr1]);
                
            for (itr2 = mid+1; itr2 <= hi; itr2++)
                nums2.push_back(nums[itr2]);
        
            itr1 = 0;
            itr2 = 0;
            int i = 0;
            
            for (i = lo; i <= hi; i++)
            {
                if ((itr1 < nums1.size()) &&
                    (itr2 < nums2.size()))
                {
                    if (nums1[itr1] > nums2[itr2])
                    {
                        nums[i] = nums2[itr2];
                        itr2++;
                    }
                    else
                    {
                        nums[i] = nums1[itr1];
                        itr1++;
                    }
                }
                else
                {
                    if (itr1 < nums1.size())
                    {
                        nums[i] = nums1[itr1];
                        itr1++;
                    }
                    else if (itr2 < nums2.size())
                    {
                        nums[i] = nums2[itr2];
                        itr2++;
                    }
                }
            }
        
            return;
        }
        
        void mergeSort (vector<int> & nums, int lo, int hi)
        {
            if (lo < hi)
            {
                int mid = lo + ((hi-lo)/2);
                
                mergeSort(nums, lo, mid);
                mergeSort(nums, mid+1, hi);
                merge(nums, lo, mid, hi);
            }
            
            return;
        }
        
        void mergeSort (vector<int> & nums)
        {
            if (nums.size() <= 1)
                return;
            
            mergeSort(nums, 0, nums.size()-1);

            return;
        }
};
