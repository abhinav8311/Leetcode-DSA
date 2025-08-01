class Solution {
    vector<string> result;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};

public:
    vector<string> letterCombinations(string digits) {
        string curr;
        if(digits.length()==0) return result;

        backtrack(digits, curr, 0);
        return result;
    }
private:
    void backtrack(string &digits , string curr , int i){
        if(i==digits.length()){
            result.push_back(curr);
            return;
        }

        string characters = digitToChar[digits[i] - '0'];
        for(auto c : characters){
            backtrack(digits, curr + c , i+1);
        }

    }
};