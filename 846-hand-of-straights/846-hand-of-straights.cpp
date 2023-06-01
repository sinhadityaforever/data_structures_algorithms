class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
      map<int, int> count;
 
    for (int h : hand) {
        ++count[h];
    }
 
    // Traverse the map
    for (auto c : count) {
        int cur = c.first;
        int n = c.second;
 
        // Check if all its occurrences can
        // be grouped into K subsets
        if (n > 0) {
 
            // Traverse next K elements
            for (int i = 1; i < groupSize; ++i) {
 
                // If the element is not
                // present in the array
                if (!count.count(cur + i)) {
                    return false;
                }
 
                count[cur + i] -= n;
 
                // If it cannot be split into
                // required number of subsets
                if (count[cur + i] < 0)
                    return false;
            }
        }
    }
 
    return true;
    }
};