class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n =nums.size();
        int currSum = 0;

        int maxi = INT_MIN;

        for(int i=0;i<n;i++){
            currSum += nums[i];

            maxi = max(maxi,currSum);

            if(currSum < 0){
                currSum = 0;
            }
        }
        return maxi;
    }
};