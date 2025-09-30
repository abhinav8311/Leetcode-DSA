class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>set;
        int n = s.length();
        int res=0;
        int l=0;
        for(int r=0;r<n;r++){
            while(set.find(s[r])!=set.end()){
                set.erase(s[l]);
                l++;
            }
            set.insert(s[r]);
            res = max(res,r-l+1);
        }
        return res;
    }
};