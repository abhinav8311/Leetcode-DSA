class Solution {
    vector<vector<string>> result;
public:
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        partition(s,curr,0);
        return result;
    }
    void partition(string s, vector<string> &curr, int i){
        if(i==s.length()){
            result.push_back(curr);
            return;
        }

        for(int j=i; j<s.length();j++){
            if(isPalindrome(s,i,j)){
                curr.push_back(s.substr(i,j-i+1));
                partition(s,curr,j+1);
                curr.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int i , int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};