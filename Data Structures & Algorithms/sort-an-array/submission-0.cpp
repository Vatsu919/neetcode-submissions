class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        divide(nums,0,nums.size()-1);
        return nums;
    }
    void divide(vector<int>& nums, int l, int r) {
        if(l<r) {
            int m = (l+r)/2;
            divide(nums,l,m);
            divide(nums,m+1,r);
            merge(nums,l,m,r);
        }
    }
    void merge(vector<int> &nums, int l,int m, int r) {
        int i=l,j=m+1;
        vector<int> v1;
        vector<int> v2;
        while(i<=m) {
            v1.push_back(nums[i]);
            i++;
        }
        while(j<=r) {
            v2.push_back(nums[j]);
            j++;
        }
        int k;
        i=0,j=0,k=l;
        while(i<v1.size() && j<v2.size()) {
            if(v1[i]<=v2[j]) {
                nums[k]=v1[i];
                i++,k++;
            }
            else {
                nums[k]=v2[j];
                j++,k++;
            }
        }
        while(i<v1.size()) {
            nums[k]=v1[i];
            i++,k++;
        }
        while(j<v2.size()) {
            nums[k]=v2[j];
            j++,k++;
        }
    }
};