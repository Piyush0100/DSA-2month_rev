#include <iostream>
#include <vector>
using namespace std;

// Function to move all zeros to the end while maintaining relative order of non-zero elements
void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int lastNonZero = 0; // Position to place the next non-zero element

    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            swap(nums[i], nums[lastNonZero]);
            lastNonZero++;
        }
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};

    cout << "Before moving zeroes: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    moveZeroes(nums);

    cout << "After moving zeroes:  ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
