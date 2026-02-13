class Solution {
public:
    void merge(vector<int>& nums, int si, int ei, int mid) {
        vector<int> temp;
        int i = si;
        int j = mid + 1;

        while (i <= mid && j <= ei) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= ei) temp.push_back(nums[j++]);

        for (int idx = si, x = 0; idx <= ei; idx++) {
            nums[idx] = temp[x++];
        }
    }

    void mergeSort(vector<int>& nums, int si, int ei) {
        if (si >= ei) return;

        int mid = (si + ei) / 2;

        mergeSort(nums, si, mid);
        mergeSort(nums, mid + 1, ei);

        merge(nums, si, ei, mid);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
