#include<bits/stdc++.h>
class Solution {
     bool isStrictlyIncreasing(const std::vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                return false;
            }
        }
        return true;
    }
public:
    int incremovableSubarrayCount(vector<int>& nums) {
      int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                vector<int> copy;
                copy.reserve(n - (j - i + 1));
                
                for (int k = 0; k < n; k++) {
                    if (k < i || k > j) {
                        copy.push_back(nums[k]);
                    }
                }
                
                if (isStrictlyIncreasing(copy)) {
                    count++;
                }
            }
        }
        return count;
    }  
};
