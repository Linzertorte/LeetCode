class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> vs;
        if(nums.size()==0) return vs;
        vs.push_back(vector<int>());
        sort(nums.begin(),nums.end());
        for(auto x:nums){
            size_t len = vs.size();
            for(int i=0;i<len;i++){
                vector<int> p = vs[i];
                p.push_back(x), vs.push_back(p);
            }
        }
        return vs;
    }
};
