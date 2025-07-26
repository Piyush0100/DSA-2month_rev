#include <iostream>
#include <vector>
using namespace std;

//_______________________REMOVE DUPLICATES__________________________//

// Function to remove duplicates from a sorted array
int removeDuplicates(vector<int>& nums) {
    int n = nums.size();

    if (n <= 1) return n;

    int j = 0;

    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[j]) {
            j++;
            nums[j] = nums[i];
        }
    }

    return j + 1;
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5};

    int newLength = removeDuplicates(nums);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "New length: " << newLength << endl;

    return 0;
}
