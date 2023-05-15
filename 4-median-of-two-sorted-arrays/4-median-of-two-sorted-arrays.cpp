class Solution {
public:
   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }
    int m = nums1.size();
    int n = nums2.size();
    int low = 0;
    int high = m;
    while (low <= high) {
        int partitionNums1 = (low + high) / 2;
        int partitionNums2 = (m + n + 1) / 2 - partitionNums1;
        int maxLeftNums1 = (partitionNums1 == 0) ? INT_MIN : nums1[partitionNums1 - 1];
        int minRightNums1 = (partitionNums1 == m) ? INT_MAX : nums1[partitionNums1];
        int maxLeftNums2 = (partitionNums2 == 0) ? INT_MIN : nums2[partitionNums2 - 1];
        int minRightNums2 = (partitionNums2 == n) ? INT_MAX : nums2[partitionNums2];
        if (maxLeftNums1 <= minRightNums2 && maxLeftNums2 <= minRightNums1) {
            if ((m + n) % 2 == 0) {
                return (double)(max(maxLeftNums1, maxLeftNums2) + min(minRightNums1, minRightNums2)) / 2;
            } else {
                return (double)max(maxLeftNums1, maxLeftNums2);
            }
        } else if (maxLeftNums1 > minRightNums2) {
            high = partitionNums1 - 1;
        } else {
            low = partitionNums1 + 1;
        }
    }
    return -1.0;
}


};