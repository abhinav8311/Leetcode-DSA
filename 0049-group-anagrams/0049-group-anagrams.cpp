class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> result;

        for(auto st: strs){
            string temp=st;
            sort(temp.begin() , temp.end());
            map[temp].push_back(st);
        }

        for(auto it: map){
            result.push_back(it.second);
        }

        return result;
    }
};