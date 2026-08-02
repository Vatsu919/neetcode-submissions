class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1;
        int cp=1;

        while(i<nums.size()) {
            if(nums[i]!=nums[i-1]) {
                nums[cp++]=nums[i];
            }
            i++;
        }
        return cp;
    }
};