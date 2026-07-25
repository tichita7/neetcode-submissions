class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();

        int s = 0;
        int e = n-1;

        while(s < e){
            int mid = s + (e-s)/2;

            //check in which half we are
            if(nums[mid] > nums[e]){ //in left half, always compare with e bcz in fully sorted, mid will always be greater than s
                s = mid+1;
            } else{
                e = mid; //include that e
            }
        }
        return nums[s];
    }
};
