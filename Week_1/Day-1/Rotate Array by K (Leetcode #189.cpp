#include <bits/stdc++.h>
using namespace std;

//___________________Rotate Array by K (Leetcode #189)_____________________//

// Function to reverse elements between indices l and r in the vector
void rev_approach(vector<int>& nums, int l, int r) {
    while (l < r) {
        swap(nums[l], nums[r]);
        l++;
        r--;
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    // Ensure k is within bounds
    k %= nums.size();

    // ---------- Approach 1: Reverse Method (O(n), O(1) space) ----------
    // Step 1: Reverse the whole array
    // Step 2: Reverse the first k elements
    // Step 3: Reverse the remaining n-k elements
    rev_approach(nums, 0, nums.size() - 1);
    rev_approach(nums, 0, k - 1);
    rev_approach(nums, k, nums.size() - 1);

    /*
    // ---------- Approach 2: Insert-Erase Method (Not in-place, O(n) space complexity due to vector operations) ----------
    // Move the last k elements to the front
    nums.insert(nums.begin(), nums.end() - k, nums.end());
    // Erase the duplicated last k elements
    nums.erase(nums.end() - k, nums.end());
    */

    // Output the rotated array
    cout << "Rotated Array: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
