class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();

        vector<int> ways(n+1);

        ways[n]=1;

        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                ways[i] = 0;
            }
            else{
                ways[i] = ways[i+1];
                if(i+1 < n && (s[i]=='1' || s[i]=='2' && s[i+1]<'7')){
                    ways[i] += ways[i+2];
                }
            }
        }
        return ways[0];
    }
};