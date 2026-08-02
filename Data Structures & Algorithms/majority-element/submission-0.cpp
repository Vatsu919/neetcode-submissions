class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur,s=0;
        for(int i=0;i<nums.size();i++) {
            if(s==0) {
                cur=nums[i];
            }
            s+=(nums[i]==cur?1:-1);
        }
        return cur;
    }
};