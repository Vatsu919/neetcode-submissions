class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int t=0, l=0, b=n-1, r=n-1;

        while(t<b) {
            for(int i=0;i<(b-t);i++) {
                int first = matrix[t][l+i];
                int second = matrix[t+i][r];
                int third = matrix[b][r-i];
                int forth = matrix[b-i][l];

                matrix[t][l+i]=forth;
                matrix[t+i][r]=first;
                matrix[b][r-i]=second;
                matrix[b-i][l]=third;
            }
            t++;
            b--;
            l++;
            r--;
        }

    }
};
