#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//_________________________SUBARRAY SUM(LEETCODE#560)____________________________//
class Solution {
public:
    // Function to count the number of subarrays whose sum equals k
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_sum_map; 
        prefix_sum_map[0] = 1;  // Base case: prefix sum 0 appears once

        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;  // Update the prefix sum

            // Check if (sum - k) exists in the map
            if (prefix_sum_map.find(sum - k) != prefix_sum_map.end()) {
                count += prefix_sum_map[sum - k]; // Add frequency of (sum - k)
            }

            // Store/update the prefix sum in map
            prefix_sum_map[sum]++;
        }

        return count;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, -1, 1}; 
    int k = 3;

    Solution sol;
    int result = sol.subarraySum(nums, k);

    cout << "Number of subarrays with sum " << k << " = " << result << endl;

    return 0;
}
