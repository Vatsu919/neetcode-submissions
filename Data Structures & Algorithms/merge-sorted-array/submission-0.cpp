class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int r=m+n-1;

        while(m>0 && n>0) {
            if(nums1[m-1]>nums2[n-1]) {
                nums1[r]=nums1[m-1];
                nums1[m-1]=0;
                r--;
                m--;
            }
            else {
                nums1[r]=nums2[n-1];
                r--;
                n--;
            }
        }
        while(n>0) {
            nums1[r]=nums2[n-1];
            r--;
            n--;
        }
    }
};