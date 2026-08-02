class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1,n2;
        int c1=0,c2=0;

        for(int i=0;i<nums.size();i++) {
            if(c1==0 && nums[i]!=n2) {
                n1=nums[i];
                c1=1;
            } 
            else if(c2==0 && nums[i]!=n1) {
                n2=nums[i];
                c2=1;
            }
            else if(nums[i]==n1) {
                c1++;
            }
            else if(nums[i]==n2) {
                c2++;
            }
            else {
                c1--;
                c2--;
            }
        }

        int ct1=0,ct2=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==n1)ct1++;
            if(nums[i]==n2)ct2++;
        }
        if(ct1>nums.size()/3 && ct2>nums.size()/3)return {n1,n2};
        else if(ct1>nums.size()/3)return {n1};
        return {};
    }
};