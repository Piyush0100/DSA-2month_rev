#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to return indices of two numbers that add up to the target (1-indexed)
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0, r = n - 1;  // Two-pointer approach
        vector<int> result;

        while (l < r) {
            int sum = numbers[l] + numbers[r];

            if (sum < target) {
                l++;  // Move left pointer forward to increase sum
            }
            else if (sum > target) {
                r--;  // Move right pointer backward to decrease sum
            }
            else {
                // Found the pair (convert to 1-indexed)
                result.emplace_back(l + 1);
                result.emplace_back(r + 1);
                break;
            }
        }
        return result;
    }
};

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    Solution sol;
    vector<int> ans = sol.twoSum(numbers, target);

    if (!ans.empty()) {
        cout << "Indices of numbers that add up to " << target << ": ";
        for (int idx : ans) {
            cout << idx << " ";
        }
        cout << endl;
    } else {
        cout << "No valid pair found!" << endl;
    }

    return 0;
}
