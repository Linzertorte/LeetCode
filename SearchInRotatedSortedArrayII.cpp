class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        //if(n==1) return nums[0]==target;
        int l=0,r=n-1;
        while(l+1<n && nums[l]==nums[l+1]) l++;
        while(r-1>=0 && nums[r]==nums[r-1]) r--;
        while(l+1<r){
            int mid = (l+r)/2;
            if(nums[mid]>nums[r]) l=mid;
            else r=mid;
        }
        //[0,r), [r,n)
        return binary_search(nums.begin(),nums.begin()+r,target) ||
        binary_search(nums.begin()+r,nums.end(),target);
    }
};
