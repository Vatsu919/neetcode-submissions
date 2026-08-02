class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int l=0,r=people.size()-1;
        int ans=0;
        sort(people.begin(), people.end());

        while(l<=r) {
            int s=people[l]+people[r];
            if(s<=limit) {
                ans++;
                l++;
                r--;
            }
            else {
                ans++;
                r--;
            }
        }
        return ans;
    }
};