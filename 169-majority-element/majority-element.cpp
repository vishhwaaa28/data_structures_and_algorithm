class Solution {
public:
    int countInRange(vector<int>& nums, int num, int si, int ei){
        int count=0;
        for(int i=si; i<=ei; i++){
            if(nums[i]==num){
                count++;
            }
        }
        return count;
    }

    int majorityElementRec(vector<int>& nums, int si, int ei){
        //base case
        if(si==ei){
            return nums[si];
        }

        int mid=si+(ei-si)/2;
        int left= majorityElementRec(nums,si,mid);
        int right = majorityElementRec(nums, mid+1,ei);

        if(left==right){
            return left;
        }

        int leftCount=countInRange(nums, left, si, ei);
        int rightCount=countInRange(nums, right, si, ei);

        return leftCount > rightCount ? left : right;
    }

    int majorityElement(vector<int>& nums) {

        return majorityElementRec(nums,0,nums.size()-1);
        
    }
};