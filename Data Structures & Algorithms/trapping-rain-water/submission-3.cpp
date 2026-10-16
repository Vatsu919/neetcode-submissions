class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> ml(height.size(),-1);
        vector<int> mr(height.size(),-1);
        int cm=height[0];
        for(int i=1;i<height.size();i++) {
            ml[i]=cm;
            cm=max(cm,height[i]);
        }
        cm=height[height.size()-1];
        int ans=0;

        for(int i=height.size()-1;i>=0;i--) {
            mr[i]=cm;
            cm=max(cm,height[i]);
        }

        for(int i=0;i<height.size();i++) {
            if(ml[i]!=-1 && mr[i]!=-1) {
                ans+=max(0, min(ml[i], mr[i])-height[i]);
            }
        }
        return ans;
    }
};
