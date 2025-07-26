#include <bits/stdc++.h>
using namespace std;

//_________________Maximum Subarray Sum (Leetcode #53)____________________//

int main() {
    // Input array
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int n = nums.size();

    int curr_sum = 0;           // To store the sum of the current subarray
    int max_sum = nums[0];      // Initialize with the first element (handles negative-only arrays)

    // Traverse the array
    for (int i = 0; i < n; i++) {
        curr_sum += nums[i];    // Add current element to current sum

        // If current sum is greater than max sum, update max sum
        max_sum = max(max_sum, curr_sum);

        // If current sum becomes negative, reset it to 0
        if (curr_sum < 0) {
            curr_sum = 0;
        }
    }

    // Output the maximum subarray sum
    cout << "Maximum Subarray Sum: " << max_sum << endl;

    return 0;
}
