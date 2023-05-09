class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        while(i<m){
            if(!nums2.empty() && nums2[0]<nums1[i]){
                int temp = nums1[i];
                nums1[i]=nums2[0];
                nums2[0]=temp;
                sort(nums2.begin(), nums2.end());
                
            }
            i++;
        }
            int j=0;
            while(j<n){
                nums1[i]=nums2[j];
                i++;
                j++;
            }
        }

    
};