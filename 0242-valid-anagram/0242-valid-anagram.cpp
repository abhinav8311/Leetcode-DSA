class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        if(s.length()!=t.length()){
            return false;
        }
        
        int n = s.length();

        for(int i=0;i<n;i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto it:mp){
            if(it.second > 0){
                return false;
            }
        }
        return true;
    }
};