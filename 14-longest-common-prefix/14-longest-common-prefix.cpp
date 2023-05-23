class Solution {
public:
    
    bool isTrue(char a, int index, vector<string>& strs){
        for(int i=1; i<strs.size(); i++){
            if(strs[i][index]!=a){
                return false;
            }
        }
        return true;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans;
        for(int i=0; i<strs[0].length(); i++){
            if(isTrue(strs[0][i], i, strs)){
                ans.push_back(strs[0][i]);
            }
            else{
                break;
            }
        }
        return ans;
        
    }
};