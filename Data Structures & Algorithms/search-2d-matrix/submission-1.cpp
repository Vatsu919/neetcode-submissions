class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int l=0,r=n*m-1;

        while(l<=r) {
            int mid=(l+r)/2;
            int mx=mid/m;
            int my=mid%m;
            if(matrix[mx][my]==target)return true;
            else if(matrix[mx][my]>target) {
                r=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        return false;
    }
};
