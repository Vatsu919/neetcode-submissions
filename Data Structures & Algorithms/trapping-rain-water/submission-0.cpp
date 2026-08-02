class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lm(height.size(), -1);
        vector<int> rm(height.size(), -1);
        int cm=height[0];
        for(int i=1;i<height.size();i++) {
            lm[i]=cm;
            cm=max(cm, height[i]);
        }
        cm=height[height.size()-1];
        for(int i=height.size()-2;i>=0;i--) {
            rm[i]=cm;
            cm=max(cm,height[i]);
        }

        int ans=0;

        for(int i=1;i<height.size()-1;i++) {
            if(height[i]<lm[i] && height[i]<rm[i]) {
                ans+=(min(lm[i],rm[i])-height[i]);
            }
        }
        return ans;
    }
};
