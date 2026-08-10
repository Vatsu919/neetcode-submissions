class Solution {
public:

    void fun(vector<int> &can, int target,int ci, int csum, vector<int> &temp, vector<vector<int>> &ans) {
        if(csum==target) {
            ans.push_back(temp);
            return ;
        }
        if(csum>target || ci>=can.size())return ;

        
        temp.push_back(can[ci]);
        fun(can,target,ci+1,csum+can[ci],temp,ans);
        temp.pop_back();

        while(ci+1<can.size() && can[ci]==can[ci+1]) {
            ci++;
        }
        
        fun(can,target,ci+1,csum,temp,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        fun(candidates,target,0,0,temp,ans);
        return ans;
    }
};
