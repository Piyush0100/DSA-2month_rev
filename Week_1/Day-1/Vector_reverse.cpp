#include <iostream>
#include <vector>
using namespace std;

//__________________Vector REVERSE (4 Ways)__________________________//

// Method 1: Naive Reverse using extra space (O(n) time & O(n) space)
void naive_rev(vector<int>& arr, int n) {
    vector<int> temp(n);
    for (int i = 0; i < n; i++) {
        temp[i] = arr[n - 1 - i];
    }
    arr = temp; // copy reversed array back
}

// Method 2: Two-pointer approach (in-place) (O(n) time & O(1) space)
void twoPointer_rev(vector<int>& arr, int n) {
    int first = 0;
    int last = n - 1;

    while (first <= last) {
        swap(arr[first], arr[last]);
        first++;
        last--;
    }
}

// Method 3: Swap-based loop (similar to two-pointer) (O(n) time & O(1) space)
void swap_element_rev(vector<int>& arr, int n) {
    for (int i = 0; i < n / 2; i++) {
        swap(arr[i], arr[n - 1 - i]);
    }
}

// Method 4: Recursive reverse (O(n) time & O(n) space on call stack)
void recursion_rev(vector<int>& arr, int l, int r) {
    if (l >= r) return;

    swap(arr[l], arr[r]);
    recursion_rev(arr, l + 1, r - 1);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int n = nums.size();

    // --- Method 1: Naive ---
    naive_rev(nums, n);
    cout << "Naive Reverse:        ";
    for (int i = 0; i < n; i++) cout << nums[i] << " ";
    cout << endl;

    // --- Method 2: Two-Pointer ---
    twoPointer_rev(nums, n);
    cout << "Two-Pointer Reverse:  ";
    for (int i = 0; i < n; i++) cout << nums[i] << " ";
    cout << endl;

    // --- Method 3: Swap-Based ---
    swap_element_rev(nums, n);
    cout << "Swap-Based Reverse:   ";
    for (int i = 0; i < n; i++) cout << nums[i] << " ";
    cout << endl;

    // --- Method 4: Recursive ---
    recursion_rev(nums, 0, n - 1);
    cout << "Recursive Reverse:    ";
    for (int i = 0; i < n; i++) cout << nums[i] << " ";
    cout << endl;

    return 0;
}
