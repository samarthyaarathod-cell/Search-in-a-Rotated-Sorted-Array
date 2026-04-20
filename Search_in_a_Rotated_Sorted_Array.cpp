#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;

        // Left half is sorted
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1; // search left
            } else {
                low = mid + 1;  // search right
            }
        }
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;  // search right
            } else {
                high = mid - 1; // search left
            }
        }
    }

    return -1;
}

int main() {
    vector<int> nums1 = {4,5,6,7,0,1,2};
    vector<int> nums2 = {4,5,6,7,0,1,2};
    vector<int> nums3 = {1};

    cout << search(nums1, 0) << endl; // Output: 4
    cout << search(nums2, 3) << endl; // Output: -1
    cout << search(nums3, 0) << endl; // Output: -1

    return 0;
}