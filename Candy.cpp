vector<int> rate;
bool cmp(int i,int j){
        return rate[i]<rate[j];
}

class Solution {
public:
    
    
    int candy(vector<int> &ratings) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        rate=ratings;
        vector<int> idx(ratings.size());
        for(int i=0;i<ratings.size();i++) idx[i]=i;
        sort(idx.begin(),idx.end(),cmp);
        int sum=0;
        int n=ratings.size();
        vector<int> candy(ratings.size(),0);
        for(int i=0;i<ratings.size();i++){
            int p=idx[i];
            if(p>0&&ratings[p]>ratings[p-1]) candy[p]=max(candy[p],candy[p-1]+1);
            if(p<n-1&&ratings[p]>ratings[p+1]) candy[p]=max(candy[p],candy[p+1]+1);
            if(!candy[p]) candy[p]=1;
        }
        for(int i=0;i<candy.size();i++) sum+=candy[i];
        return sum;
    }
};
