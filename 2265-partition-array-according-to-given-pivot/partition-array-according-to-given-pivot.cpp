class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>result(n,0);
        int left=0;
        int right = n-1;

        for(int i=0 , j=n-1;i<n;i++,j--){

            if(nums[i]<pivot){
                result[left]=nums[i];
                left++;
            }

            if(nums[j]>pivot){
                result[right]=nums[j];
                right--;
            }
        }

        while(left<=right){
            result[left]=pivot;
            left++;
        }
        return result;
    }
};


//Approach 1:
/*
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>result;
        int count=0;
        for(int i:nums){
            if(i<pivot){
                result.push_back(i);
            }
            else if( i== pivot)
                count++;
        }

        while(count--)
            result.push_back(pivot);
        
        for(int i: nums){
            if(i>pivot)
                result.push_back(i);
        }
        
        return result;
    }
};
*/