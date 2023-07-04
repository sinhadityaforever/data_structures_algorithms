class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        int curr=0;
        vector<int> colors(n, 0);
        for(auto it: queries){
            int index = it[0];
            int color = it[1];
            
            //before adding color
            int leftSide = index-1<0 ? 0 : colors[index-1];
            int rightSide = index+1>n-1 ? 0 : colors[index+1];
            
            if(colors[index]!=0 && leftSide ==colors[index]) curr--;
            if(colors[index]!=0 && rightSide ==colors[index]) curr--;
            
            colors[index]=color;
            if(colors[index]==leftSide) curr++;
            if(colors[index]==rightSide) curr++;
            ans.push_back(curr);
        }
        return ans;
    }
};