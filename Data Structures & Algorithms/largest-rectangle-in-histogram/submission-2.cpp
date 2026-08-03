class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;

        int ans=0;
        int n=heights.size();

        for(int i=0;i<heights.size();i++) {
            if(st.empty()) {
                st.push(i);
            }

            else {
                while(!st.empty() && heights[i]<=heights[st.top()]) {
                    int chi=st.top();
                    st.pop();
                    int li = !st.empty()?st.top():-1;
                    int cans = (i-li-1)*heights[chi];
                    ans=max(ans,cans);
                }
                st.push(i);
            }
        }

        while(!st.empty()) {
            int chi=st.top();
            st.pop();
            int li=!st.empty()?st.top():-1;
            int cans = (n-li-1)*heights[chi];
            ans=max(ans,cans);
        }
        return ans;
    }
};
