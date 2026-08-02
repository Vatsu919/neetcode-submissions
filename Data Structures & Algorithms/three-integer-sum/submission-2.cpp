class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        for(int i=0;i<nums.size()-2;i++) {
            int j=i+1,k=nums.size()-1;
            while(j<k) {
                int s=nums[i]+nums[j]+nums[k];
                if(s==0){
                    st.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(s>0)k--;
                else j++;
            }
        }
        return {st.begin(),st.end()};
    }
};
