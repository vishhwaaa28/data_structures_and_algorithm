class Solution {
public:
    bool binarySearch(vector<int>& nums, int target, int si, int ei) {
        if (si > ei) return false;

        int mid = si + (ei - si) / 2;

        if (nums[mid] == target) return true;

        if (nums[si] == nums[mid] && nums[mid] == nums[ei]) {
            return binarySearch(nums, target, si + 1, ei - 1);
        }

        if (nums[si] <= nums[mid]) {
            if (nums[si] <= target && target < nums[mid])
                return binarySearch(nums, target, si, mid - 1);
            else
                return binarySearch(nums, target, mid + 1, ei);
        }
        else {
            if (nums[mid] < target && target <= nums[ei])
                return binarySearch(nums, target, mid + 1, ei);
            else
                return binarySearch(nums, target, si, mid - 1);
        }
    }

    bool search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};
