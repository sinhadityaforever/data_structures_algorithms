class Solution {
public:
    
    
    int helper(string a, int s, int e){
        
        bool found = false;
        for(int i=s; i<=e; i++){
            if(!found && a[i]=='0'){
                s++;
            }
            else{
                break;
            }
        }
        int ans =0;
        long long pow =1;
        for(int i=e; i>=s; i--){
            ans=ans+(a[i]-'0')*pow;
            pow=pow*10;
        }
        return ans;
    }
    
    int compareVersion(string version1, string version2) {
        int m = version1.length();
        int n = version2.length();
        
        vector<int> rev1;
        vector<int> rev2;
        int i=0;
        int s=0;
        while(i<m){
            if(version1[i]=='.'){
                int tmp = helper(version1, s, i-1);
                rev1.push_back(tmp);
                s=i+1;
            }
            i++;
        }
        int tmp = helper(version1, s, m-1);
        rev1.push_back(tmp);
        
        i=0;
        s=0;
        while(i<n){
            if(version2[i]=='.'){
                int tmp = helper(version2, s, i-1);
                rev2.push_back(tmp);
                s=i+1;
            }
            i++;
        }
        tmp = helper(version2, s, n-1);
        rev2.push_back(tmp);
        
        for(auto i: rev2){
            cout<<i<<endl;
        }
        
        i=0;
        int j=0;
        while(i<rev1.size() && j<rev2.size()){
            if(rev1[i]<rev2[j]){
                return -1;
            }
            else if(rev1[i]>rev2[j]){
                return 1;
            }
            i++;
            j++;
        }
        while(i<rev1.size()){
            if(rev1[i]>0){
                return 1;
            }
            i++;
        }
        
         while(j<rev2.size()){
            if(rev2[j]>0){
                return -1;
            }
            j++;
        }
        return 0;
        
    }
};