class Solution {
public:
    
    
    
    
    string minWindow(string s, string t) {
        if(t=="") return "";
       unordered_map<char,int> pat;
        unordered_map<char, int> window;
        for(auto it: t) pat[it]++;
        int have =0;
        int need = pat.size();
        int l=0;
        pair<int, int> p ={-1, 1e9};
        for(int r=0; r<s.size(); r++){
            window[s[r]]++;
            if(pat.find(s[r])!=pat.end() && pat[s[r]]==window[s[r]]){
                have++;
                while(have==need){
                  
                    if(r-l+1<=p.second-p.first+1){
                        
                        p.first=l;
                        p.second=r;
                    }
                    window[s[l]]--;
                    if(pat.find(s[l])!=pat.end() && window[s[l]]<pat[s[l]]){
                        have--;
                    }
                    l++;
                }
            }
        }
        if(p.second==1e9) return "";
        string ans;
        for(int i=p.first; i<=p.second; i++)ans+=s[i];
        return ans;
        
        
    }
};