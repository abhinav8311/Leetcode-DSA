class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());

        int longest = 0;

        for(auto it : set){
            if(set.find(it-1) == set.end()){
                int length=1;
                while(set.find(it+length) != set.end()){
                    length++;
                }
                longest = max (longest,length);
            }
            
        }
        return longest;
    }
};