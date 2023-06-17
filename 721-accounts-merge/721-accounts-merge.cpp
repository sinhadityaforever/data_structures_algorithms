
class DisjointSet{
  public:
    vector<int> parent, rank;
    
    DisjointSet(int n){
        rank.resize(n, 0);
        parent.resize(n);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }
    
    
    int findUParent(int node){
        if(parent[node]==node) return node;
        return parent[node] = findUParent(parent[node]);
    }
    
    void unionByRank(int u, int v){
        int pu = findUParent(u);
        int pv = findUParent(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]) parent[pu]=pv;
        else if(rank[pu]>rank[pv]) parent[pv]=pu;
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
    
};

// pair<string, string> sFinder(unordered_map<string, pair<string, int>> mp, int node){
//     for(auto it: mp){
//         if(it.second.second == node){
//             return {it.second.first, it.first};
//         }
//     }
//     return {"", ""};
// }

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        //mail, node
        int n = accounts.size();
       unordered_map<string, int> mp;
        DisjointSet ds(n);
        sort(accounts.begin(), accounts.end());
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                if(mp.find(accounts[i][j])==mp.end()){
                    mp[accounts[i][j]]=i;
                    
                }
                else{
                    ds.unionByRank(mp[accounts[i][j]], i);
                }
            }
        }
        
        vector<string> mergedMail[n];
        
        for(auto it: mp){
            string mail = it.first;
            int node = it.second;
            int parent = ds.findUParent(node);
            mergedMail[parent].push_back(mail);
        }
        
        vector<vector<string>> ans;
        for(int i=0; i<accounts.size(); i++){
            if(mergedMail[i].size()!=0){
                sort(mergedMail[i].begin(), mergedMail[i].end());
                vector<string> tmp;
                tmp.push_back(accounts[i][0]);
                for(auto it: mergedMail[i]){
                    tmp.push_back(it);
                }
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};