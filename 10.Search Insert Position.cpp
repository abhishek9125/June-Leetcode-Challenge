class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        if(target<nums[0]){
            return 0;
        }
        if(target>nums[n-1]){
            return n;
        }
        while(start<=end){
            int mid = (end + start)/2;
            if(nums[mid]==target){
                return mid;
            }else{
                if(target>nums[mid] && target<nums[mid+1]){
                    return mid + 1; 
                }
                else if(target<nums[mid] && target>nums[mid-1]){
                    return mid;
                }
                else if(target>nums[mid]){
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }
        }
        return 0;
    }
};
