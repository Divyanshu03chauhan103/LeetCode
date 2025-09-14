class Solution {
public:
    bool binary_search(int target,vector<int>nums){

        int low=0;
        int high=nums.size();

        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]==target) return true;
            else if(nums[mid]>target){
                high=mid-1;
            }else low=mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int low=0;
        int high=matrix.size()-1;
        int col=matrix[0].size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(matrix[mid][0]<=target && matrix[mid][col]>=target){
                return binary_search(target,matrix[mid]);
            }else if(matrix[mid][0]>target && matrix[mid][col]>target){
                high=mid-1;
            }else if(matrix[mid][0]<target && matrix[mid][col]<target){
                low=mid+1;
            }
        }
        return false;
    }
};