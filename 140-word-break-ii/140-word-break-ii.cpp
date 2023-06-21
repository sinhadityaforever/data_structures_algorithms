class Solution {
public:
    
    
    void solve(string &s, int i, unordered_map<string, int> &mp, string currAns, vector<string> &ans){    
    if(i==s.length()){
        currAns.pop_back();
        ans.push_back(currAns);
        return;
    }

    string word;

    for(int j=i; j<s.length(); j++){
        
        word+=s[j];
        
        if(mp.find(word)!=mp.end()){
            //word exists
            currAns+=(word+" ");
            solve(s, j+1, mp, currAns, ans);
            //pop from currAns (BackTrack)
            for(int index=0; index<=word.size(); index++){
                if(currAns.size()>0)
                currAns.pop_back();
            }
        }
    }


}
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> mp;
    for(auto it: wordDict){
        mp[it]=1;
    }
    
    string currAns;
    vector<string> ans;
    solve(s, 0, mp, currAns, ans);
    return ans;
    }
};