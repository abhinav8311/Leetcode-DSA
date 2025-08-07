class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();

        string rev = s;
        reverse(rev.begin(), rev.end());

        vector<int> curr(n+1,0) , prev(n+1,0);

        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--)
            {
                if(s[i]==rev[j]){
                    curr[j] = 1 + prev[j+1];
                }
                else{
                    curr[j] = max(curr[j+1],prev[j]);
                }
            }
            prev = curr;
        }
        return prev[0];
    }
};