class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans=0;
        int sum=0;
        int n = cardPoints.size();
        for(int i=0; i<k; i++){
            sum+=cardPoints[i];
        }
        if(k==n) return sum;
        ans = sum;
        for(int i=0; i<k; i++){
            sum-=cardPoints[k-i-1];
            sum+=cardPoints[n-1-i];
            ans=max(sum, ans);
        }
        return ans;
    }
};