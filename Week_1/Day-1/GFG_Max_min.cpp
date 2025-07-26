#include <bits/stdc++.h>
using namespace std;

//_______________________MAX & MIN (4 Ways)___________________________//

// Custom struct to hold both minimum and maximum values
struct Pair {
    int min;
    int max;
};

// Method 1: Simple Linear Scan - O(n) time
Pair max_min(vector<int>& arr, int n) {
    Pair minmax;
    minmax.max = arr[0];
    minmax.min = arr[0];

    for (int i = 0; i < n; i++) {
        if (arr[i] > minmax.max) {
            minmax.max = arr[i];
        }
        if (arr[i] < minmax.min) {
            minmax.min = arr[i];
        }
    }
    return minmax;
}

// Method 2: By Sorting - O(n log n) time
Pair max_min_bysort(vector<int>& arr, int n) {
    Pair minmax;
    sort(arr.begin(), arr.end());
    minmax.min = arr[0];
    minmax.max = arr[n - 1];
    return minmax;
}

// Method 3: Optimized Linear with Less Comparisons (Handles 1, 2 elements efficiently)
Pair max_min_linear(vector<int>& arr, int n) {
    Pair minmax;

    if (n == 1) {
        minmax.min = minmax.max = arr[0];
        return minmax;
    }

    if (n == 2) {
        if (arr[0] < arr[1]) {
            minmax.min = arr[0];
            minmax.max = arr[1];
        } else {
            minmax.min = arr[1];
            minmax.max = arr[0];
        }
        return minmax;
    }

    minmax.min = INT_MAX;
    minmax.max = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > minmax.max) {
            minmax.max = arr[i];
        }
        if (arr[i] < minmax.min) {
            minmax.min = arr[i];
        }
    }

    return minmax;
}

// Method 4: Tournament Method (Divide & Conquer) - O(n) with ~1.5n comparisons
Pair max_min_tournament(vector<int> arr, int l, int r) {
    Pair minmax, mml, mmr;
    int mid;

    // If only one element
    if (l == r) {
        minmax.min = minmax.max = arr[l];
        return minmax;
    }

    // If two elements
    if (l + 1 == r) {
        if (arr[l] < arr[r]) {
            minmax.min = arr[l];
            minmax.max = arr[r];
        } else {
            minmax.min = arr[r];
            minmax.max = arr[l];
        }
        return minmax;
    }

    // More than two elements - divide array
    mid = (l + r) / 2;
    mml = max_min_tournament(arr, l, mid);
    mmr = max_min_tournament(arr, mid + 1, r);

    // Compare results of subarrays
    minmax.min = min(mml.min, mmr.min);
    minmax.max = max(mml.max, mmr.max);

    return minmax;
}

int main() {
    vector<int> nums = {2, 5, 3, 4, 1, 6, 7, 2, 8};
    int n = nums.size();

    // Run all 4 methods
    Pair minmax1 = max_min(nums, n);                      // Method 1
    Pair minmax2 = max_min_bysort(nums, n);               // Method 2
    Pair minmax3 = max_min_linear(nums, n);               // Method 3
    Pair minmax4 = max_min_tournament(nums, 0, n - 1);    // Method 4

    // Output results
    cout << "Method 1 (Linear):       Max = " << minmax1.max << ", Min = " << minmax1.min << endl;
    cout << "Method 2 (Sort):         Max = " << minmax2.max << ", Min = " << minmax2.min << endl;
    cout << "Method 3 (Optimized):    Max = " << minmax3.max << ", Min = " << minmax3.min << endl;
    cout << "Method 4 (Tournament):   Max = " << minmax4.max << ", Min = " << minmax4.min << endl;

    return 0;
}
