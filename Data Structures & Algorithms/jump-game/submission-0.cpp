class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mi=0;
        int ci=0;

        while(ci<nums.size()) {
            if(ci>mi)break;
            mi=max(mi, ci+nums[ci]);
            ci++;
        }
        return mi>=nums.size()-1;
    }
};
