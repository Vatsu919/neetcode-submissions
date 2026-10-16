class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;

        for(int num:nums)st.insert(num);

        int ans=0;
        for(int i=0;i<nums.size();i++) {
            if(st.find(nums[i]-1)==st.end()) {
                int cr=nums[i];
                int ct=1;
                while(st.find(cr+1)!=st.end()) {
                    cr++;
                    ct++;
                }
                ans=max(ans,ct);
            }
        }
        return ans;
    }
};
