class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n=S.size();
        vector<vector<int> > result;
        sort(S.begin(),S.end());
        for(int x=0;x<(1<<n);x++){
            vector<int> now;
            int bits=x;
            int i=0;
            while(bits){
                if(bits%2) now.push_back(S[i]);
                i++;
                bits/=2;
            }
            
            result.push_back(now);
        }
        
        return result;
    }
};
