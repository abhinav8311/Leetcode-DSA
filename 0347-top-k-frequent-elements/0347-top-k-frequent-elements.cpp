class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> freq;
        vector <int> result;

        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
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