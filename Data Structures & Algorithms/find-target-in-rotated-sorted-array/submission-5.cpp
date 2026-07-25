class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int s = 0;
        int e = n-1;

        while(s <= e){
            int mid = s + (e-s)/2;

            if(nums[mid] == target) return mid;
            
            //if in left sorted half
            if(nums[s] <= nums[mid]){ //3, 4, 5, 0, 1, 2 --> 3(nums[s]) <= 5(nums[mid]), so we r in left half
                //now check if target is in this half
                if(target >= nums[s] && target < nums[mid]){
                    e = mid-1; 
                } else{
                    s = mid+1;
                }
            } else{
                //again check
                if(target > nums[mid] && target <= nums[e]){
                    s = mid+1;
                } else{
                    e = mid-1;
                }
            }
        }
        return -1;
    }
};
