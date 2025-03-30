class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string ,vector<string>> map;//map of key->string and value-> vector of strings
        vector<vector<string>> result;//result vector of -> vector of strings

        for(auto s:strs)//iterate through each word
        {
            string temp=s;
            sort(temp.begin(),temp.end());//sort the temporary string
            map[temp].push_back(s);//push the current iterator word in its corresponding key
        }
        for(auto i:map)
        {
            result.push_back(i.second);//push the value component of the map in the result vector
        }

        return result;
    }
};