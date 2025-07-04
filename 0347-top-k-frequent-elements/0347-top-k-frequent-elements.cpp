class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> freq;
        vector <int> result;

        for(auto num:nums){
            freq[num]++;
        }

        int n=nums.size();

        vector <vector<int>> bucket(n+1);

        for(auto it:freq){
            bucket[it.second].push_back(it.first);
        }

        for(int i=n;i>=0;i--){
            for(auto x : bucket[i]){
                result.push_back(x);
                if(result.size()==k){
                   return result;
                }
            }
        }
        return result;
    }
};