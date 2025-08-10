class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n+1,false);

        dp[0] = true;

        for(int i = 1;i<=n;i++){
            for(auto word : wordDict){
                int w = word.length();
                if(i >= w && dp[i-w] && s.substr(i-w,w)==word){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};