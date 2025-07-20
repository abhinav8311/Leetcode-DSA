class Solution {
public:
    int findMin(vector<int>& nums) {
        int L=0;
        int R=nums.size()-1;

        while(L<R){
            if(nums[L]<nums[R]){
                return nums[L];
            }

            int mid=(L+R)/2;

            if(nums[L]<=nums[mid]){
                L=mid+1;
            }
            else {
                R=mid;
            }
        }
        return nums[L];
    }
};