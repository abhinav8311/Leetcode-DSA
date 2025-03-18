class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map;
        if(s.size()!=t.size())//if number of char not equal , not anagram
        return false;
        for(int i=0;i<s.size();i++)//traverse through any size coz both must be same
        {
            map[s[i]]++;//increase count for each character of s
            map[t[i]]--;//decrease count for each character of t
        }//map key must be zero if both strings had same characters

        for(auto it:map)//auto iterate through map
        {
            if(it.second)//if there is any value to key, not anagram
            return false;
        }
        
        return true;//true if key is zero
    }
};