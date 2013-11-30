class Solution {
public:
    int n_th_gray(int n){
        int base=1;
        int ans=0;
        while(n){
            if(n%2){
                ans+=base;
                ans^=(base/2);
            }
            n>>=1;
            base<<=1;
        }
        return ans;
    }
    vector<int> grayCode(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> gray;
        for(int i=0;i<(1<<n);i++)
            gray.push_back(n_th_gray(i));
        return gray;
    }
};
