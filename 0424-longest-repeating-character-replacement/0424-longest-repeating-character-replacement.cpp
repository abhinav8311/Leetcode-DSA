class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int maxf=1;
        int res=0;
        unordered_map<char,int>map;

        for(int r=0;r<s.length();r++){
            map[s[r]]++;
            maxf = max(maxf , map[s[r]]);

            while((r-l+1) - maxf > k){
                map[s[l]]--;
                l++;
            }
            res= max(res,r-l+1);
            
        }
        return res;
    }
};