class Solution {
public:
    string frequencySort(string s) {
        //freq, index
    vector<pair<int, char>> v(62, {0,0});
        for(auto it: s){
            int index=0;
            if(it >= 97 && it <= 122){
            index = it-'a';
            
            }
            else if(it >= 65 && it <= 90){
               index = it-'A'+26; 
            }
            else{
                index = it-'0'+52;
            }
            int freq = v[index].first;
            v[index]={freq+1, index};
           
        }
        
        cout<<v[51].first<<endl;
        
        sort(v.begin(), v.end());
        string ans;
        for(auto  it: v){
            char ch;
            if(it.second<26){
              ch = 'a'+it.second;
            }
            else if(it.second<52){
                ch = 'A'+it.second-26;
            }
            else{
                ch = '0'+it.second-52;
            }
            if(ch=='Z') cout<<"FOund";
            int freq = it.first;
            while(freq>0){
                ans.push_back(ch);
                freq--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
        
        }
};