class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0,r=n-1;
        while(l+1<r){
            int mid = (l+r)/2;
            if(nums[mid]>nums[r]) l=mid;
            else r=mid;
        }
        //[0,r), [r,n)
        int x =  lower_bound(nums.begin(),nums.begin()+r,target) - nums.begin();
        if(x!=n && nums[x]==target) return x;
        x =  lower_bound(nums.begin()+r,nums.end(),target) - nums.begin();
        if(x!=n && nums[x]==target) return x;
        return -1;
    }
};
