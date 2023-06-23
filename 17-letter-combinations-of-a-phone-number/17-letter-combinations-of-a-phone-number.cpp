class Solution {
public:
    
    
    
    
    void solve(int index, string digits, vector<string> &ans, string currAns, int n, unordered_map<char, string> &mp){
        if(index==n){
            if(currAns.size()>0)
            ans.push_back(currAns);
            return;
        }
        
        string curr = mp[digits[index]];
        for(auto it: curr){
            currAns.push_back(it);
            solve(index+1, digits, ans, currAns, n, mp);
            currAns.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
    unordered_map<char, string> mp;
    mp['2']="abc";
    mp['3']="def";
    mp['4']="ghi";
    mp['5']="jkl";
    mp['6']="mno";
    mp['7']="pqrs";
    mp['8']="tuv";
    mp['9']="wxyz";
        vector<string> ans;
        string currAns;
        solve(0, digits, ans, currAns, digits.size(), mp);
        return ans;
    }
};