class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> s;

        for(int i=0;i<nums.size();i++) {
            s.insert(nums[i]);
        }
        int ans=0;
        for(auto it:s) {
            if(s.find(it-1)!=s.end())continue;
            int cs=1;
            while(s.find(it+1)!=s.end()) {
                it++;
                cs++;
            }
            ans=max(ans,cs);
        }

        return ans;

    }
};
