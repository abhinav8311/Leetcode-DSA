class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for(auto num : nums){
            sum += num;
        }

        if(sum%2==1) return false;

        int target = sum/2;
        int n = nums.size();

        vector<vector<bool>> dp(n+1 , vector<bool>(target+1 , false));

        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }

        for(int i = 1;i<=n;i++){
            for(int curSum = 1;curSum <= target; curSum++){
                if(nums[i-1] <= curSum){
                    dp[i][curSum] = dp[i-1][curSum] || dp[i-1][curSum - nums[i-1]];
                }
                else{
                    dp[i][curSum] = dp[i-1][curSum];
                }
            }
        }
        return dp[n][target];
    }
};