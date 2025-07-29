#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find the maximum sum of a subarray of size k
    int maximumSumSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        int max_sum = 0;

        // Step 1: Calculate the sum of the first 'k' elements
        int window_sum = 0;
        for (int i = 0; i < k; i++) {
            window_sum += arr[i];
        }
        max_sum = window_sum;

        // Step 2: Slide the window across the array
        for (int i = k; i < n; i++) {
            window_sum += arr[i] - arr[i - k];  // Add new element, remove old
            max_sum = max(max_sum, window_sum); // Update max if needed
        }

        return max_sum;
    }
};

int main() {
    vector<int> arr = {100, 200, 300, 400};
    int k = 2;

    Solution sol;
    int result = sol.maximumSumSubarray(arr, k);

    cout << "Maximum sum of a subarray of size " << k << " is: " << result << endl;
    return 0;
}
