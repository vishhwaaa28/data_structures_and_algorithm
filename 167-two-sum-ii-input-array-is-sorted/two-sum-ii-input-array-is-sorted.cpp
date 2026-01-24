class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start=0,end=numbers.size()-1;
        int currSum=0;
        vector<int> ans;

        while(start<end){
            currSum=numbers[start]+numbers[end];
            if(currSum == target){
                ans.push_back(start+1);
                ans.push_back(end+1);
                return ans;
            }else if(currSum < target){
                start++;
            }else{
                end--;
            }
        }
        
        return ans;
    }
};